#ifndef __TEST_READ_FILE_H__
#define __TEST_READ_FILE_H__

#include "../include/utils.h"

/**
* Reads the file containing the program data to be used is retrieved
* from the file system
* @param[in] *filePath The path of the file containing the data
* @param[out] *data Pointer to Array of struct Product
 * @param[out] *noOfRows Pointer to noOfRows to store the number of rows of data fetched
*/
int test_read_file(char *filePath,struct Product **data,int *noOfRows);

#endif

