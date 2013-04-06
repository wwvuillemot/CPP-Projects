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

/****************************************************************************
* MACROS
****************************************************************************/

/****************************************************************************
* TYPEDEF
****************************************************************************/
typedef int CHECK_PROC_t( void );

/****************************************************************************
* PROTOTYPES
****************************************************************************/
CHECK_PROC_t STK_check;
CHECK_PROC_t SRT_check;

/****************************************************************************
* MAIN
****************************************************************************/
int main () 
{

	STK_check();
	SRT_check();

	return 0;
}