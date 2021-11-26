#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readFile.h"
#include "../include/calculateDemand.h"
#include <errno.h>

extern int errno;

int read_file(char *filePath,struct Product *data,int *noOfRows){
    if(!filePath){
        return -3;
    }
    if(!data){
        return -4;
    }
    FILE *file=fopen(filePath,"r");
    int rowCount=0;
    int columnCount=0;
    if(file==NULL){
        if(errno==ENOENT){
            printf("No such file present");
            return 2;
        }
        else if(errno==EISDIR){
            printf("The path refers to a directory");
            return 21;
        }
        else if(errno==EMFILE){
            printf("ERROR: Too many files are open");
            return 24;
        }
        else{
            printf("Error opening file");
            return -1;
        }
    }
    char *row=(char *)malloc(sizeof(char));
    fgets(row,1024,file);
    int flag=0;
    while(!feof(file)){
        columnCount=0;
        char *cell;
        cell = strtok(row, ",");

        while( cell != NULL ) {
            int a=atoi(cell);
            if(cell==""){
                flag=1;
            }
            if(rowCount!=0){
                switch(columnCount){
                    case 0:
                        data->id=a;
                        break;
                    case 1:
                        strcpy(data->name,cell);
                        break;
                    case 2:
                        data->cost_price=a;
                        break;
                    case 3:
                        data->selling_price=a;
                        break;
                    case 4:
                        data->current_quantity=a;
                        break;
                    case 5:
                        data->initial_quantity=a;
                        break;
                }
            }
            cell = strtok(NULL, ",");
            columnCount++;
        }
        if(rowCount!=0){
            data++;
        }
        fgets(row,1024,file);
        rowCount++;
    }
    if(flag==1){
        printf("Incomplete Data In the file. Please update the data before ");
        return 1;
    }
    *noOfRows=rowCount-1;
    return 0;
}

