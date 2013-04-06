#ifndef PRQ_H     /* begin include sandwich          */
#define PRQ_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		PRQ.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		0
*	DATE CREATED
*		01 August 2005
*	DATE MODIFIED
*		01 August 2005
*	HISTORY
*		0
*		01 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stdlib.h>
#include <enq.h>
#include <cda.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define PRQ_NULL_ID (NULL)

/****************************************************************************
* Synopsis: 
*		void *PRQ_GET_DATA( PRQ_ITEM_p_t item ); 
* Where: 
*		item -> item from which to retrieve value 
* Returns: 
*		The value of item 
* Exceptions: 
*		None 
* Notes: 
*		None 
***************************************************************************/
#define PRQ_GET_DATA( item ) ((item)->data)

/****************************************************************************
* Synopsis: 
*		CDA_UINT32_t PRQ_GET_PRIORITY( PRQ_ITEM_p_t item ); 
* Where: 
*		item -> item from which to retrieve priority 
* Returns: 
*		The priority of item 
* Exceptions: 
*		None 
* Notes: 
*		None 
***************************************************************************/
#define PRQ_GET_PRIORITY( item ) ((item)->priority)

/****************************************************************************
* STRUCTURES
****************************************************************************/
typedef struct PRQ__control_s *PRQ_ID_t;
typedef struct PRQ_ITEM_s
{	
	ENQ_ITEM_t		enq_item;
    void			*data;
    CDA_UINT32_t	priority;
} PRQ_ITEM_t, *PRQ_ITEM_p_t; 

/****************************************************************************
* TYPEDEFS
****************************************************************************/
typedef void PRQ_DESTROY_PROC_t( void *data ); 
typedef PRQ_DESTROY_PROC_t *PRQ_DESTROY_PROC_p_t; 

/****************************************************************************
* PROTOTYPES
****************************************************************************/
/****************************************************************************
 * Synopsis: 
 *		PRQ_ID_t PRQ_create_queue( 
 *			const char   *name, 
 *			CDA_UINT32_t max_priority 
 *		); 
 * Where: 
 *		name         -> queue name 
 *		max_priority == maximum priority supported by queue 
 * Returns: 
 *		queue id 
 * Exceptions: 
 *		Throws SIGABRT if queue can’t be created 
 * Notes: 
 *		max_priority is stored and checked on subsequent operations, 
 *		but is not otherwise used at this time. 
 ****************************************************************************/
PRQ_ID_t PRQ_create_queue( 
						   const char   *name, 
						   CDA_UINT32_t max_priority 
						   ); 

/****************************************************************************
 * Synopsis: 
 *		PRQ_ITEM_p_t PRQ_create_item( 
 *			void         *value, 
 *			CDA_UINT32_t priority 
 *		); 
 * Where: 
 *		value    -> value to be stored in the item 
 *		priority == the priority of the item 
 * Returns: 
 *		Address of created item 
 * Exceptions: 
 *		Throws SIGABRT if item cannot be created 
 * Notes: 
 *		None 
 ***************************************************************************/
PRQ_ITEM_p_t PRQ_create_item( 
							  void         *value, 
							  CDA_UINT32_t priority 
							  ); 

/****************************************************************************
 * Synopsis: 
 *		CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue ); 
 * Where: 
 *		queue == ID of the queue to test 
 * Returns: 
 *		CDA_TRUE if the queue is empty, CDA_FALSE otherwise 
 * Exceptions: 
 *		None 
 * Notes: 
 *		None 
 ***************************************************************************/
CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue ); 

/****************************************************************************
 * Synopsis: 
 *		PRQ_ITEM_p_t PRQ_add_item(
 *			PRQ_ID_t     queue, 
 *          PRQ_ITEM_p_t item 
 *		); 
 * Where: 
 *		queue == id of priority queue 
 *		item  -> item to add 
 * Returns: 
 *		Address of enqueued item 
 * Exceptions: 
 *		Throws SIGABRT if the item’s priority is higher than the 
 *		maximum priority allowed for the queue. 
 * Notes: 
 *		None 
 ***************************************************************************/
PRQ_ITEM_p_t PRQ_add_item( 
						   PRQ_ID_t     queue, 
                           PRQ_ITEM_p_t item 
						   ); 

/****************************************************************************
 * Synopsis: 
 *		PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue ); 
 * Where: 
 *		queue == id of target priority queue 
 * Returns: 
 *		If priority queue is non-empty: 
 *		The address of the highest priority item in the queue 
 * Otherwise: 
 *		NULL 
 * Exceptions: 
 *		None 
 * Notes: 
 *		None 
 ***************************************************************************/
PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue ); 

/****************************************************************************
 * Synopsis: 
 *		PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item ); 
 * Where: 
 *		item -> item to destroy; 
 * Returns: 
 *		NULL 
 * Exceptions: 
 *		None 
 * Notes: 
 *		None 
 ***************************************************************************/
PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item ); 

/****************************************************************************
 * Synopsis: 
 *		PRQ_ID_t PRQ_empty_queue( 
 *			PRQ_ID_t             queue, 
 *          PRQ_DESTROY_PROC_p_t destroy_proc 
 * 		); 
 * Where: 
 *		queue        == id of queue to empty 
 *		destroy_proc -> optional destroy callback procedure 
 * Returns 
 *		Queue ID 
 * Exceptions: 
 *		None 
 * Notes: 
 *		The caller may pass NULL for the destroy_proc parameter. 
 ***************************************************************************/
PRQ_ID_t PRQ_empty_queue( PRQ_ID_t             queue, 
                          PRQ_DESTROY_PROC_p_t destroy_proc 
						  ); 

/****************************************************************************
 * Synopsis: 
 *		PRQ_ID_t PRQ_destroy_queue( 
 *			PRQ_ID_t             queue, 
 *			PRQ_DESTROY_PROC_p_t destroy_proc 
 * 		); 
 * Where: 
 *		queue        == id of queue to destroy 
 *		destroy_proc -> optional destroy callback procedure 
 * Returns 
 *		PRQ_NULL_ID 
 * Exceptions: 
 *		None 
 * Notes: 
 *		The caller may pass NULL for the destroy_proc parameter. 
 ***************************************************************************/
PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t             queue, 
                            PRQ_DESTROY_PROC_p_t destroy_proc 
							); 

/****************************************************************************
* Synopsis: 
*		PRQ_ITEM_p_t PRQ_deq_item( 
*			PRQ_ITEM_p_t             item 
* 		); 
* Where: 
*		item        == id of item to be dequeued 
* Returns 
*		PRQ_NULL_ID 
* Exceptions: 
*		None 
* Notes: 
*		The caller may pass NULL for the PRQ_deq_item parameter. 
***************************************************************************/
PRQ_ITEM_p_t PRQ_deq_item( 
						PRQ_ITEM_p_t             item 
						); 

/****************************************************************************
* Synopsis: 
*		PRQ_ITEM_p_t PRQ_enq_pri_head( 
*			PRQ_ID_t            queue
*			PRQ_ITEM_p_t		item
* 		); 
* Where: 
*		queue       == id of queue
*		item		-> pointer to item to be placed at head of its
*					   priority class
* Returns 
*		PRQ_NULL_ID 
* Exceptions: 
*		None 
***************************************************************************/
PRQ_ITEM_p_t PRQ_enq_pri_head( 
							 PRQ_ID_t            queue,
							 PRQ_ITEM_p_t		item
							 );

/****************************************************************************
* Synopsis: 
*		PRQ_ITEM_p_t PRQ_deq_pri_head( 
*			PRQ_ID_t            queue
*			PRQ_ITEM_p_t		item
* 		); 
* Where: 
*		queue       == id of queue
*		item		-> pointer to item to be removed from head of its
*					   priority class
* Returns 
*		PRQ_NULL_ID 
* Exceptions: 
*		None 
***************************************************************************/
PRQ_ITEM_p_t PRQ_deq_pri_head( 
							 PRQ_ID_t            queue,
							 CDA_UINT32_t		priority
							 );

/****************************************************************************
* Synopsis: 
*		PRQ_ITEM_p_t PRQ_get_pri_head( 
*			PRQ_ID_t            queue
*			CDA_UINT32_t		priority
* 		); 
* Where: 
*		queue       == id of queue
*		priority    == priority of queue to retrieve head from
* Returns 
*		PRQ_NULL_ID 
* Exceptions: 
*		None 
***************************************************************************/
PRQ_ITEM_p_t PRQ_get_pri_head( 
							   PRQ_ID_t            queue,
							   CDA_UINT32_t		priority
							   );

/****************************************************************************
* Synopsis: 
*		PRQ_ITEM_p_t PRQ_get_next( 
*			PRQ_ITEM_p_t		item
* 		); 
* Where: 
*		item		-> pointer to item
* Returns 
*		PRQ_NULL_ID 
* Exceptions: 
*		None 
***************************************************************************/
PRQ_ITEM_p_t PRQ_get_next( 
							   PRQ_ITEM_p_t     item
							   );

#endif            /* end include sandwich            */
