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
#include <string.h>

#include <cda.h>
#include <testrig.h>
#include <srt.h>
#include <srtp.h>

#include <sort_check.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define STACK_SIZE	(1)

/****************************************************************************
* TYPEDEF
****************************************************************************/

/****************************************************************************
* PROTOTYPES
****************************************************************************/
static TEST_PROC_t test_sort01;
static TEST_PROC_t test_sort02;
static TEST_PROC_t test_sort03;
static TEST_PROC_t test_sort04;

extern int SRT_check(void);

/****************************************************************************
* MAIN
****************************************************************************/
extern int SRT_check () 
{
	TEST_p_t testrig_SRT;
	TEST_p_t testproc_SRT;
	
	TEST_PROC_p_t proc_sort01 = test_sort01;
	TEST_PROC_p_t proc_sort02 = test_sort02;
	TEST_PROC_p_t proc_sort03 = test_sort03;
	TEST_PROC_p_t proc_sort04 = test_sort04;
	
	/*
	 * CREATE TEST RIG
	 */
	testrig_SRT = TEST_createrig("SRT Test Rig");
	
	/*
	 * QUEUE TEST PROCS FOR USE WITH TEST RIG
	 */
	testproc_SRT = TEST_addproc(testrig_SRT, proc_sort01,    "SRT INT 01");
	testproc_SRT = TEST_addproc(testrig_SRT, proc_sort02,    "SRT DOUBLE 02");
	testproc_SRT = TEST_addproc(testrig_SRT, proc_sort03,    "SRT BIRTHDAY 03");
	testproc_SRT = TEST_addproc(testrig_SRT, proc_sort04,    "SRT POLY 04");
	
	/*
	 * RUN TEST RIG
	 */
	TEST_runrig(testrig_SRT);
	
	/*
	 * CLEAN UP
	 */
	TEST_destroyrig(testrig_SRT);
	
	return 0;
}

/****************************************************************************
* DRIVERS
****************************************************************************/
/*
 * proc_sort01
 */
#define TEST_TYPE int
#define TEST_PROC comp_int
static TEST_RESULT_t test_sort01(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	int inx;
	TEST_TYPE array[] = {
		5,
		3,
		2,
		15,
		-4,
		7,
		22,
		18,
		4,
		1
	};
	
	TEST_TYPE *qarray = CDA_malloc( sizeof(array) * sizeof(TEST_TYPE));
	
	memcpy( qarray, array, sizeof(array) * sizeof(TEST_TYPE));
	
	mergesort( qarray, sizeof(array)/sizeof(TEST_TYPE), sizeof(TEST_TYPE), TEST_PROC );
	SRT_mergesort( array, sizeof(array)/sizeof(TEST_TYPE), sizeof(TEST_TYPE), TEST_PROC );
	
	for(inx=0;  (unsigned) inx< (unsigned) sizeof(array)/sizeof(TEST_TYPE); inx++)
	{
		if(rcode && TEST_PROC(qarray+inx,array+inx) != SRT_EQUALTO)
			rcode = CDA_FALSE;
	}
		
	CDA_free(qarray);
	
	return rcode;
}
#undef TEST_TYPE
#undef TEST_PROC

#define TEST_TYPE double
#define TEST_PROC comp_real
static TEST_RESULT_t test_sort02(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	int inx;
	TEST_TYPE array[] = {
		5.0,
		3.2,
		2.4,
		4.4,
		1.0
	};
	
	TEST_TYPE *qarray = CDA_malloc( sizeof(array) * sizeof(TEST_TYPE));
	
	memcpy( qarray, array, sizeof(array) * sizeof(TEST_TYPE));
	
	mergesort( qarray, sizeof(array)/sizeof(TEST_TYPE), sizeof(TEST_TYPE), TEST_PROC );
	SRT_mergesort( array, sizeof(array)/sizeof(TEST_TYPE), sizeof(TEST_TYPE), TEST_PROC );
	
	for(inx=0; (unsigned) inx< (unsigned) sizeof(array)/sizeof(TEST_TYPE); inx++)
	{
		if(rcode && TEST_PROC(qarray+inx,array+inx) != SRT_EQUALTO)
			rcode = CDA_FALSE;
	}
	
	CDA_free(qarray);
	
	return rcode;
}
#undef TEST_TYPE
#undef TEST_PROC

#define TEST_TYPE MY_birth_t
#define TEST_PROC comp_birthday
static TEST_RESULT_t test_sort03(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	int inx;
	TEST_TYPE array[] = {
		{
			1964,
			9,
			10,
			"Renee"
		},
		{
			1973,
			12,
			18,
			"Ward"
		},
		{
			1937,
			9,
			28,
			"Dad"
		},
		{
			1973,
			6,
			19,
			"Phida"
		},
		{
			1961,
			3,
			28,
			"Laura"
		},
		{
			1939,
			7,
			1,
			"Mom"
		}
	};	
	
	TEST_TYPE qarray[] = {
	{
		1964,
		9,
		10,
		"Renee"
	},
	{
		1973,
		12,
		18,
		"Ward"
	},
	{
		1937,
		9,
		28,
		"Dad"
	},
	{
		1973,
		6,
		19,
		"Phida"
	},
	{
		1961,
		3,
		28,
		"Laura"
	},
	{
		1939,
		7,
		1,
		"Mom"
	}
	};		
	
	/*TEST_TYPE *qarray = CDA_malloc( sizeof(array) * sizeof(TEST_TYPE));
	
	memcpy( qarray, array, sizeof(array) * sizeof(TEST_TYPE));
	*/
	mergesort( qarray, sizeof(array)/sizeof(TEST_TYPE), sizeof(TEST_TYPE), TEST_PROC );
	SRT_mergesort( array, sizeof(array)/sizeof(TEST_TYPE), sizeof(TEST_TYPE), TEST_PROC );
	
	for(inx=0; (unsigned) inx< (unsigned) sizeof(array)/sizeof(TEST_TYPE); inx++)
	{
		if(rcode && TEST_PROC(qarray+inx,array+inx) != SRT_EQUALTO)
			rcode = CDA_FALSE;
	}
	
	/*CDA_free(qarray);
	*/
	return rcode;
}
#undef TEST_TYPE
#undef TEST_PROC

static TEST_RESULT_t test_sort04(void)
{
	TEST_RESULT_t rcode = CDA_TRUE;
	
	/* An array that may not be sorted with the new mergesort */ 
	int iarr[] = { 11, 15, 0, 5, 1, 7, 9 }; 
	
	/* Two arrays that may be sorted with the new mergesort */ 
	char *sarr[]  = { "ward", "dick", "sally", "jane", "spot" }; 
	int  *piarr[] = { &iarr[0], &iarr[1], &iarr[2], &iarr[3], &iarr[4], &iarr[5], &iarr[6] }; 

	SRT_poly_mergesort( (void**)sarr, CDA_CARD(sarr), comp_str );
	SRT_poly_mergesort( (void**)piarr, CDA_CARD(piarr), comp_int2 ); 
	
	return rcode;
}

/****************************************************************************
* COMPARE PROCS
****************************************************************************/

/*************************************************************************
* comp_str - compares two strings for the qsort and bsearch functions
* Input:
*      left : void pointer to an integer
*      right : void pointer to another integer
* Return:
*      0 : there equal
*     -1 : left < right
*      1 : left > right
************************************************************************/
int comp_str( const void * left, const void * right )
{
	char * lleft = (char *)left;
    char * lright = (char *)right;
	
	/* ---------------------------------------------
		* PROGRAMMER'S CATCHALL
		* --------------------------------------------- */
	assert(left);
	assert(right);
	
    return strcmp(lleft,lright);
}

/*************************************************************************
* comp_int2 - compares two integers for the qsort and bsearch functions
* Input:
*      left : void pointer to an integer
*      right : void pointer to another integer
* Return:
*      0 : there equal
*     -1 : left < right
*      1 : left > right
************************************************************************/
int comp_int2( const void * left, const void * right )
{
	int lleft = *(int *)left;
    int lright = *(int *)right;
	
	/* ---------------------------------------------
		* PROGRAMMER'S CATCHALL
		* --------------------------------------------- */
	assert(left);
	assert(right);
	
    return (lleft < lright) ? SRT_LESSTHAN : (lleft > lright) ? SRT_MORETHAN : SRT_EQUALTO;
}

/*************************************************************************
* comp_int - compares two integers for the qsort and bsearch functions
* Input:
*      left : void pointer to an integer
*      right : void pointer to another integer
* Return:
*      0 : there equal
*     -1 : left < right
*      1 : left > right
************************************************************************/
int comp_int( const void * left, const void * right )
{
	int lleft = *(int *)left;
    int lright = *(int *)right;
	
	/* ---------------------------------------------
		* PROGRAMMER'S CATCHALL
		* --------------------------------------------- */
	assert(left);
	assert(right);

    return (lleft < lright) ? SRT_LESSTHAN : (lleft > lright) ? SRT_MORETHAN : SRT_EQUALTO;
}

/*************************************************************************
* comp_real - compares two reals for the qsort and bsearch functions
* Input:
*      left : void pointer to a real
*      right : void pointer to another real
* Return:
*      0 : there equal
*     -1 : left < right
*      1 : left > right
************************************************************************/
int comp_real( const void * left, const void * right )
{
	double lleft = *(double *)left;
    double lright = *(double *)right;
	
	/* ---------------------------------------------
		* PROGRAMMER'S CATCHALL
		* --------------------------------------------- */
	assert(left);
	assert(right);
	
    return (lleft < lright) ? SRT_LESSTHAN : (lleft > lright) ? SRT_MORETHAN : SRT_EQUALTO;
}

/*************************************************************************
* comp_birthday - compares two birthdays for the qsort and bsearch functions
* Input:
*      left : void pointer to a birthday
*      right : void pointer to another birthday
* Return:
*      0 : there equal
*     -1 : left < right
*      1 : left > right
************************************************************************/
int comp_birthday( const void * left, const void * right )
{
	MY_birth_year_t l_year =  ((MY_birth_t *) left)->year;
    MY_birth_year_t r_year = ((MY_birth_t *) right)->year;
	
	MY_birth_month_t l_month =  ((MY_birth_t *) left)->month;
    MY_birth_month_t r_month = ((MY_birth_t *) right)->month;
	
	MY_birth_day_t l_day =  ((MY_birth_t *) left)->day;
    MY_birth_day_t r_day = ((MY_birth_t *) right)->day;
	
	int comp_value;
	
	/* ---------------------------------------------
		* PROGRAMMER'S CATCHALL
		* --------------------------------------------- */
	assert(left);
	assert(right);
	
    if(l_year < r_year)
	{
		comp_value = -1;
	}
	else if(l_year > r_year)
	{
		comp_value = 1;
	}
	else
	{
		if(l_month < r_month)
		{
			comp_value = -1;
		}
		else if(l_month > r_month)
		{
			comp_value = 1;
		}
		else
		{
		    if(l_day < r_day)
			{
				comp_value = -1;
			}
			else if(l_day > r_day)
			{
				comp_value = 1;
			}
			else
			{
				comp_value = 0;
			}	
		}
		
	}
	return comp_value;
}
