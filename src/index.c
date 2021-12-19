#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read_file.h"
#include "../include/calculate_demand.h"
#include "../include/show_items.h"
#include "../include/optimization_algorithm.h"
#include "../include/update_data.h"
#include "../include/calculate_profit.h"
#include "../include/insert_new_data.h"
#define FILE_PATH "..\\data\\product_data.csv"



int main() {
    int *no_of_rows=(int *)malloc(sizeof(int));
    struct Product **data;
    int x=read_file(FILE_PATH,data,no_of_rows);

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
                calculate_demand(*no_of_rows,*data);
                calculate_profit(*no_of_rows,*data);
                show_items(*data, *no_of_rows);
                break;
            case 2:
                insert_new_data(FILE_PATH, data, no_of_rows);
                break;
            case 3:
                int id;
                printf("Enter ID of the product you want to update= ");
                scanf("%d",&id);
                update_data(id, FILE_PATH, *data, *no_of_rows);
                break;
            case 4:
                calculate_demand(*no_of_rows,*data);
                calculate_profit(*no_of_rows,*data);
                float total_budget;
                printf("Enter Total Budget to be allocated for Restocking= ");
                scanf("%f", &total_budget);
                optimization_algorithm(*data, *no_of_rows, total_budget);
                break;
            default:
                case_no=0;
        }
    }
    return 0;
}

