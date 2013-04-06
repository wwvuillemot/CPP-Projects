#ifndef STK_H     /* begin include sandwich          */
#define STK_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		STK.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.  This file will contain
*		all support related with C Programming : Data Structures and 
*		Algorithms, J. Straub
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
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stddef.h>
#include <cda.h>

/****************************************************************************
* MACROS
****************************************************************************/
/****************************************************************************
*	NAME
*		STK_NULL_ID
*	DESCRIPTION
*		default value for an empty stack
****************************************************************************/
#define STK_NULL_ID (NULL)

/****************************************************************************
* STRUCTURES
****************************************************************************/

/****************************************************************************
* TYPEDEFS
****************************************************************************/
/****************************************************************************
*	NAME
*		stk__control_s
*	DESCRIPTION
*		stack structure
****************************************************************************/
typedef struct stk__control_s *STK_ID_t; 

/****************************************************************************
* PROTOTYPES
****************************************************************************/
/****************************************************************************
*	SYNOPSIS 
*		STK_ID_t STK_create_stack( size_t size ); 
*	WHERE 
*		size == size of the stack in items 
*	EXCEPTIONS 
*		Throws SIGABRT on create failure 
*	RETURNS 
*		stack ID to be used in all subsequent stack operations 
*	NOTES 
*		None 
****************************************************************************/
STK_ID_t STK_create_stack( size_t size );

/****************************************************************************
*	SYNOPSIS 
*		void STK_push_item( STK_ID_t stack, void *item ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*		item  == item to push 
*	EXCEPTIONS 
*		Throws SIGABRT on stack overflow 
*	RETURNS 
*		void 
*	NOTES 
*		None
****************************************************************************/
void STK_push_item( STK_ID_t stack, void *item ); 

/****************************************************************************
*	SYNOPSIS 
*		void *STK_pop_item( STK_ID_t stack ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*	EXCEPTIONS 
*		See notes 
*	RETURNS 
*		Top item of stack 
*	NOTES 
*		This method contains an assertion which will throw SIGABRT if 
*		the user attempts to illegally remove an item from an empty 
*		stack.  The assertion is disabled in production code. 
****************************************************************************/
void *STK_pop_item( STK_ID_t stack ); 

/****************************************************************************
*	SYNOPSIS 
*		void *STK_peek_item( STK_ID_t stack ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*	EXCEPTIONS 
*		See notes 
*	RETURNS 
*		The value at the top of the stack 
*	NOTES 
*		This method contains and assertion which will throw SIGABRT if 
*		the user attempts to illegally get an item from an empty 
*		stack.  The assertion is disabled in production code. 
****************************************************************************/
void *STK_peek_item( STK_ID_t stack ); 

/****************************************************************************
*	SYNOPSIS 
*		CDA_BOOL_t STK_is_stack_empty( STK_ID_t stack ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*	EXCEPTIONS 
*		None 
*	RETURNS 
*		CDA_TRUE if stack is empty, 
*		CDA_FALSE otherwise 
*	NOTES 
*		None 
****************************************************************************/
CDA_BOOL_t STK_is_stack_empty( STK_ID_t stack ); 

/****************************************************************************
*	SYNOPSIS 
*		CDA_BOOL_t STK_is_stack_full( STK_ID_t stack ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*	EXCEPTIONS 
*		None 
*	RETURNS 
*		CDA_TRUE if stack is full, 
*		CDA_FALSE otherwise 
*	NOTES 
*		None 
****************************************************************************/
CDA_BOOL_t STK_is_stack_full( STK_ID_t stack );

/****************************************************************************
*	SYNOPSIS 
*		void STK_clear_stack( STK_ID_t stack ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*	EXCEPTIONS 
*		None 
*	RETURNS 
*		void 
*	NOTES 
*		None 
****************************************************************************/
void STK_clear_stack( STK_ID_t stack ); 

/****************************************************************************
*	SYNOPSIS 
*		STK_ID_t STK_destroy_stack( STK_ID_t stack ); 
*	WHERE 
*		stack == stack id returned by STK_create_stack 
*	EXCEPTIONS 
*		None 
*	RETURNS 
*		STK_NULL_ID 
*	NOTES 
*		None 
****************************************************************************/
STK_ID_t STK_destroy_stack( STK_ID_t stack ); 

#endif            /* end include sandwich            */
