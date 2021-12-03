#include <stdio.h>
#include <stdlib.h>
#include "../include/optimizationAlgorithm.h"

void *optimization_algorithm(struct Product *data, int num_of_rows, float total_budget){

    int i; /*index for product selection within array of structures */
    int demand_rank = 5; /*index count for ranking based on demand value */
    float temp_allocated_allocated_budget = 0; /* Temporary variable used to
                                                * determine how much of item
                                                * i should be purchased.
                                                */
    float current_budget = total_budget;/*Identifies the current budget
                                         * after funds have been taken.
                                         * Initialized as total budget.
                                         */
    //current_budget = total_budget
    printf("total budget = %f \n", total_budget);
    printf("current budget = %f \n", current_budget);

    /*Allocate percentage of budget to a product based on that products
     * level of demand (and possibly level of profit). Allocated budget
     * will be removed from the total budget. The remaining budget will
     * be re-allocated to the next fiscal year.
     */

    while(demand_rank >= 0){    /*While loop selects the demand from
                                 * highest to lowest. Ensuring that
                                 * the most budget will be allocated
                                 * to the items of the highest demand.
                                 */

        printf("Budget allocations for Rank: %d\n", demand_rank); /*Output used for testing purposes */
        for(i=0; i<num_of_rows; i++){   /*For loop iterates through each item
                                         * of the list.
                                         */
            if(data[i].demand == demand_rank){ /*if statement ensures that budget
                                               * allocation only is done for the
                                               * desired rank (5 to 0)
                                               */
                if (data[i].demand == 5 && current_budget > data[i].cost_price && data[i].profit > 0){
                    /* Give highest percentage of the current allocated budget */
                    data[i].product_budget = 0.15 * current_budget;
                    /*Reduce the current budget by the taken budget */
                    current_budget -= data[i].product_budget;
                }
                else if (data[i].demand == 4 && current_budget > data[i].cost_price && data[i].profit > 0){
                    /* Give high percentage of the current allocated budget */
                    data[i].product_budget = 0.135 * current_budget;
                    /*Reduce the current budget by the taken budget */
                    current_budget -= data[i].product_budget;
                }
                else if (data[i].demand == 3 && current_budget > data[i].cost_price && data[i].profit > 0){
                    /* Give intermediate percentage of the current allocated budget */
                    data[i].product_budget = 0.1 * current_budget;
                    /*Reduce the current budget by the taken budget */
                    current_budget -= data[i].product_budget;
                }
                else if (data[i].demand == 2 && current_budget > data[i].cost_price && data[i].profit > 0){
                    /* Give low percentage of the current allocated budget */
                    data[i].product_budget = 0.075 * current_budget;
                    /*Reduce the current budget by the taken budget */
                    current_budget -= data[i].product_budget;
                }
                else if (data[i].demand == 1 && current_budget > data[i].cost_price && data[i].profit > 0){
                    /* Give lowest percentage of the current allocated budget */
                    data[i].product_budget = 0.065 * current_budget;
                    /*Reduce the current budget by the taken budget */
                    current_budget -= data[i].product_budget;
                }
                else {
                    /* Give zero percentage of the current allocated budget */
                    data[i].product_budget = 0.0 * current_budget;
                    /*Reduce the current budget by the taken budget */
                    current_budget -= data[i].product_budget;
                }

                printf("Product %d -> Allocation: %f / %f \n", i, data[i].product_budget, current_budget); /*Output used for testing purposes */
            }
            else{
                continue; /* Ensures iteration is properly moved on to the next item of the list */
            }
        }
        demand_rank--;
    }
    printf("Final remaining budget = %f \n", current_budget);

    for (i=0; i<num_of_rows; i++){  /* For loop iterates through each item of the
                                     * list, to select how many of each item
                                     * should be purchased based on the allocated
                                     * budget determined previously.
                                     */
        temp_allocated_allocated_budget = data[i].product_budget;
        /* Determine the restock amount for item i */
        while(temp_allocated_allocated_budget >= 0){
            /* Remove single product cost of item i from temp_allocated_budget */
            temp_allocated_allocated_budget -= data[i].cost_price;
            /* Test if it is possible to buy another unit of an item */
            if(temp_allocated_allocated_budget <= 0){
                /* If we exceed the allocated budget move on to the next item */
                break;
            }
            else{
                /* Increment restock amount by one while we have available allocated budget */
                data[i].restock_amount++;
                /* Test Output */
                printf("Product %d - Restock value %d -> Current Allocated Budget = %f \n", i, data[i].restock_amount, temp_allocated_allocated_budget);
            }
        }
        /* Test Output */
        printf("Product %d -> Amount Purchased = %d \n", i, data[i].restock_amount);
        puts("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    }
    return 0;
}