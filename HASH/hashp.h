#ifndef HASHP_H     /* begin include sandwich          */
#define HASHP_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		HASHP.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		1
*	DATE CREATED
*		11 August 2005
*	DATE MODIFIED
*		21 August 2005
*	HISTORY
*		1
*		21 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- modified HASH__control_s
*			+ changed PRQ_ID_t to ENQ_ANCHOR_p_t *
*		- modified HASH__item_s
*			+ changed PRQ_item_t to ENQ_ITEM_p_t
*		- made HASH_GENERATOR_PRIME private, or HASH__GENERATOR_PRIME
*		- removed HASH__destroy_item()
*		- added HASH__next_prime()
*		- changed API of HASH__hash_generator
*			+ added const HASH_NUMBER_KEYS_t number_keys to dummy arguments
*
*		0
*		11 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <hash.h>

/****************************************************************************
* MACROS
****************************************************************************/
/****************************************************************************
* Name:
*		HASH__GENERATOR_PRIME
* Description:
*		This should be a PRIME NUMBER to help minimize collisions with the
*		hash key generator.  If this is much smaller than the number of
*		items within the table then collisions will increase.  User is 
*		expected to pass a minimum number of keys.  If they pass 0 instead
*		then use this number, HASH__GENERATOR_PRIME.
****************************************************************************/
#define HASH__GENERATOR_PRIME	(101)

/****************************************************************************
* STRUCTURES
****************************************************************************/
typedef struct HASH__control_s
{
	ENQ_ANCHOR_p_t				*table;			// BINARY_ROOT_p_t would be preferable
	HASH_GENERATE_PROC_p_t		hash_proc;
	HASH_NUMBER_KEYS_t			number_keys;
} HASH__CONTROL_t, *PRQ__CONTROL_p_t;

typedef struct HASH__item_s
{
	ENQ_ITEM_p_t				enq_item;		// BINARY_NODE_p_t would be preferable
    void						*data;
} HASH__ITEM_t, *HASH_ITEM_p_t;

/****************************************************************************
* TYPEDEFS
****************************************************************************/

/****************************************************************************
* PROTOTYPES
****************************************************************************/
/****************************************************************************
* Synopsis: 
*		HASH_ITEM_p_t HASH__hash_traverse(
*								   HASH_ID_t hash,
*								   const HASH_KEY_t key
*								   );
* Where: 
*		hash == hash table
*		key == hash key used to generate index value
* Returns 
*		HASH_ITEM_p_t
* Notes
*		returns NULL if no data found
***************************************************************************/
HASH_ITEM_p_t HASH__hash_traverse(
								 HASH_ID_t hash,
								 const HASH_KEY_t key
								 );
/****************************************************************************
* Synopsis: 
*		HASH_INDEX_t HASH__hash_generator(
*								 const HASH_KEY_t key,
								 const HASH_NUMBER_KEYS_t number_keys		  
*								 );
* Where: 
*		key == hash key used to generate index value
*		number_keys == number of keys in hash table
* Returns 
*		HASH_INDEX_t
* Exceptions: 
*		Throws SIGABRT if unable to create index from key 
***************************************************************************/
HASH_INDEX_t HASH__hash_generator(
								  const HASH_KEY_t key,
								  const HASH_NUMBER_KEYS_t number_keys
								  );
/****************************************************************************
* Synopsis: 
*		HASH_NUMBER_KEYS_t HASH__next_prime(
*								 const HASH_NUMBER_KEYS_t number_keys
*								 );
* Where: 
*		number_keys == minimum number of keys
* Returns 
*		HASH_NUMBER_KEYS_t
* Exceptions: 
*		None
***************************************************************************/
HASH_NUMBER_KEYS_t HASH__next_prime(
								  const HASH_NUMBER_KEYS_t number_keys
								  );
#endif            /* end include sandwich            */
