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

    printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    printf("\n    ABC Corporation \n");
    printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");


    while(case_no) {
        printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf("    Menu:\n");
        printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf("Enter the option number to run following functions :\n");
        printf("1. Show all data or specific data \n");
        printf("2. Insert New Product \n");
        printf("3. Update Existing Product Data \n");
        printf("4. Optimize Product Restocking\n");
        printf("Enter 0 to exit the program\n");
        scanf("%d", &case_no);
        switch (case_no) {
            case 1:
                show_items(*data, *noOfRows);
                break;
            case 2:
                insert_new_data(FILE_PATH, data, noOfRows);
                break;
            case 3:
                int id;
                printf("Enter ID of the product you want to update= ");
                scanf("%d",&id);
                update_data(id, FILE_PATH, *data, *noOfRows);
                break;
            case 4:
                calculate_demand(*data, noOfRows);
                calculate_profit(*noOfRows, *data);
                float total_budget;
                printf("Enter Total Budget to be allocated for Restocking= ");
                scanf("%f", &total_budget);
                optimization_algorithm(*data, *noOfRows, total_budget);
                break;
            default:
                case_no=0;
        }
    }
    return 0;
}

