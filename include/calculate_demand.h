#ifndef __CALCULATE_DEMAND_H__
#define __CALCULATE_DEMAND_H__

#include <stdio.h>
#include "utils.h"
/**
* Calculates the demand of each product in the array of structures
* @param[out] *data Pointer to Array of struct Product
* @param[out] no_of_rows The number of rows of data in the array of structures
*/
void calculate_demand(int no_of_Rows,struct Product *data);

#endif
