#ifndef __TEST_OPTIMIZATION_ALGORITHM_H__
#define __TEST_OPTIMIZATION_ALGORITHM_H__

#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

/**
 * @brief The optimisation algorithm function aims to optimize the selection of purchasable products for the beginning of the next fiscal period.
 * @param[in]   data structure containing all the needed data of products for compilation.
 * @param[in]   num_of_rows integer value containing information pertaining to the total number of products.
 * @param[in] total_budget user defined value for how much budget will be allocated for the fiscal planning period
 * @return 0 if the function ran successfully, Otherwise, it returns the corresponding error code.
 */
int test_optimization_algorithm(struct Product *data, int num_of_rows, float total_budget);
#endif
