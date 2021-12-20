#include "../include/test_calculate_profit.h"

int test_calculate_profit(int no_of_rows,struct Product *data){
    // Data with which computated profits are to be compared for correct values
    int temp_data[]={10,10,10};
    int flag=0;
    for(int i=0;i<no_of_rows;i++){
        data[i].profit = data[i].selling_price - data[i].cost_price;
        // Comparison to check for correct values
        if(data[i].profit!=temp_data[i]){
            flag=-1;
        }
    }
    return flag;
}