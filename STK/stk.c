/****************************************************************************
*	NAME
*		STK
*	DESCRIPTION
*		module STK (STACK) source file.  
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
#include <stkp.h>

/****************************************************************************
* MACROS
****************************************************************************/

/****************************************************************************
* SUBROUTINES
*
*	NOTES
*		see stk.h for subroutine API and notes
****************************************************************************/
STK_ID_t STK_create_stack( size_t size )
{
	STK__CONTROL_p_t stack = CDA_NEW( STK__CONTROL_t );
	
	stack->stack = CDA_calloc( size, sizeof(void *) );
	stack->sptr = stack->stack;
	stack->size = size;
	
	return (STK_ID_t) stack;
}

void STK_push_item( STK_ID_t stack, void *item )
{
	if(stack->sptr >= stack->stack + stack->size)
		abort();
	*stack->sptr++ = item;
}

 
void *STK_pop_item( STK_ID_t stack )
{
	void *rvalue = NULL;
	CDA_ASSERT( stack->sptr != stack->stack);	
	rvalue = *(--stack->sptr);
	return rvalue;
}

 
void *STK_peek_item( STK_ID_t stack )
{
	void *rvalue = NULL;
	CDA_ASSERT( stack->sptr != stack->stack);
	rvalue = *(stack->sptr - 1);
	return rvalue;
}

 
CDA_BOOL_t STK_is_stack_empty( STK_ID_t  stack)
{
	CDA_BOOL_t rcode = 
		stack->sptr == stack->stack ? CDA_TRUE : CDA_FALSE;
	return rcode;
}

 
CDA_BOOL_t STK_is_stack_full( STK_ID_t stack )
{
	CDA_BOOL_t rcode = 
		stack->sptr >= stack->stack + stack->size ? CDA_TRUE : CDA_FALSE;
	return rcode;
}


void STK_clear_stack( STK_ID_t stack )
{
	stack->sptr = stack->stack;
}

 
STK_ID_t STK_destroy_stack( STK_ID_t stack )
{
	CDA_free( stack->stack ); 
	CDA_free( stack );
	
	return STK_NULL_ID;
}

