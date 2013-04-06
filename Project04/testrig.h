#ifndef TESTRIG_H     /* begin include sandwich          */
#define TESTRIG_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		TESTRIG.H
*	DESCRIPTION
*		Header for test driver rigs; used to test other modules in a 
*		standardized manner
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
#include <stdio.h>
#include <string.h>
#include <assert.h>

/****************************************************************************
* MACROS
****************************************************************************/
/*
 * TEST PASS, FAIL
 */
#define TEST_PASS	(1)
#define TEST_FAIL	(0)
/*
* COPY NEW STRING
 */
#define TEST_NEW_STR( str )    \
(strcpy( (char *)malloc( strlen( (str) ) + 1 ), (str) ))
#define TEST_NEW_STR_IF( str ) \
((str) == NULL ? NULL : TEST_NEW_STR( (str) ))

/****************************************************************************
* STRUCTURES
****************************************************************************/

/****************************************************************************
* TYPEDEFS
****************************************************************************/
/*
 * test subroutine typedef prototype
 */
typedef int TEST_RESULT_t;
typedef TEST_RESULT_t TEST_PROC_t(void);
typedef TEST_PROC_t *TEST_PROC_p_t;
typedef struct test_s
{
	struct test_s *pnext;
	char *name;
	TEST_PROC_p_t test_proc;
} TEST_t, *TEST_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
TEST_p_t TEST_createrig(const char *);
TEST_p_t TEST_addproc(TEST_p_t, TEST_PROC_p_t, const char *);
void TEST_runrig(TEST_p_t);
void TEST_destroyrig(TEST_p_t);

#endif            /* end include sandwich            */
