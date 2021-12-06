#ifndef __INSERTNEWDATA_H__
#define __INSERTNEWDATA_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

/**
* Asks the user to input the new product specifications and adds them
* to the file as well as the array of structure
* @param[in] *filePath The path of the file containing the data
* @param[out] *data Pointer to Array of struct Product
* @param[out] *noOfRows Pointer to noOfRows to store the number of rows of data fetched
*/
int insert_new_data(char *filePath, struct Product **data, int *noOfRows);

#endif
