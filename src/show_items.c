#include "../include/show_items.h"


#define MAX 16

/** The showitems function aims to show the user either, all the product data found within the given file, or show selected product data from desired product IDs.
 */
void *show_items(struct Product *data, int num_of_rows){
    int i;  /*!< row indexing */
    char user_decision_str[15]; /*!< user input for what the program needs to show */
    int user_decision_int; /*!< user input for what the program needs to show */
    int count = 0;      /*!< Count variable used in loop sequences to keep track of
                         * how many inputs the user had entered for displaying
                         * selected products.
                         */
    int* selected_products = NULL;  /*!< Dynamic array that stores user inputs of
                                     * valid product IDs, to show the data of
                                     * later.
                                     */
    int* more_selected_products = NULL; /*!< array that re allocates required
                                         * memory needed for the selected_products
                                         * array.
                                         */
    char user_input_str[25];    /*!< String that saves the user input of the
                                 * desired product ID to later show information.
                                 */
    int user_input_int;         /*!< Will be used to save the user string input
                                 * of user_input_str, to ensure inputs are only
                                 * an integer of the product ID as requested.
                                 */
    int n;  /*!< Used for indexing */
    int is_found = 1; /*!< Binary Variable used to check if product ID searched
                       * by the user exists. Initialized to be false.
                       */


    do{
        /* Asks the user for the desired selection. */
        puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        puts("Please Select Either of the Following:  ");
        puts("1 - Select All Data to Show");
        puts("2 - Select Desired Data to Show");
        puts("done - To Exit Data Viewing");
        puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        scanf(" %s", &user_decision_str);
        user_decision_int = atoi(user_decision_str);

        /* Checks if user input is a string instead of a requested number (except 'done'). */
        if(0 == user_decision_int && strcmp(user_decision_str, "done") != 0){
            puts("Incorrect Value. Try again");

        }

            /* Checks if user input is not the requested integers and the exit condition string. */
        else if(user_decision_int != 1 && user_decision_int != 2 && strcmp(user_decision_str, "done") != 0 ){
            puts("Incorrect Value. Try again");

        }

            /* If user input matches selection 1, function shows all the product data. */
        else if(1 == user_decision_int){
            printf ("Showing Information for All Products: \n");
            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
            char *row1[] = {"Product Name", "Product ID", "Purchase Price", "Selling Price", "Profit", "Demand", "Initial Quantity", "Current Quantity"};       /* row 1 signifies the column names of the outputted data */
            printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s | %*s\n", -MAX, row1[0], MAX, row1[1], MAX, row1[2], MAX, row1[3], MAX, row1[4], MAX, row1[5], MAX, row1[6], MAX, row1[7]);    /* Prints each column name in their respective
                                                                                                                                                                                            *  location into the command terminal
                                                                                                                                                                                            */
            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");

            /* Accesses each row from the Product structure. */
            for(i=0; i<num_of_rows; i++){
                printf("%-16s | %16d | %16f | %16f | %16f | %16d | %16d | %16d\n", data[i].name, data[i].id, data[i].cost_price, data[i].selling_price, data[i].profit, data[i].demand, data[i].initial_quantity, data[i].current_quantity);       /* Prints the desired column of data each. Note that the value within %d must be equal to MAX */
            }
            puts("\n");
        }


            /* If user input matches selection 2, function shows the data for only the products selected by the user */
        else if(2 == user_decision_int){
            do {
                printf ("Enter a product ID (type 'done' to end): ");   /* Asks the user of what product they want to
                                                                         * see data for.
                                                                         */
                scanf (" %s", &user_input_str);
                user_input_int = atoi(user_input_str);  /* Converts all user inputs into an integer */


                if(user_input_int == 0 && strcmp(user_input_str, "done") != 0){     /* Checks if user input is a string and not the end condition string */
                    puts("Entered value is incorrect. Please try again.");  /* Notifies user of error input */

                }

                else if(user_input_int != 0){     /* Checks if user input is a value */

                    for (i = 0; i < num_of_rows; i++){   /* Checks if user input product ID matches the values saved in the structure */
                        if (data[i].id == user_input_int){
                            is_found = 1;   /* Input ID is found */
                            break;
                        }
                        else {
                            is_found = 0;   /* Input ID is not found */
                        }
                    }

                    if (is_found == 0){   /* Notifies the user if the Input ID was not found */
                        puts("Entered product ID does not match archived values. Please try again.");
                    }
                    else if(is_found == 1){  /* Checks if the product ID inputted by the user is found in the structure */
                        count++;    /* Asks the user for Product IDs until user is satisfied with an end condition input of 0 */
                        more_selected_products = (int*) realloc (selected_products, count * sizeof(int));   /* Each time a new value is introduced the memory block pointed by selected_products is increased by the size of an int */


                        if(more_selected_products != NULL){ /* Checks if the user is adding more product IDs, then
                                                             * adds the most recent product ID to the dynamic array
                                                             * selected_products.
                                                             */
                            selected_products=more_selected_products;   /* Updates the size of the array */
                            selected_products[count-1]=user_input_int;  /* Saves the user input into a dynamic array */
                        }
                        else {  /* Checks if we reach an un-expected end to the array */
                            free (selected_products);   /* Frees the memory allocated to the array to prevent memory leak */
                            puts ("Error (re)allocating memory");   /* Notifies user that an error occurred */
                            exit (1);
                        }

                    }
                }


            } while (strcmp(user_input_str, "done") != 0);  /* This do-while loop prompts the user for numbers until a zero character
                                                             * is entered. Each time a new value is introduced the memory block pointed
                                                             * by selected_products is increased by the size of an int.
                                                             */
            puts("\n");
            printf ("Showing Information for Selected Products: \n");

            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
            char *row1[] = {"Product Name", "Product ID", "Purchase Price", "Selling Price", "Profit", "Demand", "Initial Quantity", "Current Quantity"};       /* row 1 signifies the column names of the outputted data */
            printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s | %*s\n", -MAX, row1[0], MAX, row1[1], MAX, row1[2], MAX, row1[3], MAX, row1[4], MAX, row1[5], MAX, row1[6], MAX, row1[7]);   /* Prints each column name in their respective location into the command terminal */
            puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");

            for(n = 0; n<count; n++){                                       /* Looks for matching product numbers from the data array and outputs the row */
                for(i = 0; i<num_of_rows; i++){
                    if(selected_products[n] == data[i].id){
                        printf("%-16s | %16d | %16f | %16f | %16f | %16d | %16d | %16d\n", data[i].name, data[i].id, data[i].cost_price, data[i].selling_price, data[i].profit, data[i].demand, data[i].initial_quantity, data[i].current_quantity);/* Prints the desired column of data each. Note that the value within %d must be equal to MAX */
                    }
                }
            }
            puts("\n");
            free (selected_products);  /* Deallocates the memory previously allocated to the selected_products array */

        }

    }while( strcmp(user_decision_str, "done") != 0);    /* Function continues basic functionality until user enters
                                                         * exit condition 'done'
                                                         */

    return 0;
}

