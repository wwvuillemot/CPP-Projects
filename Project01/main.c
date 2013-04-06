/****************************************************************************
*	NAME
*		PROJECT01 TEST DRIVER
*	DESCRIPTION
*		Test driver for Project 01, C Data Structures & Algorithms
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		0
*	DATE CREATED
*		29 June 2005
*	DATE MODIFIED
*		02 July 2005
*	HISTORY
*		1
*		02 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- rewrote completely to use testrig module
*
*		0
*		29 June 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/

/****************************************************************************
* INCLUDES
****************************************************************************/
#include <limits.h>
#include <stdio.h>

#include <cda.h>
#include <testrig.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define ARR_CARD	(1000)

/****************************************************************************
* PROTOTYPES
****************************************************************************/
TEST_PROC_t test_booleen_size;
TEST_PROC_t test_booleen_true;
TEST_PROC_t test_booleen_false;
TEST_PROC_t test_cardinality;
TEST_PROC_t test_string;
TEST_PROC_t test_assert;
TEST_PROC_t test_int8_size;
TEST_PROC_t test_int8_sign;
TEST_PROC_t test_uint8_size;
TEST_PROC_t test_uint8_sign;
TEST_PROC_t test_int16_size;
TEST_PROC_t test_int16_sign;
TEST_PROC_t test_uint16_size;
TEST_PROC_t test_uint16_sign;
TEST_PROC_t test_int32_size;
TEST_PROC_t test_int32_sign;
TEST_PROC_t test_uint32_size;
TEST_PROC_t test_uint32_sign;
TEST_PROC_t test_malloc;
TEST_PROC_t test_realloc;
TEST_PROC_t test_calloc;

/****************************************************************************
* MAIN
****************************************************************************/
int main () 
{

	TEST_p_t testrig_CDA;
	TEST_p_t testproc_CDA;
	
	TEST_PROC_p_t test_proc_booleen_size =	test_booleen_size;
	TEST_PROC_p_t test_proc_booleen_true =	test_booleen_true;
	TEST_PROC_p_t test_proc_booleen_false = test_booleen_false;
	
	TEST_PROC_p_t test_proc_cardinality =	test_cardinality;
	TEST_PROC_p_t test_proc_string =		test_string;
	TEST_PROC_p_t test_proc_assert =		test_assert;
	
	TEST_PROC_p_t test_proc_int8_size =		test_int8_size;
	TEST_PROC_p_t test_proc_int8_sign =		test_int8_sign;
	TEST_PROC_p_t test_proc_uint8_size =	test_uint8_size;
	TEST_PROC_p_t test_proc_uint8_sign =	test_uint8_sign;
	
	TEST_PROC_p_t test_proc_int16_size =	test_int16_size;
	TEST_PROC_p_t test_proc_int16_sign =	test_int16_sign;
	TEST_PROC_p_t test_proc_uint16_size =	test_uint16_size;
	TEST_PROC_p_t test_proc_uint16_sign =	test_uint16_sign;
	
	TEST_PROC_p_t test_proc_int32_size =	test_int32_size;
	TEST_PROC_p_t test_proc_int32_sign =	test_int32_sign;
	TEST_PROC_p_t test_proc_uint32_size =	test_uint32_size;
	TEST_PROC_p_t test_proc_uint32_sign =	test_uint32_sign;	
	
	TEST_PROC_p_t test_proc_malloc =		test_malloc;
	TEST_PROC_p_t test_proc_realloc =		test_realloc;
	TEST_PROC_p_t test_proc_calloc =		test_calloc;	
	
	/*
	 * CREATE TEST RIG
	 */
	testrig_CDA = TEST_createrig("CDA Test Rig");
	
	/*
	 * QUEUE TEST PROCS FOR USE WITH TEST RIG
	 */
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_booleen_size, "CDA_BOOLEEN");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_booleen_true, "CDA_TRUE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_booleen_false, "CDA_FALSE");
	
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_cardinality, "CDA_CARD");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_string, "CDA_STRING");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_assert, "CDA_ASSERT");

	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_int8_size, "CDA_INT8 SIZE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_int8_sign, "CDA_INT8 SIGN");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_uint8_size, "CDA_UINT8 SIZE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_uint8_sign, "CDA_UNIT8 SIGN");

	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_int16_size, "CDA_INT16 SIZE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_int16_sign, "CDA_INT16 SIGN");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_uint16_size, "CDA_UINT16 SIZE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_uint16_sign, "CDA_UNIT16 SIGN");
	
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_int32_size, "CDA_INT32 SIZE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_int32_sign, "CDA_INT32 SIGN");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_uint32_size, "CDA_UINT32 SIZE");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_uint32_sign, "CDA_UNIT32 SIGN");

	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_malloc, "CDA_MALLOC");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_realloc, "CDA_REALLOC");
	testproc_CDA = TEST_addproc(testrig_CDA, test_proc_calloc, "CDA_CALLOC");
	
	/*
	 * RUN TEST RIG
	 */
	TEST_runrig(testrig_CDA);
	
	/*
	 * CLEAN UP
	 */
	TEST_destroyrig(testrig_CDA);

	return 0;
}

/****************************************************************************
* DRIVERS
****************************************************************************/

/*
 * BOOLEEN
 */

/*
 * CDA_BOOL_t
 */
TEST_RESULT_t test_booleen_size(void)
{
	CDA_BOOL_t		bool_Me = 0;
	return (sizeof(bool_Me) == 4 ? TEST_PASS : TEST_FAIL );
}

/*
 * CDA_TRUE
 */
TEST_RESULT_t test_booleen_true(void)
{
	return (CDA_TRUE == 1 ? TEST_PASS : TEST_FAIL);
}

/*
 * CDA_FALSE
 */	
TEST_RESULT_t test_booleen_false(void)
{	
	return (CDA_FALSE == 0 ? TEST_PASS : TEST_FAIL);
}

/*
 * MISCELLANEOUS
 */

/*
 * CDA_CARD
 */
TEST_RESULT_t test_cardinality(void)
{
	int array[ARR_CARD];
	return (CDA_CARD(array) == ARR_CARD ? TEST_PASS : TEST_FAIL);
}

/*
 * CDA_NEW_STR_IF
 */
TEST_RESULT_t test_string(void)
{
	char * strText = "This is a string I want to copy.";
	char * strNew;
	strNew = CDA_NEW_STR_IF(strText);
	return (!strcmp(strText,strNew) ? TEST_PASS : TEST_FAIL);
}
	
/*
 * CDA_ASSERT
 */
TEST_RESULT_t test_assert(void)
{
	CDA_ASSERT(ARR_CARD > 0);
	return TEST_PASS;
}	

/*
 * TYPEDEFS
 */

/*
 * CDA_INT8_t
 */
TEST_RESULT_t test_int8_size(void)
{
	CDA_INT8_t		int8_Me = 0;
	return (sizeof(int8_Me) == 1 ? TEST_PASS : TEST_FAIL);
}
TEST_RESULT_t test_int8_sign(void)
{
	CDA_INT8_t		int8_Me = 0;
	return ((int8_Me - 1) == -1 ? TEST_PASS : TEST_FAIL);
}

/*
 * CDA_UINT8_t
 */
TEST_RESULT_t test_uint8_size(void)
{
	CDA_UINT8_t		uint8_Me = 0;
	return (sizeof(uint8_Me) == 1 ? TEST_PASS : TEST_FAIL);
}
TEST_RESULT_t test_uint8_sign(void)
{
	CDA_UINT8_t		uint8_Me = 0;
	return ((uint8_Me - 1) == -1 ? TEST_PASS : TEST_FAIL);
}

/*
 * CDA_INT16_t
 */
TEST_RESULT_t test_int16_size(void)
{
	CDA_INT16_t		int16_Me = 0;
	return (sizeof(int16_Me) == 2 ? TEST_PASS : TEST_FAIL);
}
TEST_RESULT_t test_int16_sign(void)
{
	CDA_INT16_t		int16_Me = 0;
	return ((int16_Me - 1) == -1 ? TEST_PASS : TEST_FAIL);
}

/*
 * CDA_UINT16_t
 */
TEST_RESULT_t test_uint16_size(void)
{
	CDA_UINT16_t	uint16_Me = 0;
	return (sizeof(uint16_Me) == 2 ? TEST_PASS : TEST_FAIL);
}
TEST_RESULT_t test_uint16_sign(void)
{
	CDA_UINT16_t	uint16_Me = 0;
	return ((uint16_Me - 1) == -1 ? TEST_PASS : TEST_FAIL);
}	

/*
 * CDA_INT32_t
 */
TEST_RESULT_t test_int32_size(void)
{
	CDA_INT32_t		int32_Me = 0;
	return (sizeof(int32_Me) == 4 ? TEST_PASS : TEST_FAIL);
}
TEST_RESULT_t test_int32_sign(void)
{
	CDA_INT32_t		int32_Me = 0;
	return ((int32_Me - 1) == -1 ? TEST_PASS : TEST_FAIL);
}

/*
 * CDA_UINT32_t
 */
TEST_RESULT_t test_uint32_size(void)
{
	CDA_UINT32_t	uint32_Me = 0;
	return (sizeof(uint32_Me) == 4 ? TEST_PASS : TEST_FAIL);
}
TEST_RESULT_t test_uint32_sign(void)
{
	CDA_UINT32_t	uint32_Me = 0;
	return ((uint32_Me - 1) == -1 ? TEST_PASS : TEST_FAIL);
}
	
/*
 * DYNAMIC MEMORY
 */

/*
 * CDA_malloc
 */
TEST_RESULT_t test_malloc(void)
{
	TEST_RESULT_t rcode;
	int *pInt;
	int iInt = 3;
	pInt = CDA_NEW(int);
	*pInt = iInt;
	rcode = ((*pInt - iInt) == 0 ? TEST_PASS : TEST_FAIL);
	CDA_free(pInt);
	return rcode;
}

/*
 * CDA_realloc
 */
TEST_RESULT_t test_realloc(void)
{
	TEST_RESULT_t rcode;
	int *pInt;
	int *ppInt;
	int iInt = 3;
	pInt = CDA_NEW(int);
	*pInt = iInt;
	ppInt = CDA_realloc(pInt,sizeof(int));
	rcode = ((*ppInt - iInt) == 0 ? TEST_PASS : TEST_FAIL);
	CDA_free(pInt);
	if(pInt != ppInt)
		CDA_free(ppInt);
	return rcode;
}
		
/*
 * CDA_calloc
 */
TEST_RESULT_t test_calloc(void)
{
	int *array;
	int i;
	int iCorrect = 0;
	
	array = CDA_calloc(ARR_CARD, sizeof(int));
	for(i = 0; i < ARR_CARD; i++)
		iCorrect = iCorrect + (array[i] == 0 ? 1 : 0);
	CDA_free(array);
	
	return (iCorrect == ARR_CARD ? TEST_PASS : TEST_FAIL);
}