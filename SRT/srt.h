#ifndef SRT_H     /* begin include sandwich          */
#define SRT_H     /* second line of include sandwich */
/****************************************************************************
*	NAME
*		SRT.H
*	DESCRIPTION
*		C DATA structures and ALGORITHMS header file.
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
#include <stdlib.h>
#include <cda.h>

/****************************************************************************
* MACROS
****************************************************************************/
#define SRT_LESSTHAN	(-1)
#define SRT_EQUALTO		(0)
#define SRT_MORETHAN	(1)

/****************************************************************************
* STRUCTURES
****************************************************************************/

/****************************************************************************
* TYPEDEFS
****************************************************************************/
/****************************************************************************
* NAME
*	SRT_CMP_PROC_t
* DESCRIPTION
*	typedef for callback proc used with:
*		- SRT_mergesort(); and,
*		- SRT_poly_mergesort()
* NOTES
*	The caller is responible for their proc of type, SRT_CMP_PROC_t to follow
*	ANSI/ISO conventions for comparison procs.  As convenience the caller can
*	have their proc of type SRT_CMP_PROC_t return:
*		- SRT_LESSTHAN	if	data1	<	data2
*		- SRT_EQUALTO	if	data1	==	data2
*		- SRT_MORETHAN	if	data1	>	data2
****************************************************************************/
typedef int SRT_CMP_PROC_t(
	const void *data1, 
	const void *data2
);
typedef SRT_CMP_PROC_t *SRT_CMP_PROC_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
/****************************************************************************
*	NAME
*		SRT_mergesort
*	DESCRIPTION
*		sorts an array using mergesort algorithm
*	ARGUMENTS
*		- array :: pointer to array
*		- num_elements :: number of elements of passed array
*		- element size :: size of array element in BYTES
*		- cmp_proc :: pointer to function of type SRT_CMP_PROC_t that
*		  compares to elements from passed array
*	RETURN
*		void
*	NOTES
*		- see TYPEDEF SRT_CMP_PROC_t for notes
****************************************************************************/
void SRT_mergesort(
				   void					*array,
				   size_t				num_elements,
				   size_t				element_size,
				   SRT_CMP_PROC_p_t		cmp_proc
				   );

/****************************************************************************
*	NAME
*		SRT_mergesort
*	DESCRIPTION
*		sorts an array using mergesort algorithm
*	ARGUMENTS
*		- array :: pointer to a pointer to array
*		- num_elements :: number of elements of passed array
*		- cmp_proc :: pointer to function of type SRT_CMP_PROC_t that
*		  compares to elements from passed array
*	RETURN
*		void
*	NOTES
*		- see TYPEDEF SRT_CMP_PROC_t for notes
****************************************************************************/
void SRT_poly_mergesort(
						void				**array,
						size_t				num_elements,
						SRT_CMP_PROC_p_t	cmp_proc
						);
				
#endif            /* end include sandwich            */
