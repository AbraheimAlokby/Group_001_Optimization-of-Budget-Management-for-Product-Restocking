/*******************************************************************/
/*                       PREPROCESSOR GUAARDS                      */
/*******************************************************************/
#ifndef __READ_FILE_H__
#define __READ_FILE_H__

/*******************************************************************/
/*                       FUNCTIONS PROTOTYPES                      */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utils.h"

/**@brief
 * The file containing the program data to be used is retrieved from the file system
 * @param[in] *filePath The path of the file containing the data
 * @param[out] *data Pointer to Array of struct Product
 * @param[out] *noOfRows Pointer to noOfRows to store the number of rows of data fetched
 * @return Success or error code
 */
int read_file(char *filePath,struct Product **data,int *no_of_rows);

#endif

