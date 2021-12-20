#include "../include/calculate_demand.h"

void calculate_demand(int noOfRows,struct Product *data){
    for(int i=0;i<noOfRows;i++){
        float percentageOfItemsSold=(data[i].initial_quantity-data[i].current_quantity+0.0)/data[i].initial_quantity;
        percentageOfItemsSold*=100;
        int demandVariable;
        if(percentageOfItemsSold>80){
            demandVariable=5;
        }
        else if(percentageOfItemsSold>60&&percentageOfItemsSold<=80){
            demandVariable=4;
        }
        else if(percentageOfItemsSold>40&&percentageOfItemsSold<=60){
            demandVariable=3;
        }
        else if(percentageOfItemsSold>20&&percentageOfItemsSold<=40){
            demandVariable=2;
        }
        else{
            demandVariable=1;
        }
        data[i].demand=demandVariable;
    }
}
