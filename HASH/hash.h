#ifndef HASH_H     /* begin include sandwich          */
#define HASH_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		HASH.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		2
*	DATE CREATED
*		11 August 2005
*	DATE MODIFIED
*		21 August 2005
*	HISTORY
*		2
*		21 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- added HASH_NULL_ID
*		- added HASH_NUMBER_KEYS_t
*		- added HASH_DESTROY_PROC_t
*		- added HASH_DESTROY_PROC_p_t
*		- changed HASH_STATUS_e
*			+ added HASH_STATUS_ITEM_DELETED
*			+ added HASH_STATUS_ITEM_NOTDELETED
*		- changed API to HASH_create_table
*			+ added HASH_NUMBER_KEYS_t number_keys to dummy arguments
*		- changed API to HASH_create_item
*			+ allows NULL data as dummy argument
*		- changed API to HASH_destroy_item
*			+ changed return type to STATUS_t
*			+ added void *data to dummy arguments
*		- changed API to HASH_destroy_table
*			+ added HASH_DESTROY_PROC_p_t destroy_proc
*	
*		1
*		15 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- added API for all subroutines
*
*		0
*		11 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stdlib.h>
#include <cda.h>
#include <enq.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define HASH_NULL_ID (NULL)

/****************************************************************************
* STRUCTURES
****************************************************************************/

/****************************************************************************
* TYPEDEFS
****************************************************************************/
/****************************************************************************
* Name:
*		HASH_STATUS_t
* Notes: 
*		Type definition used as return value for subroutines
*			- HASH_find_item()
*			- HASH_add_item()
*			- HASH_delete_item()
****************************************************************************/
typedef enum HASH_STATUS_e{
	HASH_STATUS_KEY_FOUND,
	HASH_STATUS_KEY_NOTFOUND,
	HASH_STATUS_ITEM_ADDED,
	HASH_STATUS_ITEM_NOTADDED,
	HASH_STATUS_ITEM_DELETED,
	HASH_STATUS_ITEM_NOTDELETED
} HASH_STATUS_t;

/****************************************************************************
* Name:
*		HASH_ID_t
* Notes: 
*		Type definition to encapsulated hash table structure
****************************************************************************/
typedef struct HASH__control_s *HASH_ID_t;
/****************************************************************************
* Name:
*		HASH_KEY_t
* Notes: 
*		- Convenience type definition of an item's key for a hash table
*		- changing will have non-deterministic effect on module
****************************************************************************/
typedef char *HASH_KEY_t;
/****************************************************************************
* Name:
*		HASH_INDEX_t
* Notes: 
*		Convenience type definition used as return value for hash_proc
****************************************************************************/
typedef CDA_UINT32_t HASH_INDEX_t;
/****************************************************************************
* Name:
*		HASH_NUMBER_KEYS_t
* Notes: 
*		Type definition for defining the minimum number of keys 
*		created by hash table
****************************************************************************/
typedef CDA_UINT32_t HASH_NUMBER_KEYS_t;
/****************************************************************************
* Name:
*		HASH_GENERATE_PROC_t
* Notes:
*		Type definition of hash table generate index proc
* Synopsis: 
*		HASH_INDEX_t hash_proc(const HASH_KEY_t, const HASH_NUMBER_KEYS_t);
* Description:
*		Given HASH_KEY_t generate an index of type HASH_INDEX_t
* Exceptions: 
*		Throws SIGABRT if unable to create index from key 
****************************************************************************/
typedef HASH_INDEX_t HASH_GENERATE_PROC_t(const HASH_KEY_t, const HASH_NUMBER_KEYS_t);
/****************************************************************************
* Name:
*		HASH_GENERATE_PROC_p_t
* Notes: 
*		Type definition of pointer to hash table proc
****************************************************************************/
typedef HASH_GENERATE_PROC_t *HASH_GENERATE_PROC_p_t;
/****************************************************************************
* Name:
*		HASH_DESTROY_PROC_t
* Notes:
*		Type definition of destroy proc
* Synopsis: 
*		void destroy_proc(void *);
* Description:
*		Used by HASH module to free dynamically created data;
* Exceptions: 
*		Throws SIGABRT if unable to free data 
****************************************************************************/
typedef void HASH_DESTROY_PROC_t( void *data ); 
/****************************************************************************
* Name:
*		HASH_DESTROY_PROC_p_t
* Notes: 
*		Type definition of pointer to hash data destroy proc
****************************************************************************/
typedef HASH_DESTROY_PROC_t *HASH_DESTROY_PROC_p_t; 

/****************************************************************************
* PROTOTYPES
****************************************************************************/
/****************************************************************************
* Synopsis: 
*		TABLE_ID_t HASH_create_table(
*			HASH_NUMBER_KEYS_t number_keys,
*			HASH_GENERATE_PROC_p_t hash_proc
* 		); 
* Where: 
*		HASH_NUMBER_KEYS_t	== hint for number of keys to generate, internal
*							   implementation free to use whatever number it
*							   feels is optimal
*		HASH_GENERATE_PROC_p_t => pointer to function that generates hash given
*						          HASH_KEY_t
* Returns 
*		HASH_ID_t 
* Exceptions: 
*		None 
* Notes:
*		- number_keys may be 0.  If 0 then defaults to module default value
*		  if not 0 then implementation determines optimal number of keys given hint
*		- hash_proc may be NULL.  If NULL then private hash_proc will be 
*		  used
***************************************************************************/
HASH_ID_t HASH_create_table(
							HASH_NUMBER_KEYS_t number_keys,
							HASH_GENERATE_PROC_p_t hash_proc
							); 

/****************************************************************************
* Synopsis: 
*		HASH_ID_t HASH_empty_table(
*								   HASH_ID_t hash,
*								   HASH_DESTROY_PROC_p_t destroy_proc							
*								   );
* Where: 
*		hash == hash table object created with HASH_create_table()
*		destroy_proc => pointer to function that frees user's data
* Returns 
*		HASH_ID_t
* Exceptions: 
*		None 
* Notes:
*		- destroy_proc may be NULL.  
***************************************************************************/
HASH_ID_t HASH_empty_table(
						   HASH_ID_t hash,
						   HASH_DESTROY_PROC_p_t destroy_proc							
						   );

/****************************************************************************
* Synopsis: 
*		TABLE_ID_t HASH_destroy_table(
*			TABLE_ID_t hash,
*			HASH_DESTROY_PROC_p_t destroy_proc
*		); 
* Where: 
*		hash == hash table object created with HASH_create_table()
*		HASH_DESTROY_PROC_p_t => pointer to function that frees user's data
* Returns 
*		returns HASH_NULL_ID if successful
* Exceptions: 
*		None 
* Notes:
*		- destroy_proc may be NULL.  
***************************************************************************/
HASH_ID_t HASH_destroy_table(
							 HASH_ID_t hash,
							 HASH_DESTROY_PROC_p_t destroy_proc							
							); 

/****************************************************************************
* Synopsis: 
*		STATUS_t HASH_add_item(
*			TABLE_ID_t hash,
*			HASH_KEY_t key,
*			void *data
*		); 
* Where: 
*		hash == hash table object created with HASH_create_table()
*		key => pass key of type, HASH_KEY_t (pointer to string)
*		data => pointer to data to be stored at key's location
* Returns 
*		HASH_STATUS_t
*			If added successfully					== HASH_STATUS_ITEM_ADDED
*			If not added successfully				== HASH_STATUS_ITEM_NOTADDED
*			If not added because key already exists == HASH_STATUS_KEY_FOUND
* Exceptions: 
*		None 
* Notes:
*		- data may be NULL
***************************************************************************/
HASH_STATUS_t HASH_add_item(
						HASH_ID_t hash,
						const HASH_KEY_t key,
						void *data
							 ); 

/****************************************************************************
* Synopsis: 
*		HASH_STATUS_t HASH_delete_item(
*			TABLE_ID_t table,
*			HASH_KEY_t key,
*			void *data,
*			HASH_DESTROY_PROC_p_t destroy_proc	 
*		); 
* Where: 
*		table == hash table object created with HASH_create_table()
*		key => pointer to key string
*		data => pointer to data if HASH_STATUS_t == HASH_STATUS_ITEM_DELETED
*		destroy_proc => pointer to destroy proc for data
* Returns 
*		HASH_STATUS_t
*			If deleted successfully					== HASH_STATUS_ITEM_DELETED
*			If not deleted							== HASH_STATUS_ITEM_NOTDELETED
* Exceptions: 
*		None 
* Notes:
*		destroy_proc may be NULL
***************************************************************************/
HASH_STATUS_t HASH_delete_item(
						 HASH_ID_t table,
						 const HASH_KEY_t key,
						 void *data,
						 HASH_DESTROY_PROC_p_t destroy_proc	
						 ); 

/****************************************************************************
* Synopsis: 
*		HASH_STATUS_t HASH_find_item(
*			TABLE_ID_t table,
*			HASH_KEY_t key,
*			void **data
*		); 
* Where: 
*		table == hash table object created with HASH_create_table()
*		key => pointer to key string
*		data => pointer to pointer of data associated with key
* Returns 
*		HASH_STATUS_t
*			If found successfully					== HASH_STATUS_KEY_FOUND
*			If not found successfully				== HASH_STATUS_KEY_NOTFOUND
* Exceptions: 
*		None 
***************************************************************************/
HASH_STATUS_t HASH_find_item(
						HASH_ID_t table,
						const HASH_KEY_t key,
						void **data
						 ); 

#endif            /* end include sandwich            */
