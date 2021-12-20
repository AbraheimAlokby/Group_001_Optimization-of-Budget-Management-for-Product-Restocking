/*******************************************************************/
/*                       PREPROCESSOR GUAARDS                      */
/*******************************************************************/
#ifndef __UPDATE_DATA_H__
#define __UPDATE_DATA_H__

/*******************************************************************/
/*                       FUNCTIONS PROTOTYPES                      */
/*******************************************************************/
#include <stdio.h>
#include <string.h>
#include "utils.h"

/**@brief
* Updates data using Product ID
* @param[in] no_of_Rows Number of the rows in data file
* @param[in] *data Pointer to Array of struct Product
* @param[in] temp_id Product ID which needs to be changed
* @param[out] *data Pointer to Array of struct Product
* @param[out] no_of_rows The number of rows of data in the array of structures
* @retval 1 with successful execution, otherwise return with error code
*/
int update_data(int temp_id, char *filePath, struct Product *data, int noOfRows);

#endif

