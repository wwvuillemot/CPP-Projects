/****************************************************************************
*	NAME
*		PROJECT03 TEST DRIVER
*	DESCRIPTION
*		Test driver for Project 03, C Data Structures & Algorithms
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		0
*	DATE CREATED
*		24 July 2005
*	DATE MODIFIED
*		24 July 2005
*	HISTORY
*		0
*		24 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original; copied from Project 02
****************************************************************************/

/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <signal.h>

#include <cda.h>
#include <testrig.h>
#include <stk.h>
#include <stkp.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define STACK_SIZE	(1)

/****************************************************************************
* TYPEDEF
****************************************************************************/
typedef struct stack_test_s
{
	int	number;
} STACK_TEST_t, *STACK_TEST_p_t;

typedef void SIG_PROC_t( int sig );
typedef SIG_PROC_t *SIG_PROC_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
static TEST_PROC_t test_create_stack01;
static TEST_PROC_t test_create_stack02;
static TEST_PROC_t test_create_stack03;
static TEST_PROC_t test_create_stack04;

static TEST_PROC_t test_push_stack01;
static TEST_PROC_t test_push_stack02;
static TEST_PROC_t test_push_stack03;

static TEST_PROC_t test_pop_stack01;
static TEST_PROC_t test_pop_stack02;

static TEST_PROC_t test_peek_stack01;
static TEST_PROC_t test_peek_stack02;

static TEST_PROC_t test_clear_stack01;
static TEST_PROC_t test_destroy_stack01;

static SIG_PROC_t trap_sigabt;

static CDA_BOOL_t SIG_RESULT = CDA_FALSE;
static SIG_PROC_p_t old_sigabt = SIG_DFL;

extern int STK_check( void );

/****************************************************************************
* MAIN
****************************************************************************/
extern int STK_check () 
{
	
	TEST_p_t testrig_STK;
	TEST_p_t testproc_STK;
	
	TEST_PROC_p_t proc_create_stack01 = test_create_stack01;
	TEST_PROC_p_t proc_create_stack02 = test_create_stack02;
	TEST_PROC_p_t proc_create_stack03 = test_create_stack03;
	TEST_PROC_p_t proc_create_stack04 = test_create_stack04;
	
	TEST_PROC_p_t proc_push_stack01 =	test_push_stack01;
	TEST_PROC_p_t proc_push_stack02 =	test_push_stack02;
	TEST_PROC_p_t proc_push_stack03 =	test_push_stack03;
	
	TEST_PROC_p_t proc_pop_stack01 =	test_pop_stack01;
	TEST_PROC_p_t proc_pop_stack02 =	test_pop_stack02;
	
	TEST_PROC_p_t proc_peek_stack01 =	test_peek_stack01;
	TEST_PROC_p_t proc_peek_stack02 =	test_peek_stack02;
	
	TEST_PROC_p_t proc_clear_stack01 =		test_clear_stack01;
	TEST_PROC_p_t proc_destroy_stack01 =	test_destroy_stack01;
	
	/*
	 * CREATE TEST RIG
	 */
	testrig_STK = TEST_createrig("STK Test Rig");
	
	/*
	 * QUEUE TEST PROCS FOR USE WITH TEST RIG
	 */
	testproc_STK = TEST_addproc(testrig_STK, proc_create_stack01,    "STK_CREATE_CREATE 01");
	testproc_STK = TEST_addproc(testrig_STK, proc_create_stack02,    "STK_CREATE_CREATE 02");
	testproc_STK = TEST_addproc(testrig_STK, proc_create_stack03,    "STK_CREATE_CREATE 03");
	testproc_STK = TEST_addproc(testrig_STK, proc_create_stack04,    "STK_CREATE_CREATE 04");
	
	testproc_STK = TEST_addproc(testrig_STK, proc_push_stack01,		"STK_PUSH_STACK 01");
	testproc_STK = TEST_addproc(testrig_STK, proc_push_stack02,		"STK_PUSH_STACK 02");
	testproc_STK = TEST_addproc(testrig_STK, proc_push_stack03,		"STK_PUSH_STACK 03");
	
	testproc_STK = TEST_addproc(testrig_STK, proc_pop_stack01,		"STK_POP_STACK 01");
	testproc_STK = TEST_addproc(testrig_STK, proc_pop_stack02,		"STK_POP_STACK 02");
	
	/*testproc_STK = TEST_addproc(testrig_STK, proc_peek_stack01,		"STK_PEEK_STACK 01");
	*/
	testproc_STK = TEST_addproc(testrig_STK, proc_peek_stack02,		"STK_PEEK_STACK 02");
	
	testproc_STK = TEST_addproc(testrig_STK, proc_clear_stack01,	"STK_CLEAR_STACK 01");
	testproc_STK = TEST_addproc(testrig_STK, proc_destroy_stack01,	"STK_DESTROY_STACK 01");
	
	/*
	 * RUN TEST RIG
	 */
	TEST_runrig(testrig_STK);
	
	/*
	 * CLEAN UP
	 */
	TEST_destroyrig(testrig_STK);
	
	return 0;
}

static void trap_sigabt( int sig )
{
	SIG_RESULT = CDA_FALSE;
	if( sig == SIGABRT )
		SIG_RESULT = CDA_TRUE;
}


/****************************************************************************
* DRIVERS
****************************************************************************/

/*
 * test_create_stack01
 */
static TEST_RESULT_t test_create_stack01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	rcode = ( 
			  (	STK_NULL_ID == STK_destroy_stack(stack))
			  ) ? CDA_TRUE : CDA_FALSE;
	
	return rcode;
}

/*
 * test_create_stack02
 */
static TEST_RESULT_t test_create_stack02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	rcode = ( 
			  ( STACK_SIZE == stack->size ) 
			  ) ? CDA_TRUE : CDA_FALSE;
	
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_create_stack03
 */
static TEST_RESULT_t test_create_stack03(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	rcode = ( 
			  (stack->sptr == stack->stack) 
			  ) ? CDA_TRUE : CDA_FALSE;
	
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_create_stack04
 */
static TEST_RESULT_t test_create_stack04(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	rcode = STK_is_stack_empty( stack );
	
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_push_stack01
 */
static TEST_RESULT_t test_push_stack01(void)
{
	int *item;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	
	old_sigabt = signal(SIGABRT, trap_sigabt);
	
	STK_push_item( stack, item );
	/*STK_push_item( stack, item );*/
	
	signal(SIGABRT, old_sigabt);
	
	STK_destroy_stack(stack);
	return CDA_TRUE;
}

/*
 * test_push_stack02
 */
static TEST_RESULT_t test_push_stack02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	int item;
	STK_push_item(stack, &item);
	
	rcode = STK_is_stack_full(stack);
	
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_push_stack03
 */
static TEST_RESULT_t test_push_stack03(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	int item = 18;
	STK_push_item(stack, &item);	
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_pop_stack01
 */
static TEST_RESULT_t test_pop_stack01(void)
{
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	
	old_sigabt = signal(SIGABRT, trap_sigabt);
	
	/*STK_pop_item( stack);*/
	
	signal(SIGABRT, old_sigabt);
	
	STK_destroy_stack(stack);
	return CDA_TRUE;
}

/*
 * test_pop_stack02
 */
#define ITEM_NUMBER	(18)
static TEST_RESULT_t test_pop_stack02(void)
{
	TEST_RESULT_t rcode = CDA_FALSE;
	int item = ITEM_NUMBER;
	int *pitem = &item;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	STK_push_item(stack, pitem);
	pitem = STK_pop_item(stack);
	if(*pitem == ITEM_NUMBER)
		rcode = CDA_TRUE;
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_peek_stack01
 */
static TEST_RESULT_t test_peek_stack01(void)
{
	TEST_RESULT_t rcode = CDA_FALSE;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	STK_peek_item(stack);
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_peek_stack02
 */
static TEST_RESULT_t test_peek_stack02(void)
{
	TEST_RESULT_t rcode = CDA_FALSE;
	int item = ITEM_NUMBER;
	int *pitem = &item;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	STK_push_item(stack, pitem);
	pitem = STK_peek_item(stack);
	if(
	   (*pitem == ITEM_NUMBER) &&
	   (STK_is_stack_full(stack))
	   )
		rcode = CDA_TRUE;
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_clear_stack01
 */
static TEST_RESULT_t test_clear_stack01(void)
{
	TEST_RESULT_t rcode = CDA_FALSE;
	int item = ITEM_NUMBER;
	int *pitem = &item;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	STK_push_item(stack, pitem);
	STK_clear_stack( stack );
	if(
	   (STK_is_stack_empty(stack))
	   )
		rcode = CDA_TRUE;
	STK_destroy_stack(stack);
	return rcode;
}

/*
 * test_destroy_stack01
 */
static TEST_RESULT_t test_destroy_stack01(void)
{
	TEST_RESULT_t rcode = CDA_FALSE;
	int item = ITEM_NUMBER;
	int *pitem = &item;
	STK_ID_t stack = STK_create_stack( STACK_SIZE );
	STK_push_item(stack, pitem);
	stack = STK_destroy_stack( stack );
	if(
	   (stack == STK_NULL_ID)
	   )
		rcode = CDA_TRUE;
	return rcode;
}
