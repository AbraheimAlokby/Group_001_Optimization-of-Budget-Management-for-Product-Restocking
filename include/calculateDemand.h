#ifndef __CALCULATEDEMAND_H__
#define __CALCULATEDEMAND_H__

#include <stdio.h>
#include "utils.h"
/**
* Calculates the demand of each product in the array of structures
* @param[out] *data Pointer to Array of struct Product
* @param[out] *noOfRows Pointer to noOfRows to store the number of rows of data fetched
*/
int *calculate_demand(struct Product *data,int *noOfRows);

#endif
