/*******************************************************************/
/*                       PREPROCESSOR GUAARDS                      */
/*******************************************************************/
#ifndef __CALCULATE_PROFIT_H__
#define __CALCULATE_PROFIT_H__

/*******************************************************************/
/*                       FUNCTIONS PROTOTYPES                      */
/*******************************************************************/
#include <stdio.h>
#include "utils.h"

/**@brief
* Calculates the profit of each product in the array of structures
* @param[in] no_of_Rows Number of the rows in data file
* @param[in] *data Pointer to Array of struct Product
* @param[out] *data Pointer to Array of struct Product
* @param[out] no_of_rows The number of rows of data in the array of structures
* @retval 1 with successful execution, otherwise return with error code
*/

int calculate_profit(int noOfRows,struct Product *data);

#endif
