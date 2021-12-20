#include "../include/test_insert_new_data.h"

int test_insert_new_data(char *filePath, struct Product **data, int *noOfRows){

    // Sample test data for the test case
//    char name[]="d";
    float cost_price=30, selling_price=40;
    int current_quantity=10, initial_quantity=30;
    int id=3;

    // Creating a string of comma separated values for user specifications to store them in the .csv file
    char *str=(char *)malloc(sizeof(char)*200);


    char *tempStr=(char *)malloc(sizeof(char)*20);
    snprintf(tempStr,20,"%d",id);
    strcpy(str,tempStr);
    strcat(str,",");
    strcat(str,"c");
    strcat(str,",");
    snprintf(tempStr,20,"%f",cost_price);
    strcat(str,tempStr);
    strcat(str,",");
    snprintf(tempStr,20,"%f",selling_price);
    strcat(str,tempStr);
    strcat(str,",");
    snprintf(tempStr,20,"%d",current_quantity);
    strcat(str,tempStr);
    strcat(str,",");
    snprintf(tempStr,20,"%d",initial_quantity);
    strcat(str,tempStr);
    strcat(str,"\0");
    // Opening the file for append access
    FILE *file= fopen(filePath,"r");
    if(file==NULL) {
        return -1;
    }
    char c;
    int row_count=0;
    while(!feof(file)&&row_count<3){
        c=fgetc(file);
        if (c == '\n'){
            row_count++;
        }
    }

    int flag=0;
    int i=0;
    while(!feof(file)){
        char q=fgetc(file);
        if(str[i]!=q){
            flag=-1;
        }
        i++;
    }

    return flag;

}
