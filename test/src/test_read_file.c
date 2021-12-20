#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/test_read_file.h"
#include <errno.h>

extern int errno;

int test_read_file(char *filePath,struct Product **data,int *noOfRows){
    if(!filePath){
        return -1;
    }
    if(!data){
        return -1;
    }
    FILE *file=fopen(filePath,"r");
    int rowCount=0;
    int columnCount=0;
    if(file==NULL){
        return -1;
    }
    char c;
    while(!feof(file)){
        char c=fgetc(file);
        if (c == '\n'){
            rowCount++;
        }
    }

    rowCount++;
    *data=(struct Product*)malloc((rowCount-1)*sizeof(struct Product));
    fseek(file,0,SEEK_SET);
    rowCount=0;
    while(!feof(file)){
        char c=fgetc(file);
        if (c == '\n'){
            break;
        }
    }
    char *row=(char *)malloc(sizeof(char));
    fgets(row,1024,file);
    int flag=0;
    int check=0;
    struct Product temp_data[3]={ {1,"a",10,20,10,20},
                                  {2,"b",20,30,10,210},
                                  {3,"c",30,40,10,30}
    };


    while(!feof(file)){
        columnCount=0;
        char *cell;
        cell = strtok(row, ",");

        while( cell != NULL ) {
            int a=atoi(cell);
            if(cell==""){
                flag=1;
            }
            switch(columnCount){
                case 0:
                    (*data)[rowCount].id=a;
                    if(a!=temp_data[rowCount].id){
                        check=1;
                    }
                    break;
                case 1:
                    strcpy((*data)[rowCount].name,cell);
                    if(strcmp(cell,temp_data[rowCount].name)){
                        check=1;
                    }
                    break;
                case 2:
                    (*data)[rowCount].cost_price=a;
                    if(a!=temp_data[rowCount].cost_price){
                        check=1;
                    }
                    break;
                case 3:
                    (*data)[rowCount].selling_price=a;
                    if(a!=temp_data[rowCount].selling_price){
                        check=1;
                    }
                    break;
                case 4:
                    (*data)[rowCount].current_quantity=a;
                    if(a!=temp_data[rowCount].current_quantity){
                        check=1;
                    }
                    break;
                case 5:
                    (*data)[rowCount].initial_quantity=a;
                    if(a!=temp_data[rowCount].initial_quantity){
                        check=1;
                    }
                    break;
            }
            cell = strtok(NULL, ",");
            columnCount++;
        }
        fgets(row,1024,file);
        rowCount++;
    }
    *noOfRows=rowCount;
    return check;
}

