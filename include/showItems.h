//
// Created by Abe on 2021-11-25.
//

#ifndef MY_FUNCTIONS_V001_SHOWITEMS_H
#define MY_FUNCTIONS_V001_SHOWITEMS_H

#include <stdio.h>
#include "utils.h"

/*
 * Reads the required product data structure and the length of said
 * data, so that it will be used to display the data to the user
 * if commanded.
 */

void *show_items(struct Product *data, int num_of_rows);

#endif //MY_FUNCTIONS_V001_SHOWITEMS_H
