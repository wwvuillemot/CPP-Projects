#ifndef ENQ_H     /* begin include sandwich          */
#define ENQ_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		ENQ.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.  
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		0
*	DATE CREATED
*		02 July 2005
*	DATE MODIFIED
*		02 July 2005
*	HISTORY
*		0
*		02 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/

/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stdlib.h>
#include <cda.h>

/****************************************************************************
* MACROS
****************************************************************************/
/****************************************************************************
*	NAME
*		ENQ_GET_HEAD
*	DESCRIPTION
*		returns the head of the list
*	ARGUMENTS
*		- list 
****************************************************************************/
#define ENQ_GET_HEAD( list ) \
	((list)->flink)

/****************************************************************************
*	NAME
*		ENQ_GET_TAIL
*	DESCRIPTION
*		returns the tail of the list
*	ARGUMENTS
*		- list 
****************************************************************************/
#define ENQ_GET_TAIL( list ) \
	((list)->blink)

/****************************************************************************
*	NAME
*		ENQ_GET_NEXT
*	DESCRIPTION
*		returns the next item of the list
*	ARGUMENTS
*		- list 
****************************************************************************/
#define ENQ_GET_NEXT( item) \
	((item)->flink)

/****************************************************************************
*	NAME
*		ENQ_GET_PREV
*	DESCRIPTION
*		returns the previous item of the list
*	ARGUMENTS
*		- list 
****************************************************************************/
#define ENQ_GET_PREV( item ) \
	((item)->blink)

/****************************************************************************
*	NAME
*		ENQ_GET_LIST_NAME
*	DESCRIPTION
*		returns the name of list
*	ARGUMENTS
*		- list 
****************************************************************************/
#define ENQ_GET_LIST_NAME( list ) \
	((list)->name)

/****************************************************************************
*	NAME
*		ENQ_GET_ITEM_NAME
*	DESCRIPTION
*		returns the name of item
*	ARGUMENTS
*		- list 
****************************************************************************/
#define ENQ_GET_ITEM_NAME( item ) \
	((item)->name)

/****************************************************************************
* STRUCTURES
****************************************************************************/

/****************************************************************************
* TYPEDEFS
****************************************************************************/
typedef struct enq_item_s 
{ 
    struct enq_item_s *flink; 
    struct enq_item_s *blink; 
    char              *name;
} ENQ_ITEM_t, *ENQ_ITEM_p_t;
typedef ENQ_ITEM_t ENQ_ANCHOR_t, *ENQ_ANCHOR_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
ENQ_ANCHOR_p_t ENQ_create_list(const char *name);
ENQ_ITEM_p_t ENQ_create_item( const char *name, 
							 size_t     size 
							 ); 
CDA_BOOL_t ENQ_is_item_enqed( ENQ_ITEM_p_t item );
CDA_BOOL_t ENQ_is_list_empty( ENQ_ANCHOR_p_t list );
ENQ_ITEM_p_t ENQ_add_head( ENQ_ANCHOR_p_t list, 
                           ENQ_ITEM_p_t   item 
						   ); 
ENQ_ITEM_p_t ENQ_add_tail( ENQ_ANCHOR_p_t list, 
                           ENQ_ITEM_p_t   item 
						   );
ENQ_ITEM_p_t ENQ_add_after( ENQ_ITEM_p_t item, 
                            ENQ_ITEM_p_t after 
							);
ENQ_ITEM_p_t ENQ_add_before( ENQ_ITEM_p_t item, 
                             ENQ_ITEM_p_t before 
							 );
ENQ_ITEM_p_t ENQ_deq_item( ENQ_ITEM_p_t item );
ENQ_ITEM_p_t ENQ_deq_head( ENQ_ANCHOR_p_t list );
ENQ_ITEM_p_t ENQ_deq_tail( ENQ_ANCHOR_p_t list );
ENQ_ITEM_p_t ENQ_destroy_item( ENQ_ITEM_p_t item ); 
ENQ_ANCHOR_p_t ENQ_empty_list( ENQ_ANCHOR_p_t list );
ENQ_ANCHOR_p_t ENQ_destroy_list( ENQ_ANCHOR_p_t list ); 

#endif            /* end include sandwich            */
