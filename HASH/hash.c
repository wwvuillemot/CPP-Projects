/****************************************************************************
*	NAME
*		HASH
*	DESCRIPTION
*		module HASH (HASH) source file.  
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		2
*	DATE CREATED
*		10 August 2005
*	DATE MODIFIED
*		21 August 2005
*	HISTORY
*		2
*		21 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- see HASH.h for details
*
*		1
*		15 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- added subroutines
*
*		0
*		10 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <hashp.h>

/****************************************************************************
* MACROS
****************************************************************************/

/****************************************************************************
* SUBROUTINES
*
*	NOTES
*		see hash.h for subroutine API and notes
****************************************************************************/
/****************************************************************************
* SUBROUTINE	HASH_create_table
****************************************************************************/
HASH_ID_t HASH_create_table(
							HASH_NUMBER_KEYS_t number_keys,
							HASH_GENERATE_PROC_p_t hash_proc
							)
{
	CDA_UINT32_t table_inx			= 0;
	HASH_GENERATE_PROC_p_t my_proc	= HASH__hash_generator;
	HASH_ID_t hash					= NULL;
	
	CDA_ASSERT( number_keys > 0);
	
	hash					= CDA_NEW(HASH__CONTROL_t);
	hash->hash_proc			= NULL == hash_proc ? my_proc : hash_proc;
	hash->number_keys		= HASH__next_prime( number_keys );
	hash->table				= CDA_malloc(
										 sizeof(ENQ_ANCHOR_p_t) * 
										 (hash->number_keys+1)
										 );
	for(table_inx=0; table_inx<=hash->number_keys;table_inx++)
		hash->table[table_inx]	= (ENQ_ANCHOR_p_t) ENQ_create_list(NULL);
	
	return hash;
}

/****************************************************************************
* SUBROUTINE	HASH_empty_table
****************************************************************************/
HASH_ID_t HASH_empty_table(
						   HASH_ID_t hash,
						   HASH_DESTROY_PROC_p_t destroy_proc							
						   )
{
	CDA_UINT32_t table_inx		= hash->number_keys;
	
	CDA_ASSERT( hash );
	
	for(table_inx = 0; table_inx <= hash->number_keys; table_inx++)
	{		
		while ( !ENQ_is_list_empty( (ENQ_ANCHOR_p_t) hash->table[table_inx] ) ) 
		{	
			HASH_ITEM_p_t item = (HASH_ITEM_p_t) ENQ_deq_head(hash->table[table_inx]);
			if(destroy_proc != NULL)
				destroy_proc( item-> data );
			ENQ_destroy_item( (ENQ_ITEM_p_t) item);			
		}
	}	
	
	return hash;	
}

/****************************************************************************
* SUBROUTINE	HASH_destroy_table
****************************************************************************/
HASH_ID_t HASH_destroy_table(
							 HASH_ID_t hash,
							 HASH_DESTROY_PROC_p_t destroy_proc							
							 )
{
	CDA_UINT32_t table_inx		= hash->number_keys;
	
	CDA_ASSERT( hash );

	hash						= HASH_empty_table(
												   hash,
												   destroy_proc
												   );

	for(table_inx=0; table_inx <= hash->number_keys; table_inx++)
		hash->table[table_inx]	= ENQ_destroy_list(
												   (ENQ_ANCHOR_p_t) hash->table[table_inx]
												   );
	
	CDA_free(hash->table);
	CDA_free(hash);
	
	return HASH_NULL_ID;	
}

/****************************************************************************
* SUBROUTINE	HASH_add_item
****************************************************************************/
HASH_STATUS_t HASH_add_item(
							HASH_ID_t hash,
							const HASH_KEY_t key,
							void *data
							)
{
	HASH_STATUS_t status	= HASH_STATUS_ITEM_NOTADDED;
	HASH_ITEM_p_t item		= NULL;
	HASH_INDEX_t index		= 0;
	void *finddata			= NULL;
	
	CDA_ASSERT( hash );
	
	switch(HASH_find_item(hash, key, &finddata)){
	
		case HASH_STATUS_KEY_FOUND:
			
			status					= HASH_STATUS_KEY_FOUND;
			break;
		
		case HASH_STATUS_KEY_NOTFOUND:
			
			index					= hash->hash_proc( key, hash->number_keys);
			item					= (HASH_ITEM_p_t) ENQ_create_item( key , sizeof(HASH__ITEM_t) );
			item->data				= data;
			if( item == (HASH_ITEM_p_t) ENQ_add_tail( 
									(ENQ_ANCHOR_p_t) hash->table[index],
									(ENQ_ITEM_p_t) item 
									)
				)
				status				= HASH_STATUS_ITEM_ADDED;
			break;
		
		case HASH_STATUS_ITEM_ADDED:
		case HASH_STATUS_ITEM_NOTADDED:
		default:
		
			CDA_ASSERT( CDA_TRUE );
			break;
	}
	
	return status;
}

/****************************************************************************
* SUBROUTINE	HASH_delete_item
****************************************************************************/
HASH_STATUS_t HASH_delete_item(
						HASH_ID_t hash,
						const HASH_KEY_t key,
						void *data,
						HASH_DESTROY_PROC_p_t destroy_proc	  
						)
{
	HASH_STATUS_t status	= HASH_STATUS_ITEM_NOTDELETED;
	HASH_ITEM_p_t item		= NULL;

	CDA_ASSERT( hash );
	
	item = HASH__hash_traverse( hash, key );
	if(item != NULL)
	{
		if(destroy_proc == NULL)
		{
			data			= item->data;
		}
		else
		{
			destroy_proc( item-> data );
		}
		ENQ_destroy_item( (ENQ_ITEM_p_t) item);
		status				= HASH_STATUS_ITEM_DELETED;
	}
		
	return status;
}

/****************************************************************************
* SUBROUTINE	HASH_find_item
****************************************************************************/
HASH_STATUS_t HASH_find_item(
							 HASH_ID_t hash,
							 const HASH_KEY_t key,
							 void **data
							 )
{
	HASH_STATUS_t status	= HASH_STATUS_KEY_NOTFOUND;
	HASH_ITEM_p_t item		= NULL;
	
	CDA_ASSERT( hash );
	
	if(!ENQ_is_list_empty( (ENQ_ANCHOR_p_t) hash ) )
	{
		if((item = HASH__hash_traverse(hash, key)) != NULL)
		{
			status				= HASH_STATUS_KEY_FOUND;
			data				= &item->data;
		}
	} 
	
	return status;
}

/****************************************************************************
* SUBROUTINE	HASH__hash_traverse
****************************************************************************/
HASH_ITEM_p_t HASH__hash_traverse(
						  HASH_ID_t hash,
						  const HASH_KEY_t key
						  )
{	
	
	HASH_ITEM_p_t item			= NULL;
	int	data_found				= CDA_FALSE;
	HASH_INDEX_t index			= hash->hash_proc( key, hash->number_keys );
	HASH_ITEM_p_t head			= (HASH_ITEM_p_t) ENQ_GET_HEAD( 
												(ENQ_ANCHOR_p_t) hash->table[index]
												);
	
	CDA_ASSERT( hash );

	item						= head;
	while( (!data_found) && ( head != item ) )
	{
		if(!strcmp(key,ENQ_GET_LIST_NAME((ENQ_ITEM_p_t) item)))
		{
			data_found			= CDA_TRUE;			
		}
		else
		{
			item				= (HASH_ITEM_p_t) ENQ_GET_NEXT( (ENQ_ITEM_p_t) head );			
		}
	}

	return item;
}

/****************************************************************************
* SUBROUTINE	HASH__hash_generator
****************************************************************************/
HASH_INDEX_t HASH__hash_generator(
								  const HASH_KEY_t key,
								  const HASH_NUMBER_KEYS_t number_keys
								  )
{
	CDA_UINT32_t key_inx	= 0;
	HASH_INDEX_t index		= 0;
	
	CDA_ASSERT( number_keys > 1 );
	
	/*
	 * calculate the key by doing simple addition of
	 * ASCII char from key string and then take modulus
	 * of sum against total number of keys in table
	 * 
	 * collisions will occur ... however, we handle through
	 * chaining and comparing actual keys against each other
	 * see HASH__hash_traverse()
	 */
	while(key != '\0')
		index = index + key[key_inx++];	
	index					= index % number_keys;
	
	return index;
}

/****************************************************************************
* SUBROUTINE	HASH__next_prime
****************************************************************************/
HASH_NUMBER_KEYS_t HASH__next_prime(
									const HASH_NUMBER_KEYS_t number_keys
									)
{
	HASH_NUMBER_KEYS_t next_prime = number_keys;

	if(number_keys == 0)
		next_prime = HASH__GENERATOR_PRIME;
	
	/*
	 * Possibility to add prime number finder here whereby given a positive
	 * integer determine the next prime number ... may not be necessary if
	 * collisions are rare.  For time being left as a pass-through
	 * until further need is identified.
	 */
	
	return next_prime;
}
