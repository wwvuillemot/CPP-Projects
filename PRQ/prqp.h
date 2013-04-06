#ifndef PRQP_H    /* begin include sandwich          */
#define PRQP_H    /* second line of include sandwich */
/****************************************************************************
*	NAME
*		PRQP.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.
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
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <prq.h>  /* include public header file      */

/****************************************************************************
* MACROS
****************************************************************************/
/****************************************************************************
* Synopsis: 
*		PRQ__IF_PRIORITY( CDA_UINT32_t pri, CDA_UINT32_t max ); 
* Where: 
*		pri == priority
*		max == maximum allowable priority for queue
* Returns: 
*		None
* Exceptions: 
*		SIGABRT if pri > max OR pri < 0
* Notes: 
*		None 
***************************************************************************/
#define PRQ__IF_PRIORITY(pri,max)  \
	if( ((pri) > (max)) || ((pri) < 0) ) abort()

/****************************************************************************
* STRUCTURES
****************************************************************************/
typedef struct PRQ__control_s
{
	ENQ_ANCHOR_p_t	*anchors;
	CDA_UINT32_t	max_priority;
} PRQ__CONTROL_t, *PRQ__CONTROL_p_t;

/****************************************************************************
* TYPEDEFS
****************************************************************************/
typedef unsigned char PRQ__BYTE_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/

#endif            /* end include sandwich            */
