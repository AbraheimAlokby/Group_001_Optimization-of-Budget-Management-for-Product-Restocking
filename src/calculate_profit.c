#include "../include/calculate_profit.h"

int calculate_profit(int no_of_rows,struct Product *data){
    for(int i=0;i<no_of_rows;i++){
        data[i].profit = data[i].selling_price - data[i].cost_price;
    }
}