#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\test_read_file.h"
#include "..\include\test_calculate_demand.h"
#include "..\include\test_calculate_profit.h"
#include "..\include\test_optimization_algorithm.h"
#include "..\include\test_insert_new_data.h"

#define FILE_PATH "..\\test\\data\\data.csv"
#define TOTAL_BUDGET 4000



int main() {
    int *noOfRows=(int *)malloc(sizeof(int));
    struct Product **data;

    int x=test_read_file(FILE_PATH,data,noOfRows);
    if(x==0){
        printf(" ~~~~ Test Case Read File : Passed ~~~~ \n");
    }
    else{
        printf(" ~~~~ Test Case Read File : Failed ~~~~ \n");
    }

    x=test_calculate_demand(*data,*noOfRows);
    if(x==0){
        printf("\n ~~~~ Test Case Calculate Demand : Passed ~~~~ \n");
    }
    else{
        printf("\n ~~~~ Test Case Calculate Demand : Failed ~~~~ \n");
    }

    x=test_calculate_profit(*noOfRows,*data);
    if(x==0){
        printf("\n ~~~~ Test Case Calculate Profit : Passed ~~~~ \n");
    }
    else{
        printf("\n ~~~~ Test Case Calculate Profit : Failed ~~~~ \n");
    }

//    x=test_insert_new_data(FILE_PATH,data,noOfRows);
//    printf("\nASFASAFAS %d  ",x);
    printf(" \n \n Testing Each Step of optimization:  \n");
    x=test_optimization_algorithm(*data, *noOfRows,TOTAL_BUDGET);
    if(x==0){
        printf("\n ~~~~ Test Case Optimization : Passed ~~~~ \n");
    }
    else{
        printf("\n ~~~~ Test Case Optimization : Failed ~~~~ \n");
    }

    return 0;
}
