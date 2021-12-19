#include "../include/calculate_demand.h"

void calculate_demand(int noOfRows,struct Product *data){
    for(int i=0;i<noOfRows;i++){
        float percentageOfItemsSold=(data[i].selling_price-data[i].cost_price+0.0)/data[i].selling_price;
        percentageOfItemsSold*=100;
        int demandVariable;
        if(percentageOfItemsSold>80){
            demandVariable=1;
        }
        else if(percentageOfItemsSold>60&&percentageOfItemsSold<=80){
            demandVariable=2;
        }
        else if(percentageOfItemsSold>40&&percentageOfItemsSold<=60){
            demandVariable=3;
        }
        else if(percentageOfItemsSold>20&&percentageOfItemsSold<=40){
            demandVariable=4;
        }
        else{
            demandVariable=5;
        }
        data[i].demand=demandVariable;
    }
}
