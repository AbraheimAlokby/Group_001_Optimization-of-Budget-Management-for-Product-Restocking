#include "../include/read_file.h"

extern int errno;

int read_file(char *filePath,struct Product **data,int *no_of_rows){
    if(!filePath){
        return -3;
    }
    if(!data){
        return -4;
    }
    // Open file with read access
    FILE *file=fopen(filePath,"r");
    int row_count=0;
    int column_count=0;
    // Check for errors in case file read fails
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
    char c;
    // Count the no of products in the file based on number of rows of data
    while(!feof(file)){
        char c=fgetc(file);
        if (c == '\n'){
            row_count++;
        }
    }
    // Allocate memory to array of structures based on count of number of rows
    *data=(struct Product*)malloc((row_count-1)*sizeof(struct Product));

    // Set the read position to beginning for reading the file
    fseek(file,0,SEEK_SET);
    row_count=0;

    // Skip the first line of the file as it contains headings of data
    while(!feof(file)){
        char c=fgetc(file);
        if (c == '\n'){
            break;
        }
    }
    char *row=(char *)malloc(sizeof(char));
    fgets(row,1024,file);
    int flag=0;

    // Read individual comma separated values in the .csv file
    while(!feof(file)){
        column_count=0;
        char *cell;
        // Break the string of comma separated values
        cell = strtok(row, ",");

        while( cell != NULL ) {
            int a=atoi(cell);
            // Check if any value is empty
            if(cell==""){
                flag=1;
            }
            switch(column_count){
                case 0:
                    (*data)[row_count].id=a;
                    break;
                case 1:
                    strcpy((*data)[row_count].name,cell);
                    break;
                case 2:
                    (*data)[row_count].cost_price=a;
                    break;
                case 3:
                    (*data)[row_count].selling_price=a;
                    break;
                case 4:
                    (*data)[row_count].current_quantity=a;
                    break;
                case 5:
                    (*data)[row_count].initial_quantity=a;
                    break;
            }
            cell = strtok(NULL, ",");
            column_count++;
        }
        fgets(row,1024,file);
        row_count++;
    }
    if(flag==1){
        printf("Incomplete Data In the file. Please update the data before ");
        return 1;
    }
    // The number of rows saved and to be used later in the program
    *no_of_rows=row_count;
    return 0;
}

