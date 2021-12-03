#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readFile.h"
#include "../include/calculateDemand.h"
#include "../include/showItems.h"
#include "../include/optimizationAlgorithm.h"
#define FILE_PATH "..\\data\\abc.csv"



int main() {
    int *noOfRows=(int *)malloc(sizeof(int));
    struct Product **data;

    int x=read_file(FILE_PATH,data,noOfRows);


    calculate_demand(*data,noOfRows);
    show_items(*data,*noOfRows);
    optimization_algorithm(*data,*noOfRows,10000.0);
    return 0;
}

