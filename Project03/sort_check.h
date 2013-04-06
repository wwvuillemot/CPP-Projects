#ifndef SORT_CHECK_H     /* begin include sandwich          */
#define SORT_CHECK_H     /* second line of include sandwich */

/****************************************************************************
* MACROS
****************************************************************************/
#define MY_NAME_LEN       (40)

/****************************************************************************
* TYPEDEF
****************************************************************************/
typedef int MY_birth_year_t;
typedef int MY_birth_month_t;
typedef int MY_birth_day_t;
typedef char MY_name_t[MY_NAME_LEN+1];
typedef struct My_Birth_Stuct
{
	MY_birth_year_t		year;
	MY_birth_month_t	month;
	MY_birth_day_t		day;
	MY_name_t			name;
} MY_birth_t, *MY_birth_p_t;

/****************************************************************************
* PROTOTYPES
****************************************************************************/
SRT_CMP_PROC_t comp_str;
SRT_CMP_PROC_t comp_int;
SRT_CMP_PROC_t comp_int2;
SRT_CMP_PROC_t comp_real;
SRT_CMP_PROC_t comp_birthday;

#endif
