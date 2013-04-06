/****************************************************************************
*	NAME
*		TESTRIG
*	DESCRIPTION
*		Module for test driver rigs; used to test other modules in a 
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
#include <testrig.h>
#include <testrigp.h>

/****************************************************************************
*	NAME
*		TEST_createrig
*	DESCRIPTION
*		creates a new test rig
****************************************************************************/
TEST_p_t TEST_createrig(const char *name)
{
	TEST_p_t rig_p = malloc(sizeof(TEST_p_t));
	if (rig_p == NULL)
		abort();
	
	rig_p->name = TEST_NEW_STR_IF(name);
	
	rig_p->pnext = NULL;
	
	rig_p->test_proc = NULL;
	
	return rig_p;
}

/****************************************************************************
*	NAME
*		TEST_addproc
*	DESCRIPTION
*		add a test proc with a test rig
****************************************************************************/
TEST_p_t TEST_addproc(TEST_p_t rig_p, TEST_PROC_p_t test_proc_p, const char *name)
{
	TEST_p_t proc_p;
	TEST_p_t lastproc_p = rig_p;
	
	assert(rig_p);
	assert(test_proc_p);
	
	proc_p = TEST_createrig(name);
	proc_p->test_proc = test_proc_p;
	
	while(lastproc_p->pnext != NULL)
		lastproc_p = lastproc_p->pnext;
	
	lastproc_p->pnext = proc_p;
	
	return proc_p;
}

/****************************************************************************
*	NAME
*		TEST_runrig
*	DESCRIPTION
*		runs all the registered test procs for a given test rig
****************************************************************************/
void TEST_runrig(TEST_p_t rig_p)
{
	int intTestsTotal = 0;
	int intTestsPassed = 0;
	
	TEST_p_t proc_p = rig_p->pnext;
	
	if(proc_p == NULL)
		return;
	
	printf("Starting test rig %s\n",rig_p->name);
		
	while(
		(proc_p != NULL) && 
		(proc_p->test_proc != NULL)
	)
	{
		TEST_RESULT_t result = proc_p->test_proc();
		intTestsTotal++;
		
		if(result == TEST_PASS)
		{
			printf("\t  PASSED   test %s\n",proc_p->name);
			intTestsPassed++;
		}
		else
		{
			printf("\t>>FAILED<< test %s\n",proc_p->name);
			
		}
		
		proc_p = proc_p->pnext;		
	}
		
	printf("Ending test rig %s\n",rig_p->name);
	printf("%d of %d passed rig %s\n",intTestsPassed,intTestsTotal,rig_p->name);
}

/****************************************************************************
*	NAME
*		TEST_destroyrig
*	DESCRIPTION
*		destroys all the registered test procs for a given test rig and the
*		rig itself
****************************************************************************/
void TEST_destroyrig(TEST_p_t rig_p)
{
	TEST_p_t nextrig_p = rig_p;
	
	assert(rig_p);
	
	while(nextrig_p != NULL) 
	{
		rig_p = nextrig_p;
		nextrig_p = rig_p->pnext;
		if(rig_p->name != NULL)
			free(rig_p->name);
		if(rig_p != NULL)
			free(rig_p);
	}
	
}