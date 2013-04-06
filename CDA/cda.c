/****************************************************************************
 *	NAME
 *		CDA
 *	DESCRIPTION
 *		C DATA structures and ALGORITHMS source file.
 *	AUTHOR
 *		Ward W. Vuillemot <wwv@mac.com>
 *	CURATOR
 *		Ward W. Vuillemot <wwv@mac.com>
 *	REVISION
 *		1
 *	DATE CREATED
 *		29 June 2005
 *	DATE MODIFIED
 *		02 July 2005
 *	HISTORY
 *		1
 *		02 July 2005
 *		Ward W. Vuillemot <wwv@mac.com>
 *		- modified CDA_calloc; corrected logic to only abort() if both size
 *		  and number of elements are not 0 and calloc() fails
 *
 *		0
 *		29 June 2005
 *		Ward W. Vuillemot <wwv@mac.com>
 *		- original
 ****************************************************************************/
#include <cda.h>
#include <cdap.h>

/****************************************************************************
 *	NAME
 *		CDA_malloc
 *	DESCRIPTION
 *		allocates dynamic memory from the heap using ISO malloc() by passing
 *		the size of the memory (in bytes). returns a void pointer to the 
 *		newly allocated memory, otherwise NULL if size is 0.
 *	CAUTION
 *		Will abort() if size is not 0 and unable to fulfill request. 
 *	NOTES
 *		see ISO for details on realloc()
 ****************************************************************************/
void *CDA_malloc(
	size_t size
)
{
	void *mem = malloc( size );

	if ( (mem == NULL) && (size > 0) )
		abort();

	return mem;
}
/****************************************************************************
 *	NAME
 *		CDA_calloc
 *	DESCRIPTION
 *		allocates dynamic memory from the heap using ISO calloc() by passing
 *		the number of elements and size of each element in terms of memory 
 *		(in bytes). returns a void pointer to the newly allocated memory, 
 *		otherwise NULL if elt_count or elt_size are 0. 
 *	CAUTION
 *		Will abort() if elt_count and elt_size are not 0 and unable to fulfill 
 *		request. 
 *	NOTES
 *		see ISO for details on calloc()
 ****************************************************************************/
void *CDA_calloc(
	size_t elt_count,
	size_t elt_size
)
{
	void *mem = calloc( elt_count, elt_size );

	if ( (mem == NULL) && (
						 (elt_size > 0) && 
						 (elt_count > 0)
						 )
	)
		abort();

	return mem;
}
/****************************************************************************
 *	NAME
 *		CDA_realloc
 *	DESCRIPTION
 *		allocates dynamic memory from the heap using ISO realloc() by passing
 *		the original pointer and the requested size of the new memory (in 
 *		bytes). returns a void pointer to the newly allocated memory, otherwise
 *		NULL if size is 0.
 *	CAUTION
 *		Will abort() if size is not 0 and unable to fulfill request.
 *	NOTES
 *		see ISO for details on realloc()
 ****************************************************************************/
void *CDA_realloc(
	void *ptr,			/* pointer to memory to be (re)allocated */
	size_t size			/* size of memory (bytes) to be (re)allocated) */
)
{
	void *mem = realloc( ptr, size );
	
	if ( (mem == NULL) && (size > 0) )
		abort();
	
	return mem;
}
/****************************************************************************
 *	NAME
 *		CDA_free
 *	DESCRIPTION
 *		frees dynamically allocated memory created using CDA_malloc(), 
 *		CDA_realloc(), or CDA_calloc()
 *	NOTES
 *		see ISO for details on free()
 ****************************************************************************/
void CDA_free(
	void *ptr
)
{
	if ( ptr != NULL )
		free( ptr );
}
