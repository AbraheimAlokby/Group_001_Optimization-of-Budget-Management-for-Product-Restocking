#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readFile.h"
#include "../include/readFile.h"
#define FILE_PATH "..\\abc.csv"




int main() {
    int *noOfRows=(int *)malloc(sizeof(int));
    struct Product data[3];

    int x=read_file(FILE_PATH,data,noOfRows);

    for(int i=0;i<*noOfRows;i++){
        printf("%d %s %f %f %d %d ",data[i].id,data[i].name,data[i].cost_price,data[i].selling_price,data[i].current_quantity,data[i].initial_quantity);
        printf("\n");
    }
    calculate_demand(data,*noOfRows);
    return 0;
}
