#include "../include/test_calculate_demand.h"

int test_calculate_demand(struct Product *data,int noOfRows){
    int temp_data[]={3,5,4};
    int flag=0;
    for(int i=0;i<noOfRows;i++){
        float percentageOfItemsSold=(data[i].initial_quantity-data[i].current_quantity+0.0)/data[i].initial_quantity;
        percentageOfItemsSold*=100;
        if(percentageOfItemsSold>80){
            data[i].demand=5;
        }
        else if(percentageOfItemsSold>60&&percentageOfItemsSold<=80){
            data[i].demand=4;
        }
        else if(percentageOfItemsSold>40&&percentageOfItemsSold<=60){
            data[i].demand=3;
        }
        else if(percentageOfItemsSold>20&&percentageOfItemsSold<=40){
            data[i].demand=2;
        }
        else {
            data[i].demand =1;
        }
        if(data[i].demand!=temp_data[i]){
            flag=-1;
        }
    }
    return flag;
}
