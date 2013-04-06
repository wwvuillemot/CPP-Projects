/****************************************************************************
*	NAME
*		PRQ
*	DESCRIPTION
*		module PRQ (PRIORITY QUEUE) source file.  
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		0
*	DATE CREATED
*		24 July 2005
*	DATE MODIFIED
*		25 July 2005
*	HISTORY
*		0
*		01 August 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <prqp.h>

/****************************************************************************
* MACROS
****************************************************************************/

/****************************************************************************
* SUBROUTINES
*
*	NOTES
*		see prq.h for subroutine API and notes
****************************************************************************/
/****************************************************************************
* SUBROUTINE	PRQ_create_queue
****************************************************************************/
PRQ_ID_t PRQ_create_queue( 
						   const char   *name, 
						   CDA_UINT32_t max_priority 
						   )
{
	CDA_UINT32_t anchor_inx		= 0;
	PRQ_ID_t queue				= NULL;
	
	CDA_ASSERT( max_priority > 0 );
	
	queue						= CDA_NEW(PRQ__CONTROL_t);
	queue->max_priority			= max_priority;
	queue->anchors				= CDA_malloc(
											 sizeof(ENQ_ANCHOR_p_t) * 
											 (max_priority+1)
											 );
	for(anchor_inx=0; anchor_inx<=max_priority;anchor_inx++)
		queue->anchors[anchor_inx]	= (ENQ_ANCHOR_p_t) ENQ_create_list(name);
	
	return queue;
}

/****************************************************************************
* SUBROUTINE	PRQ_create_item 
***************************************************************************/
PRQ_ITEM_p_t PRQ_create_item( 
							  void         *data, 
							  CDA_UINT32_t priority 
							  )
{
	PRQ_ITEM_p_t item			= NULL;
	
	item						= (PRQ_ITEM_p_t) ENQ_create_item(
																 NULL,
																 sizeof(PRQ_ITEM_t)
																 );
	item->data					= data;
	item->priority				= priority;
	
	return item;
}

/****************************************************************************
* SUBROUTINE	PRQ_is_queue_empty
***************************************************************************/
CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue )
{
	CDA_UINT32_t anchor_inx		= 0;
	CDA_BOOL_t is_empty			= CDA_TRUE;
	
	CDA_ASSERT( queue );
	
	while( anchor_inx <= queue->max_priority )
		if( ! ENQ_is_list_empty( (ENQ_ANCHOR_p_t) queue->anchors[anchor_inx++] ) )
			is_empty = CDA_FALSE;
	
	return is_empty;
}

/****************************************************************************
* SUBROUTINE	PRQ_add_item
***************************************************************************/
PRQ_ITEM_p_t PRQ_add_item( 
						   PRQ_ID_t     queue,
						   PRQ_ITEM_p_t item 
						   )
{
	CDA_ASSERT( queue);
	CDA_ASSERT( item);
	
	PRQ__IF_PRIORITY(item->priority, queue->max_priority);
	
	item						= (PRQ_ITEM_p_t) ENQ_add_tail( 
															   (ENQ_ANCHOR_p_t) queue->anchors[item->priority], 
															   (ENQ_ITEM_p_t)   item 
															   );
	
	return item;
}

/****************************************************************************
* SUBROUTINE	PRQ_remove_item
***************************************************************************/
PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue )
{
	PRQ_ITEM_p_t item			= NULL;
	
	CDA_ASSERT( queue );
	
	switch (PRQ_is_queue_empty(queue))
	{
		case(CDA_FALSE):
		{
			CDA_INT32_t anchor_inx = queue->max_priority;
			while(anchor_inx >= 0)
			{	
				if(!ENQ_is_list_empty( (ENQ_ANCHOR_p_t) queue->anchors[anchor_inx]) )
				{
					item = (PRQ_ITEM_p_t) ENQ_deq_head(queue->anchors[anchor_inx]);
					anchor_inx = -1;
				}
				--anchor_inx;
			}
		}			
			break;
		case(CDA_TRUE):
			break;
	}
	
	return item;			
}

/****************************************************************************
* SUBROUTINE	PRQ_destroy_item
***************************************************************************/
PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item )
{
	CDA_ASSERT( item );
	
	item = (PRQ_ITEM_p_t) ENQ_deq_item( (ENQ_ITEM_p_t) item);
	CDA_free(item);
	
	return NULL;
}

/****************************************************************************
* SUBROUTINE	PRQ_empty_queue
***************************************************************************/
PRQ_ID_t PRQ_empty_queue( PRQ_ID_t             queue, 
                          PRQ_DESTROY_PROC_p_t destroy_proc 
						  )
{
	CDA_UINT32_t anchor_inx		= queue->max_priority;
	PRQ_ITEM_p_t item			= NULL;
	
	CDA_ASSERT( queue );
	
	for(anchor_inx = 0; anchor_inx <= queue->max_priority; anchor_inx++)
	{		
		while ( !ENQ_is_list_empty( (ENQ_ANCHOR_p_t) queue->anchors[anchor_inx] ) ) 
		{	
			item = (PRQ_ITEM_p_t) ENQ_deq_head(queue->anchors[anchor_inx]);
			if(destroy_proc != NULL)
				destroy_proc( item->data );
			item = PRQ_destroy_item( item );
		}
	}
	
	return queue;
}

/****************************************************************************
* SUBROUTINE	PRQ_destroy_queue
***************************************************************************/
PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t             queue, 
                            PRQ_DESTROY_PROC_p_t destroy_proc 
							)
{
	CDA_UINT32_t anchor_inx;
	
	CDA_ASSERT( queue );
	
	queue						= PRQ_empty_queue( 
												   queue, 
												   destroy_proc 
												   );
	for(anchor_inx=0;anchor_inx<=queue->max_priority;anchor_inx++)
		queue->anchors[anchor_inx]	= ENQ_destroy_list( 
														(ENQ_ANCHOR_p_t) queue->anchors[anchor_inx]
														);
	
	CDA_free(queue->anchors);
	CDA_free(queue);
	
	return PRQ_NULL_ID;
}

/****************************************************************************
* SUBROUTINE	PRQ_deq_item
***************************************************************************/
PRQ_ITEM_p_t PRQ_deq_item( 
						   PRQ_ITEM_p_t             item 
						   )
{
	CDA_ASSERT( item );
	
	item = (PRQ_ITEM_p_t) ENQ_deq_item( 
										(ENQ_ITEM_p_t) item 
										);
	
	return item;
}

/****************************************************************************
* SUBROUTINE	PRQ_enq_pri_head
***************************************************************************/
PRQ_ITEM_p_t PRQ_enq_pri_head( 
							   PRQ_ID_t            queue,
							   PRQ_ITEM_p_t		item
							   )
{
	CDA_ASSERT(queue);
	CDA_ASSERT(item);

	PRQ__IF_PRIORITY(item->priority, queue->max_priority);
	
	item = (PRQ_ITEM_p_t) ENQ_add_head( 
										(ENQ_ANCHOR_p_t) queue->anchors[item->priority],
										(ENQ_ITEM_p_t) item
										);
	
	return item;
}

/****************************************************************************
* SUBROUTINE	PRQ_deq_pri_head
***************************************************************************/
PRQ_ITEM_p_t PRQ_deq_pri_head( 
							   PRQ_ID_t            queue,
							   CDA_UINT32_t		priority
							   )
{
	PRQ_ITEM_p_t item			= NULL;
	
	CDA_ASSERT(queue);

	PRQ__IF_PRIORITY(priority, queue->max_priority);
	
	if(!ENQ_is_list_empty( (ENQ_ANCHOR_p_t) queue->anchors[priority]) )
		item = (PRQ_ITEM_p_t) ENQ_deq_head( 
										   (ENQ_ANCHOR_p_t) 
										   queue->anchors[priority]
											);
	
	return item;
}

/****************************************************************************
* SUBROUTINE	PRQ_get_pri_head
***************************************************************************/
PRQ_ITEM_p_t PRQ_get_pri_head( 
							   PRQ_ID_t            queue,
							   CDA_UINT32_t		priority
							   )
{
	PRQ_ITEM_p_t item			= NULL;
	
	CDA_ASSERT(queue);
	
	PRQ__IF_PRIORITY(priority, queue->max_priority);
	
	if(!ENQ_is_list_empty( (ENQ_ANCHOR_p_t) queue->anchors[priority]) )
		item = (PRQ_ITEM_p_t) ENQ_GET_HEAD( 
											(ENQ_ANCHOR_p_t) 
											queue->anchors[priority]
											);
	
	return item;	
}

/****************************************************************************
* SUBROUTINE	PRQ_get_next
***************************************************************************/
PRQ_ITEM_p_t PRQ_get_next( 
						   PRQ_ITEM_p_t     item
						   )
{
	PRQ_ITEM_p_t next			= NULL;
	
	CDA_ASSERT(item);
	
	next = (PRQ_ITEM_p_t) ENQ_GET_NEXT( 
						 (ENQ_ITEM_p_t) 
						 item
						 );
	
	return next;	
}
