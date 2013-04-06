/****************************************************************************
*	NAME
*		SRT
*	DESCRIPTION
*		module SRT (SORT) source file.  
*	AUTHOR
*		Ward W. Vuillemot <wwv@mac.com>
*	CURATOR
*		Ward W. Vuillemot <wwv@mac.com>
*	REVISION
*		1
*	DATE CREATED
*		24 July 2005
*	DATE MODIFIED
*		25 July 2005
*	HISTORY
*		1
*		25 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		_ SRT_poly_mergesort(); corrected incorrect encapsulation of while
*		  loops resulting in premature termination of mergesort
*			
*		0
*		24 July 2005
*		Ward W. Vuillemot <wwv@mac.com>
*		- original
****************************************************************************/
/****************************************************************************
* INCLUDES
****************************************************************************/
#include <srtp.h>
#include <stk.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define MAX_STACK_SIZE	(1024)

/****************************************************************************
* SUBROUTINES
*
*	NOTES
*		see srt.h for subroutine API and notes
****************************************************************************/
/****************************************************************************
* SUBROUTINE SRT_mergesort
****************************************************************************/
void SRT_mergesort(
				   void					*array,
				   size_t				num_elements,
				   size_t				element_size,
				   SRT_CMP_PROC_p_t		cmp_proc
				   )
{
	CDA_ASSERT(element_size > 0);
	
	if( num_elements > 1)
	{
		SRT__BYTE_t *tempArray = CDA_malloc( num_elements * element_size);
		
		size_t lowerHalf = num_elements / 2;
		size_t upperHalf = num_elements - lowerHalf;
		
		SRT__BYTE_t *array1 = array;
		SRT__BYTE_t *array2 = array1 + lowerHalf * element_size;
		
		SRT_mergesort( array, lowerHalf, element_size, cmp_proc);
		SRT_mergesort( array2, upperHalf, element_size, cmp_proc);
		
		{
			int inx = 0;
			int jnx = 0;
			int knx = 0;
			while( 
				   (inx < (int) lowerHalf) &&
				   (jnx < (int) upperHalf)
				   )
			{
				if(
				   cmp_proc(
							array1 + inx * element_size,
							array2 + jnx * element_size) < SRT_EQUALTO
				   )
				{
					memcpy(
						   tempArray + knx * element_size,
						   array1 + inx * element_size,
						   element_size
						   );
					inx++;
					knx++;
				}
				else
				{
					memcpy(
						   tempArray + knx * element_size,
						   array2 + jnx * element_size,
						   element_size
						   );
					jnx++;
					knx++;			
				}
				
			}
			
			while( inx < (int) lowerHalf)
			{
				memcpy(
					   tempArray + knx * element_size,
					   array1 + inx * element_size,
					   element_size
					   );
				inx++;
				knx++;
			}		
				
			while( jnx < (int) upperHalf)
			{
				memcpy(
					   tempArray + knx * element_size,
					   array2 + jnx * element_size,
					   element_size
					   );
				jnx++;
				knx++;			
			}
						
			for( inx = 0; inx < (int) num_elements; ++inx)
				memcpy(
					   array1 + inx * element_size,
					   tempArray + inx * element_size,
					   element_size
					   );
		}
		
		CDA_free(tempArray);
	}
}
/****************************************************************************
* SUBROUTINE SRT_poly_mergesort
****************************************************************************/
STK_ID_t stack = STK_NULL_ID;
void SRT_poly_mergesort(
						void				**array,
						size_t				num_elements,
						SRT_CMP_PROC_p_t	cmp_proc
						)
{
	if ( stack == STK_NULL_ID ) 
        stack = STK_create_stack( MAX_STACK_SIZE );
			
	if ( num_elements > 1 )
	{
		size_t lowerHalf = num_elements / 2;
		size_t upperHalf = num_elements - lowerHalf;
		
		void **array1 = array;
		void **array2 = array1 + lowerHalf;
		
		SRT_poly_mergesort( array1, lowerHalf, cmp_proc);
		SRT_poly_mergesort( (void **) array2, upperHalf, cmp_proc);
					
		{
			int inx = 0;		
			int jnx = 0; 
			while( 
				   (inx < (int) lowerHalf) &&
				   (jnx < (int) upperHalf)
				   )
			{
				if(
				   cmp_proc(
							array1[inx],
							array2[jnx]) < SRT_EQUALTO
				   )
				{
					STK_push_item( stack, array1[inx++]  );
				}
				else 
				{
					STK_push_item( stack, array2[jnx++] ); 				
				}
				
			}

			while ( inx < (int) lowerHalf ) 
				STK_push_item( stack, array1[inx++] );

			while ( jnx < (int) upperHalf ) 
				STK_push_item( stack, array2[jnx++] ); 
								
			inx = num_elements; 
			
			while ( inx > 0 )
				array[--inx] = STK_pop_item( stack ); 
		}
	}
}

