#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readFile.h"
#include "../include/calculateDemand.h"
#include "../include/showItems.h"
#include "../include/optimizationAlgorithm.h"
#include "../include/updateData.h"
#include "../include/calculateProfit.h"
#include "../include/insertNewData.h"
#define FILE_PATH "..\\data\\abc.csv"



int main() {
    int *noOfRows=(int *)malloc(sizeof(int));
    struct Product **data;
    int x=read_file(FILE_PATH,data,noOfRows);

    int case_no;
    printf("Enter Case No:");
    scanf("%d",&case_no);
    switch(case_no){
        case 1:
            update_data(1,FILE_PATH,*data,*noOfRows);
            break;
        case 2:
            insert_new_data(FILE_PATH,data,noOfRows);
            break;
        case 3:
            show_items(*data,*noOfRows);
            break;
        case 4:
            calculate_demand(*data,noOfRows);
            calculate_profit(*noOfRows,*data);
            float total_budget;
            printf("Enter Total Budget to be allocated for Restocking");
            scanf("%f",&total_budget);
            optimization_algorithm(*data,*noOfRows,total_budget);
            break;
    }
    return 0;
}

