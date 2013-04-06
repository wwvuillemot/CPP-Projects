/****************************************************************************
*	NAME
*		ENQ
*	DESCRIPTION
*		C DATA structures and ALGORITHMS source file.
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		2
*	DATE CREATED
*		02 July 2005
*	DATE MODIFIED
*		10 July 2005
*	HISTORY
*		2
*		10 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- fixed memory leak in ENQ_create_item()
*		- dereferenced ENQ_is_list_empty() from ENQ_is_item_enqed()
*		- simplified ENQ_deq_head() and ENQ_deq_tail to have only one
*		  exit point
*		- corrected ISO violation with CDA_ASSERT() coming before
*		  declarations are complete
*
*		1
*		09 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- made all ENQ_add subroutines reference EQN_add_head()
*		- made ENQ_create_item() reference ENQ_create_list()
*		- made ENQ_is_list_empty() reference ENQ_is_item_enqed()
*
*		0
*		02 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
#include <enq.h>
#include <enqp.h>

/****************************************************************************
*	NAME
*		ENQ_create_list
*	DESCRIPTION
*		creates a queue list
*	ARGUMENTS
*		- name :: name of the list (optional)
*	RETURN
*		pointer to a list of type, ENQ_ANCHOR_p_t
*	NOTES
*		- caller is responsible for freeing the memory occupied by the list
*		  by calling ENQ_destroy_list
*		- list name is copied into a private buffer and freed when list is
*		  destroyed
****************************************************************************/
ENQ_ANCHOR_p_t ENQ_create_list( const char *name ) 
{ 
    ENQ_ANCHOR_p_t list = CDA_NEW( ENQ_ANCHOR_t ); 
		
    list->flink = list; 
    list->blink = list; 
    list->name = CDA_NEW_STR_IF( name ); 
	
	return list;
} 

/****************************************************************************
*	NAME
*		ENQ_create_item
*	DESCRIPTION
*		creates an item to add to a queue list
*	ARGUMENTS
*		- name :: name of the item (optional)
*		- size :: size (bytes) of the item itself
*	RETURN
*		pointer to the item of type, ENQ_ITEM_p_t
*	NOTES
*		- caller is responsible for freeing the memory occupied by the item
*		  by calling ENQ_destroy_item. 
*		- item name is copied into a private buffer and freed when list is
*		  destroyed
****************************************************************************/
ENQ_ITEM_p_t ENQ_create_item( const char *name, size_t size ) 
{ 
    ENQ_ITEM_p_t item = (ENQ_ITEM_p_t)CDA_malloc( size ); 
    CDA_ASSERT( size >= sizeof(ENQ_ITEM_t) ); 
    
	item->flink = item; 
    item->blink = item; 
    item->name = CDA_NEW_STR_IF( name ); 
	
    return item; 
} 

/****************************************************************************
*	NAME
*		ENQ_is_item_enqed
*	DESCRIPTION
*		logical, tells if item is in queue or not (enqueued)
*	ARGUMENTS
*		- item :: item to check
*	RETURN
*		CDA_TRUE if the item is enqueued, CDA_FALSE otherwise 
*	NOTES
*		- none
****************************************************************************/
CDA_BOOL_t ENQ_is_item_enqed( ENQ_ITEM_p_t item ) 
{ 
	CDA_BOOL_t rcode = (item->flink == item ? CDA_FALSE : CDA_TRUE); 
	CDA_ASSERT(item);
    return rcode; 	
} 

/****************************************************************************
*	NAME
*		ENQ_is_list_empty
*	DESCRIPTION
*		logical, tells if list is empty or not
*	ARGUMENTS
*		- list :: list to check
*	RETURN
*		CDA_TRUE if the list is empty, CDA_FALSE otherwise 
*	NOTES
*		- none
****************************************************************************/
CDA_BOOL_t ENQ_is_list_empty( ENQ_ANCHOR_p_t list ) 
{ 
    CDA_BOOL_t rcode = (list->flink == list) ? CDA_TRUE : CDA_FALSE;
	CDA_ASSERT(list);
    return rcode; 
} 

/****************************************************************************
*	NAME
*		ENQ_add_head
*	DESCRIPTION
*		add item to head of list
*	ARGUMENTS
*		- list :: list in which to enqueue 
*		- item :: item to enqueue 
*	RETURN
*		address of enqueued item 
*	NOTES
*		- all other ENQ_add reference this subroutine
****************************************************************************/
ENQ_ITEM_p_t ENQ_add_head( ENQ_ANCHOR_p_t list, 
                           ENQ_ITEM_p_t   item 
						   )
{
	CDA_ASSERT(list);
	CDA_ASSERT(item);
	CDA_ASSERT(! ENQ_is_item_enqed(item));
	
	item->flink = list->flink;
	item->blink = list;
	list->flink->blink = item;
	list->flink = item;
	
	return item;
}

/****************************************************************************
*	NAME
*		ENQ_add_tail
*	DESCRIPTION
*		add item to tail of list
*	ARGUMENTS
*		- list :: list in which to enqueue 
*		- item :: item to enqueue 
*	RETURN
*		address of enqueued item 
*	NOTES
*		- none
****************************************************************************/
ENQ_ITEM_p_t ENQ_add_tail( ENQ_ANCHOR_p_t list, 
                           ENQ_ITEM_p_t   item 
						   )
{
	CDA_ASSERT(list);
	CDA_ASSERT(item);
	CDA_ASSERT(! ENQ_is_item_enqed(item));
		
	item = ENQ_add_head( (ENQ_ANCHOR_p_t) list->blink, (ENQ_ITEM_p_t) item);
	
	return item;
}

/****************************************************************************
*	NAME
*		ENQ_add_after
*	DESCRIPTION
*		add item after another item
*	ARGUMENTS
*		- item :: item to add 
*		- after :: item to place after
*	RETURN
*		address of added item 
*	NOTES
*		- none
****************************************************************************/
ENQ_ITEM_p_t ENQ_add_after( ENQ_ITEM_p_t item, 
                            ENQ_ITEM_p_t after 
							)
{
	CDA_ASSERT(item);
	CDA_ASSERT(after);
	CDA_ASSERT(! ENQ_is_item_enqed(item));
	
	item = ENQ_add_head( (ENQ_ANCHOR_p_t) after, item);
	
	return item;
}

/****************************************************************************
*	NAME
*		ENQ_add_before
*	DESCRIPTION
*		add item before another item
*	ARGUMENTS
*		- item :: item to add 
*		- before :: item to place before
*	RETURN
*		address of added item 
*	NOTES
*		- none
****************************************************************************/
ENQ_ITEM_p_t ENQ_add_before( ENQ_ITEM_p_t item, 
                             ENQ_ITEM_p_t before 
							 )
{
	CDA_ASSERT(item);
	CDA_ASSERT(before);
	CDA_ASSERT(! ENQ_is_item_enqed(item));

	item = ENQ_add_head( (ENQ_ANCHOR_p_t) before->blink, item);
	
	return item;
}

/****************************************************************************
*	NAME
*		ENQ_deq_item
*	DESCRIPTION
*		dequeue an item
*	ARGUMENTS
*		- item :: item to dequeue 
*	RETURN
*		address of dequeued item 
*	NOTES
*		- none
****************************************************************************/
ENQ_ITEM_p_t ENQ_deq_item( ENQ_ITEM_p_t item )
{
	CDA_ASSERT(item);
	
	item->blink->flink = item->flink;
	item->flink->blink = item->blink;
	item->flink = item;
	item->blink = item;
	
	return item;
}

/****************************************************************************
*	NAME
*		ENQ_deq_head
*	DESCRIPTION
*		dequeue the head of a list
*	ARGUMENTS
*		- list :: list from where head will be dequeued 
*	RETURN
*		address of dequeued head if non-empty list otherwise list itself
*	NOTES
*		- none
****************************************************************************/
ENQ_ITEM_p_t ENQ_deq_head( ENQ_ANCHOR_p_t list )
{
	CDA_ASSERT(list);
	return ENQ_deq_item(list->flink);
}

/****************************************************************************
*	NAME
*		ENQ_deq_tail
*	DESCRIPTION
*		dequeue the tail of a list
*	ARGUMENTS
*		- list :: list from where tail will be dequeued 
*	RETURN
*		address of dequeued tail if non-empty list otherwise list itself
*	NOTES
*		- none
****************************************************************************/
ENQ_ITEM_p_t ENQ_deq_tail( ENQ_ANCHOR_p_t list )
{
	CDA_ASSERT(list);
	return ENQ_deq_item(list->blink);
}

/****************************************************************************
*	NAME
*		ENQ_destroy_item
*	DESCRIPTION
*		destroy an item
*	ARGUMENTS
*		- item :: item to destroy
*	RETURN
*		NULL
*	NOTES
*		- The item to destroy may be enqueued or unenqueued. If enqueued, 
*		  it will be dequeued prior to destruction. 
****************************************************************************/
ENQ_ITEM_p_t ENQ_destroy_item( ENQ_ITEM_p_t item )
{
	CDA_ASSERT(item);
	ENQ_deq_item( item ); 
    CDA_free( item->name ); 
    CDA_free( item ); 	
    return NULL; 
}

/****************************************************************************
*	NAME
*		ENQ_empty_list
*	DESCRIPTION
*		empty a list
*	ARGUMENTS
*		- list :: list to empty
*	RETURN
*		address of the list
*	NOTES
*		- All items enqueued in the list will be destroyed.
****************************************************************************/
ENQ_ANCHOR_p_t ENQ_empty_list( ENQ_ANCHOR_p_t list )
{
	CDA_ASSERT(list);
	while ( !ENQ_is_list_empty( list ) ) 
        ENQ_destroy_item( list->flink ); 	
	return list; 
}

/****************************************************************************
*	NAME
*		ENQ_destroy_list
*	DESCRIPTION
*		destroy a list
*	ARGUMENTS
*		- list :: list to destroy
*	RETURN
*		NULL
*	NOTES
*		- All items enqueued in the list will be destroyed with the list 
*		  itself
****************************************************************************/
ENQ_ANCHOR_p_t ENQ_destroy_list( ENQ_ANCHOR_p_t list )
{
	CDA_ASSERT(list);
	ENQ_empty_list(list);
	CDA_free( list->name ); 
    CDA_free( list ); 
	return NULL;
}

