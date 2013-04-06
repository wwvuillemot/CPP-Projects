#ifndef CDA_H     /* begin include sandwich          */
#define CDA_H     /* second line of include sandwich */
/****************************************************************************
 *	NAME
 *		CDA.H
 *	DESCRIPTION
 *		C DATA structures and ALGORITHMS header file.
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
 *		- removed unused library headers and redundant library headers
 *
 *		0
 *		29 June 2005
 *		Ward W. Vuillemot <wwv@mac.com>
 *		- original
 ****************************************************************************/

/****************************************************************************
* INCLUDES
****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/****************************************************************************
 * MACROS
 ****************************************************************************/
/*
 * BOOLEENS
 */
#define CDA_TRUE	(1)
#define CDA_FALSE	(0)
/*
 * CARDINALITY OF ARRAY
 */
#define CDA_CARD( arr )	\
	(sizeof((arr))/sizeof(*(arr)))
/*
 * INSTANTIATE A NEW INSTANCE OF AN OBJECT
 */
#define CDA_NEW( type ) \
        ((type *)CDA_malloc( sizeof(type) ))
/*
 * ASSERT WRAPPER
 */
#define CDA_ASSERT( exp ) \
		(assert( (exp) ))
/*
 * COPY NEW STRING
 */
#define CDA_NEW_STR( str )    \
    (strcpy( (char *)CDA_malloc( strlen( (str) ) + 1 ), (str) ))
#define CDA_NEW_STR_IF( str ) \
    ((str) == NULL ? NULL : CDA_NEW_STR( (str) ))

/****************************************************************************
 * STRUCTURES
 ****************************************************************************/

/****************************************************************************
 * TYPEDEFS
 ****************************************************************************/
typedef int             CDA_BOOL_t;

typedef signed char     CDA_INT8_t;
typedef unsigned char   CDA_UINT8_t;

typedef signed short    CDA_INT16_t;
typedef unsigned short  CDA_UINT16_t;

typedef signed long     CDA_INT32_t;
typedef unsigned long   CDA_UINT32_t;
	
/****************************************************************************
 * PROTOTYPES
 ****************************************************************************/
void *CDA_malloc(size_t size);
void *CDA_calloc(size_t elt_count, size_t elt_size);
void *CDA_realloc(void *ptr, size_t size);
void CDA_free(void *ptr);

#endif            /* end include sandwich            */
