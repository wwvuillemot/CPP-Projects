/****************************************************************************
*	NAME
*		PROJECT04 TEST DRIVER
*	DESCRIPTION
*		Test driver for Project 04, C Data Structures & Algorithms
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
*		- original; copied from Project 02
****************************************************************************/

/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stddef.h>
#include <stdio.h>

#include <cda.h>
#include <testrig.h>

#include <prqp.h>

/****************************************************************************
* MACROS
****************************************************************************/

/****************************************************************************
* TYPEDEF
****************************************************************************/
typedef struct prq_test_s
{
	int	number;
} STACK_TEST_t, *STACK_TEST_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
static TEST_PROC_t test_create_prq01;
static TEST_PROC_t test_create_prq02;
static TEST_PROC_t test_create_prq03;

static TEST_PROC_t test_add_prq01;
static TEST_PROC_t test_add_prq02;

static TEST_PROC_t test_remove_prq01;
static TEST_PROC_t test_remove_prq02;

static TEST_PROC_t test_destroy_prq01;
static TEST_PROC_t test_destroy_prq02;

static TEST_PROC_t test_empty_prq01;

static TEST_PROC_t test_enq_prq01;
static TEST_PROC_t test_enq_prq02;
static TEST_PROC_t test_enq_prq03;
/****************************************************************************
* MAIN
****************************************************************************/
int main () 
{
	TEST_p_t testrig_PRQ;
	TEST_p_t testproc_PRQ;
	
	TEST_PROC_p_t proc_create_prq01 = test_create_prq01;
	TEST_PROC_p_t proc_create_prq02 = test_create_prq02;
	TEST_PROC_p_t proc_create_prq03 = test_create_prq03;

	TEST_PROC_p_t proc_add_prq01 = test_add_prq01;
	TEST_PROC_p_t proc_add_prq02 = test_add_prq02;
		
	TEST_PROC_p_t proc_remove_prq01 = test_remove_prq01;
	TEST_PROC_p_t proc_remove_prq02 = test_remove_prq02;

	TEST_PROC_p_t proc_destroy_prq01 = test_destroy_prq01;
	TEST_PROC_p_t proc_destroy_prq02 = test_destroy_prq02;

	TEST_PROC_p_t proc_empty_prq01 = test_empty_prq01;

	TEST_PROC_p_t proc_enq_prq01 = test_enq_prq01;
	TEST_PROC_p_t proc_enq_prq02 = test_enq_prq02;
	TEST_PROC_p_t proc_enq_prq03 = test_enq_prq03;
	/*
	 * CREATE TEST RIG
	 */
	testrig_PRQ = TEST_createrig("PRQ Test Rig");
	
	/*
	 * QUEUE TEST PROCS FOR USE WITH TEST RIG
	 */
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_create_prq01,    "PRQ_CREATE 01");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_create_prq02,    "PRQ_CREATE 02");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_create_prq03,    "PRQ_CREATE 03");

	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_add_prq01,    "PRQ_ADD 01");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_add_prq02,    "PRQ_ADD 02");
	
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_remove_prq01,    "PRQ_REMOVE 01");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_remove_prq02,    "PRQ_REMOVE 02");

	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_destroy_prq01,    "PRQ_DESTROY 01");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_destroy_prq02,    "PRQ_DESTROY 02");

	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_empty_prq01,    "PRQ_EMPTY 01");

	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_enq_prq01,    "PRQ_ENQDEQ 01");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_enq_prq02,    "PRQ_ENQDEQ 02");
	testproc_PRQ = TEST_addproc(testrig_PRQ, proc_enq_prq03,    "PRQ_ENQDEQ 03");
	/*
	 * RUN TEST RIG
	 */
	TEST_runrig(testrig_PRQ);
	
	/*
	 * CLEAN UP
	 */
	TEST_destroyrig(testrig_PRQ);
	
	return 0;
}

/****************************************************************************
* DRIVERS
****************************************************************************/
#define QUEUE_NAME	("WARD")
#define QUEUE_PRI	(2)
/*
 * test_create_prq01
 */
static TEST_RESULT_t test_create_prq01(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	PRQ_ID_t prq					= NULL;
	prq								= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	rcode							= PRQ_NULL_ID == PRQ_destroy_queue(prq, NULL) ? CDA_TRUE : CDA_FALSE;
	
	return rcode;
}

/*
 * test_create_prq02
 */
static TEST_RESULT_t test_create_prq02(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	
	rcode							= ( QUEUE_PRI == prq->max_priority ) ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

/*
 * test_create_prq04
 */
static TEST_RESULT_t test_create_prq03(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;

	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	rcode							= PRQ_is_queue_empty(prq);
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}


/*
 * test_create_prq03
 */
static TEST_RESULT_t test_add_prq01(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	rcode							= ( item == PRQ_add_item( prq, item )  ) ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}


static TEST_RESULT_t test_add_prq02(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_add_item( prq, item ) ;
	rcode							= PRQ_is_queue_empty( prq ) == CDA_FALSE ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_remove_prq01(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_add_item( prq, item ) ;
	rcode							= ( item == PRQ_remove_item( prq )  ) ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_remove_prq02(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	rcode							= ( NULL == PRQ_remove_item( prq )  ) ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_destroy_prq01(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_add_item( prq, item ) ;
	rcode							= PRQ_destroy_item( item ) == NULL ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_destroy_prq02(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_add_item( prq, item ) ;
	item							= PRQ_destroy_item( item );
	rcode							= PRQ_is_queue_empty( prq ) == CDA_TRUE ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_empty_prq01(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_add_item( prq, item ) ;
	prq								= PRQ_empty_queue( prq, NULL );
	rcode							= PRQ_is_queue_empty( prq ) == CDA_TRUE ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_enq_prq01(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_enq_pri_head( prq, item ) ;
	rcode							= item == PRQ_deq_pri_head( prq,  QUEUE_PRI) ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_enq_prq02(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	int number						= QUEUE_PRI*2;
	int	*data						= &number;
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	PRQ_ITEM_p_t item				= PRQ_create_item( data, QUEUE_PRI);
	item							= PRQ_enq_pri_head( prq, item ) ;
	rcode							= item == PRQ_deq_pri_head( prq,  QUEUE_PRI-1) ? CDA_FALSE : CDA_TRUE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}

static TEST_RESULT_t test_enq_prq03(void)
{
	TEST_RESULT_t rcode				= CDA_TRUE;
	
	PRQ_ID_t prq					= PRQ_create_queue( QUEUE_NAME, QUEUE_PRI );
	rcode							= NULL == PRQ_deq_pri_head( prq, QUEUE_PRI ) ? CDA_TRUE : CDA_FALSE;
	
	PRQ_destroy_queue(prq, NULL);
	
	return rcode;
}