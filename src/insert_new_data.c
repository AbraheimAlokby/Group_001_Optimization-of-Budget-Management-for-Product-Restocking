#include "../include/insert_new_data.h"

int insert_new_data(char *filePath, struct Product **data, int *noOfRows){
    char name[30];
    float cost_price, selling_price;
    int current_quantity, initial_quantity;

    // Ask user for product specifications

    printf("Enter name of the product= ");
    scanf("%s",&name);

    printf("Enter cost price of the the product= ");
    scanf("%f",&cost_price);

    printf("Enter selling price of the the product= ");
    scanf("%f",&selling_price);
    while(selling_price<cost_price){
        printf("Invalid Value: Selling Price must be more than cost price \n");
        printf("Enter selling price of the the product= ");
        scanf("%f",&selling_price);
    }

    printf("Enter the current quantity of the product= ");
    scanf("%d",&current_quantity);

    printf("Enter the initial quantity of the= ");
    scanf("%d",&initial_quantity);
    while(initial_quantity<current_quantity){
        printf("Invalid Value: Initial Quantity must be more than Current Quantity \n");
        printf("Enter the initial quantity of the= ");
        scanf("%d",&initial_quantity);
    }

    // Creating a string of comma separated values for user specifications to store them in the .csv file
    char *str=(char *)malloc(sizeof(char)*200);
    int id=(*data)[*noOfRows-1].id+1;

    char *tempStr=(char *)malloc(sizeof(char)*20);
    snprintf(tempStr,20,"%d",id);
    strcpy(str,tempStr);
    strcat(str,",");
    strcat(str,name);
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
    FILE *file= fopen(filePath,"a");
    if(file==NULL){
        return 1;
    }
    // Insert the created string in the last row of the file
    fputs(str,file);
    // Inserting "\n" at the end of the file
    fputc(10,file);
    // Closing the file
    fclose(file);

    // Increasing the number of rows by one after adding new data row
    *noOfRows=*noOfRows+1;

    // Resizing the array to store the new product
    (*data)=(struct Product*)realloc(*data,(*noOfRows)*sizeof(struct Product));

    // Assigning values at the end of the Array of structures
    (*data)[*noOfRows-1].id=id;
    strcpy((*data)[*noOfRows-1].name,name);
    (*data)[*noOfRows-1].cost_price=cost_price;
    (*data)[*noOfRows-1].selling_price=selling_price;
    (*data)[*noOfRows-1].current_quantity=current_quantity;
    (*data)[*noOfRows-1].initial_quantity=initial_quantity;
    return 0;

}
