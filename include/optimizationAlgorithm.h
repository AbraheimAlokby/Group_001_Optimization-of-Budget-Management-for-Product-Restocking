#ifndef __OPTIMIZATIONALGORITHM_H__
#define __OPTIMIZATIONALGORITHM_H__

#include <stdio.h>
#include "utils.h"

/*
 * Reads the required product data structure and the length of said
 * data, so that it will be used to display the data to the user
 * if commanded.
 */

void *optimization_algorithm(struct Product *data, int num_of_rows, float total_budget);
#endif
