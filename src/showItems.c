//
// Created by Abe on 2021-11-25.
//

#include <stdio.h>
#include <stdlib.h>
#include "showItems.h"

#define MAX 16


void *show_items(struct Product *data, int num_of_rows){
    int i;  //row indexing
    int user_decision; //user input for what the program needs to show
    //int user_selection; //user input for how many projects they want to
    int count = 0;      //dummy count variable used in loop sequences
    int* selected_products = NULL;
    int* more_selected_products = NULL;

    int user_input;
    int n;




    do{
        puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        puts("Please Select Either of the Following:  ");
        puts("1 - Select All Data");
        puts("2 - Select Desired Data");
        puts("0 - To Exit");
        puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        //puts("\n");
        scanf("%d", &user_decision);

        if(user_decision == 1){
            printf ("Showing Information for All Products: \n");
            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
            char *row1[] = {"Product Name", "Product ID", "Purchase Price", "Selling Price", "Profit", "Demand", "Initial Quantity", "Current Quantity"};       //row 1 signifies the column names of the outputted data
            printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s | %*s\n", -MAX, row1[0], MAX, row1[1], MAX, row1[2], MAX, row1[3], MAX, row1[4], MAX, row1[5], MAX, row1[6], MAX, row1[7]);                      //Prints each column name in their respective location into the command terminal
            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");

            for(i=0; i<num_of_rows; i++){     //Accesses each row from the data structure
                printf("%-16s | %16d | %16f | %16f | %16f | %16d | %16d | %16d\n", data[i].name, data[i].id, data[i].cost_price, data[i].selling_price, data[i].profit, data[i].demand, data[i].initial_quantity, data[i].current_quantity);       //Prints the desired column of data each. Note that the value within %d must be equal to MAX
            }
            puts("\n");
        }



        else if(user_decision == 2){
            do {                                                                                    //Asks the user for Product IDs until user is satisfied with an end condition input of 0
                printf ("Enter a product ID (0 to end): ");
                scanf ("%d", &user_input);
                count++;

                more_selected_products = (int*) realloc (selected_products, count * sizeof(int));   //Each time a new value is introduced the memory block pointed by selected_products is increased by the size of an int

                if (more_selected_products != NULL){
                    selected_products=more_selected_products;
                    selected_products[count-1]=user_input;                                          //Saves the user input into a dynamic array
                }
                else {
                    free (selected_products);
                    puts ("Error (re)allocating memory");
                    exit (1);
                }

            } while (user_input!=0);                                                                //This do while loop prompts the user for numbers until a zero character is entered. Each time a new value is introduced the memory block pointed by selected_products is increased by the size of an int.
            puts("\n");
            printf ("Showing Information for Selected Products: \n");

            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
            char *row1[] = {"Product Name", "Product ID", "Purchase Price", "Selling Price", "Profit", "Demand", "Initial Quantity", "Current Quantity"};       //row 1 signifies the column names of the outputted data
            printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s | %*s\n", -MAX, row1[0], MAX, row1[1], MAX, row1[2], MAX, row1[3], MAX, row1[4], MAX, row1[5], MAX, row1[6], MAX, row1[7]);                      //Prints each column name in their respective location into the command terminal
            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");

            for(n = 0; n<count; n++){                                       //Looks for matching product numbers from the data array and outputs the row
                for(i = 0; i<num_of_rows; i++){
                    if(selected_products[n] == data[i].id){
                        printf("%-16s | %16d | %16f | %16f | %16f | %16d | %16d | %16d\n", data[i].name, data[i].id, data[i].cost_price, data[i].selling_price, data[i].profit, data[i].demand, data[i].initial_quantity, data[i].current_quantity);//Prints the desired column of data each. Note that the value within %d must be equal to MAXintf
                    }
                }
            }
            puts("\n");
            free (selected_products);                                                           //Deallocates the memory previously allocated to the selected_products array

        }



    }while( user_decision != 0);

    return 0;
}
