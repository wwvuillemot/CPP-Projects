/****************************************************************************
*	NAME
*		PROJECT02 TEST DRIVER
*	DESCRIPTION
*		Test driver for Project 02, C Data Structures & Algorithms
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
*		- original; copied from Project 01
****************************************************************************/

/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include <cda.h>
#include <enq.h>
#include <testrig.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define ARR_CARD	(1000)

/****************************************************************************
* TYPEDEF
****************************************************************************/
typedef struct enq_test_s
{
	ENQ_ITEM_t list;
	int	number;
} ENQ_TEST_t, *ENQ_TEST_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
TEST_PROC_t test_create_list01;
TEST_PROC_t test_create_list02;
TEST_PROC_t test_create_item;

TEST_PROC_t test_is_item_enqed01;
TEST_PROC_t test_is_item_enqed02;
TEST_PROC_t test_is_list_empty01;
TEST_PROC_t test_is_list_empty02;

TEST_PROC_t test_add_head;
TEST_PROC_t test_add_tail;
TEST_PROC_t test_add_after;
TEST_PROC_t test_add_before;

TEST_PROC_t test_deq_item;
TEST_PROC_t test_deq_head01;
TEST_PROC_t test_deq_head02;
TEST_PROC_t test_deq_tail01;
TEST_PROC_t test_deq_tail02;

TEST_PROC_t test_destroy_item;
TEST_PROC_t test_empty_list;
TEST_PROC_t test_destroy_list;

TEST_PROC_t test_get_head;
TEST_PROC_t test_get_tail;
TEST_PROC_t test_get_next;
TEST_PROC_t test_get_prev;
TEST_PROC_t test_get_item_name;
TEST_PROC_t test_get_list_name;

/****************************************************************************
* MAIN
****************************************************************************/
int main () 
{

	TEST_p_t testrig_ENQ;
	TEST_p_t testproc_ENQ;
	
	TEST_PROC_p_t proc_create_list01 = test_create_list01;
	TEST_PROC_p_t proc_create_list02 = test_create_list02;
	TEST_PROC_p_t proc_create_item =   test_create_item;
	
	TEST_PROC_p_t proc_is_item_enqed01 = test_is_item_enqed01;
	TEST_PROC_p_t proc_is_item_enqed02 = test_is_item_enqed02;
	TEST_PROC_p_t proc_is_list_empty01 = test_is_list_empty01;
	TEST_PROC_p_t proc_is_list_empty02 = test_is_list_empty02;
	
	TEST_PROC_p_t proc_add_head =      test_add_head;
	TEST_PROC_p_t proc_add_tail =      test_add_tail;
	TEST_PROC_p_t proc_add_after =     test_add_after;
	TEST_PROC_p_t proc_add_before =    test_add_before;
	
	TEST_PROC_p_t proc_deq_item =      test_deq_item;
	TEST_PROC_p_t proc_deq_head01 =    test_deq_head01;
	TEST_PROC_p_t proc_deq_head02 =    test_deq_head02;
	TEST_PROC_p_t proc_deq_tail01 =    test_deq_tail01;
	TEST_PROC_p_t proc_deq_tail02 =    test_deq_tail02;
	
	TEST_PROC_p_t proc_destroy_item =  test_destroy_item;
	TEST_PROC_p_t proc_empty_list =    test_empty_list;
	TEST_PROC_p_t proc_destroy_list =  test_destroy_list;
	
	TEST_PROC_p_t proc_get_head =      test_get_head;
	TEST_PROC_p_t proc_get_tail =      test_get_tail;
	TEST_PROC_p_t proc_get_next =      test_get_next;
	TEST_PROC_p_t proc_get_prev =      test_get_prev;
	TEST_PROC_p_t proc_get_item_name = test_get_item_name;
	TEST_PROC_p_t proc_get_list_name = test_get_list_name;
	
	/*
	 * CREATE TEST RIG
	 */
	testrig_ENQ = TEST_createrig("ENQ Test Rig");
	
	/*
	 * QUEUE TEST PROCS FOR USE WITH TEST RIG
	 */
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_create_list01,    "ENQ_CREATE_LIST01");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_create_list02,    "ENQ_CREATE_LIST02");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_create_item,      "ENQ_CREATE_ITEM");
	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_is_item_enqed01,  "ENQ_IS_ITEM_ENQUED 01");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_is_item_enqed02,  "ENQ_IS_ITEM_ENQUED 02");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_is_list_empty01,  "ENQ_IS_LIST_EMPTY 01");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_is_list_empty02,  "ENQ_IS_LIST_EMPTY 02");
	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_add_head,         "ENQ_ADD_HEAD");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_add_tail,         "ENQ_ADD_TAIL");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_add_after,        "ENQ_ADD_AFTER");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_add_before,       "ENQ_ADD_BEFORE");
	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_deq_item,         "ENQ_DEQ_ITEM");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_deq_head01,       "ENQ_DEQ_HEAD 01");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_deq_head02,       "ENQ_DEQ_HEAD 02");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_deq_tail01,       "ENQ_DEQ_TAIL 01");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_deq_tail02,       "ENQ_DEQ_TAIL 02");
	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_destroy_item,     "ENQ_DESTROY_ITEM");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_empty_list,       "ENQ_EMPTY_LIST");
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_destroy_list,     "ENQ_DESTROY_LIST");	

	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_get_head,        "ENQ_GET_HEAD");	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_get_tail,        "ENQ_GET_TAIL");	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_get_next,        "ENQ_GET_NEXT");	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_get_prev,        "ENQ_GET_PREV");	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_get_item_name,   "ENQ_GET_ITEM_NAME");	
	testproc_ENQ = TEST_addproc(testrig_ENQ, proc_get_list_name,   "ENQ_GET_LIST_NAME");	
		
	/*
	 * RUN TEST RIG
	 */
	TEST_runrig(testrig_ENQ);
	
	/*
	 * CLEAN UP
	 */
	TEST_destroyrig(testrig_ENQ);

	return 0;
}

/****************************************************************************
* DRIVERS
****************************************************************************/

/*
 * ENQ_CREATE_LIST01
 */
TEST_RESULT_t test_create_list01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list");

	rcode = ( 
			  (list->blink == list) && 
			  (list->flink == list) 
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_CREATE_LIST02
 */
TEST_RESULT_t test_create_list02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "" );
	
	rcode = test_get_list_name();
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_CREATE_ITEM
 */
TEST_RESULT_t test_create_item(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ITEM_p_t  item = ENQ_create_item( "item", sizeof(ENQ_TEST_t) );

	rcode = ( 
			  (item->blink == item) && 
			  (item->flink == item) 
			) ? CDA_TRUE : CDA_FALSE;

	ENQ_destroy_list(item);	
	return rcode;
}

/*
 * ENQ_IS_ITEM_ENQED01
 */
TEST_RESULT_t test_is_item_enqed01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ITEM_p_t  item = ENQ_create_item( "item", sizeof(ENQ_TEST_t) );

	rcode = ( 
			  (TEST_RESULT_t) ENQ_is_item_enqed( item ) == CDA_FALSE
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(item);	
	return rcode;
}

/*
 * ENQ_IS_ITEM_ENQED02
 */
TEST_RESULT_t test_is_item_enqed02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t  item = ENQ_create_item( "item", sizeof(ENQ_TEST_t) );

	ENQ_add_head(list, item);
	
	rcode = ( 
			  (TEST_RESULT_t) ENQ_is_item_enqed( item ) == CDA_TRUE
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(item);	
	return rcode;
}

/*
 * ENQ_IS_LIST_EMPTY01
 */
TEST_RESULT_t test_is_list_empty01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );

	rcode = ( 
			  (TEST_RESULT_t) ENQ_is_list_empty(list) == CDA_TRUE
			) ? CDA_TRUE : CDA_FALSE;

	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_IS_LIST_EMPTY02
 */
TEST_RESULT_t test_is_list_empty02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t  item = ENQ_create_item( "item", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, item);
	
	rcode = ( 
			  (TEST_RESULT_t) ENQ_is_list_empty(list) == CDA_FALSE
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_ADD_HEAD
 */
TEST_RESULT_t test_add_head(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item", sizeof(ENQ_TEST_t) );
	
	rcode = ( 
			  item == ENQ_add_head(list, item) 
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_ADD_TAIL
 */
TEST_RESULT_t test_add_tail(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item", sizeof(ENQ_TEST_t) );
	
	rcode = ( 
			  item == ENQ_add_tail(list, item) 
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_ADD_AFTER
 */
TEST_RESULT_t test_add_after(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    after = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(after, head);

	rcode = (
			 (head->flink == after) &&
			 (after->blink == head)
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_ADD_BEFORE
 */
TEST_RESULT_t test_add_before(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    before = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_before(before, head);
	
	rcode = ( 
			  (ENQ_GET_PREV(head) == before) &&
			  (ENQ_GET_NEXT(before) == head) &&
			  (ENQ_GET_HEAD(list) == before) 
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DEQ_ITEM
 */
TEST_RESULT_t test_deq_item(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	
	rcode = ( 
			  (head == (ENQ_ITEM_p_t) ENQ_deq_item(head)) &&
			  (ENQ_GET_NEXT(head) == head) &&
			  (ENQ_GET_PREV(head) == head)
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DEQ_HEAD01
 */
TEST_RESULT_t test_deq_head01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	
	rcode = ( 
			  (head == ENQ_deq_head(list)) 
			) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DEQ_HEAD02
 */
TEST_RESULT_t test_deq_head02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_deq_head(list);
	
	rcode = ( 
			  (head == list) &&
			  (ENQ_GET_NEXT(head) == head) 
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DEQ_TAIL01
 */
TEST_RESULT_t test_deq_tail01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    tail = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	
	ENQ_add_tail(list, tail);
	
	rcode = ( 
			  (tail == ENQ_deq_tail(list)) 
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DEQ_TAIL02
 */
TEST_RESULT_t test_deq_tail02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    tail = ENQ_deq_tail(list);
	
	rcode = ( 
			  (tail == list)
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DESTROY_ITEM
 */
TEST_RESULT_t test_destroy_item(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	head = ENQ_destroy_item(head);
	
	rcode = ( 
			  (head == NULL) &&
			  (ENQ_is_list_empty(list))
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_EMPTY_LIST
 */
TEST_RESULT_t test_empty_list(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(item, head);
	
	ENQ_empty_list(list);
	
	rcode = ( 
			  (ENQ_is_list_empty(list))
			  ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_list(list);
	return rcode;
}

/*
 * ENQ_DESTROY_LIST
 */
TEST_RESULT_t test_destroy_list(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(item, head);
	
	list = ENQ_destroy_list(list);
	
	rcode = ( 
			  (list == NULL)
			  ) ? CDA_TRUE : CDA_FALSE;
	
	return rcode;
}

/*
 * ENQ_GET_HEAD
 */
TEST_RESULT_t test_get_head(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(item, head);
	
	rcode = ( 
			  (head == ENQ_GET_HEAD(list) )
			  ) ? CDA_TRUE : CDA_FALSE;

	ENQ_destroy_list(list);
	
	return rcode;
}

/*
 * ENQ_GET_TAIL
 */
TEST_RESULT_t test_get_tail(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(item, head);
	
	rcode = ( 
			  (item == ENQ_GET_TAIL(list) )
			) ? CDA_TRUE : CDA_FALSE;
	
	list = ENQ_destroy_list(list);
	
	return rcode;
}

/*
 * ENQ_GET_NEXT
 */
TEST_RESULT_t test_get_next(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(item, head);
	
	rcode = ( 
			  (item == ENQ_GET_NEXT(head)) && 
			  (list == ENQ_GET_NEXT(item)) 
			  ) ? CDA_TRUE : CDA_FALSE;
	
	list = ENQ_destroy_list(list);
	
	return rcode;
}

/*
 * ENQ_GET_PREV
 */
TEST_RESULT_t test_get_prev(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );
	ENQ_ITEM_p_t    head = ENQ_create_item( "item1", sizeof(ENQ_TEST_t) );
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	ENQ_add_head(list, head);
	ENQ_add_after(item, head);
	
	rcode = ( 
			  (list == ENQ_GET_PREV(head)) && 
			  (item == ENQ_GET_PREV(list))
			  ) ? CDA_TRUE : CDA_FALSE;
	
	list = ENQ_destroy_list(list);
	
	return rcode;
}

/*
 * ENQ_GET_ITEM_NAME
 */
TEST_RESULT_t test_get_item_name(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ITEM_p_t    item = ENQ_create_item( "item2", sizeof(ENQ_TEST_t) );
	
	rcode = ( 
			  (!strcmp(item->name, ENQ_GET_ITEM_NAME(item)))
			   ) ? CDA_TRUE : CDA_FALSE;
	
	ENQ_destroy_item(item);
	
	return rcode;
}

/*
 * ENQ_GET_LIST_NAME
 */
TEST_RESULT_t test_get_list_name(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	ENQ_ANCHOR_p_t  list = ENQ_create_list( "list" );

	rcode = ( 
			  (!strcmp(list->name, ENQ_GET_LIST_NAME(list)))
			) ? CDA_TRUE : CDA_FALSE;
	
	list = ENQ_destroy_list(list);
	
	return rcode;
}