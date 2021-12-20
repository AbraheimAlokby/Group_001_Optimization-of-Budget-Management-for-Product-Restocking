/*******************************************************************/
/*                       PREPROCESSOR GUAARDS                      */
/*******************************************************************/
#ifndef __CALCULATE_DEMAND_H__
#define __CALCULATE_DEMAND_H__

/*******************************************************************/
/*                       FUNCTIONS PROTOTYPES                      */
/*******************************************************************/

#include <stdio.h>
#include "utils.h"
/**@brief
* Calculates the demand of each product in the array of structures
* @param[in] no_of_Rows Number of the rows in data file
* @param[in] *data Pointer to Array of struct Product
* @param[out] *data Pointer to Array of struct Product
* @param[out] no_of_rows The number of rows of data in the array of structures
*/
void calculate_demand(int no_of_Rows,struct Product *data);

#endif
