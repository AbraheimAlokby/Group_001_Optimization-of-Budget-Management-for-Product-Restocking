#include<stdio.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#include"updateData.h"

struct Product{
    int id;
    char name[30];
    float cost_price;
    float selling_price;
    int current_quantity;
    int initial_quantity;
    float profit;
    int demand;
};

struct Product data[10];

int calculate_profit(){
	for(int i=0;i<10;i++){
		data[i].profit = data[i].selling_price - data[i].cost_price;
	}
}

int askForCase(){
	int case_no;
	scanf("%d",&case_no);
	//print function list
	switch(case_no){
		case 1:
			//fun 1
		case 2:
			//fun 2
	}
}

int updateData(int temp_id){
	if(temp_id)
		continue;	
	else{
		printf("Enter Valid number");
		return 4;	
	}
	
	int n,flag = 0;
	for(int i=0;i<10;i++){
		if(temp_id == data[i].id){
			
			printf("Press 1 to update ID\n");
			printf("Press 2 to update name\n");
			printf("Press 3 to update cost price\n");
			printf("Press 4 to update selling price\n");
			printf("Press 5 to update current quantity\n");
			printf("Press 6 to update initial quantity\n");
			scanf("%d", &n);
			
			if(n == 1){
				printf("Enter ID: ");
				int temp;
				scanf("%d",&temp);
				for(int j = 0; j < 10; j++){
					if(data[i].id == temp){
						printf("Product ID is already exists in the file\n");
						return 1;
					}
				}
				data[i].id = temp;
			}
			
			else if(n == 2){
				printf("Enter Name: ");
				char new_name[30];
				scanf("%s",new_name);
				strcpy(data[i].name,new_name);
			}
			else if(n == 3){
				printf("Enter Cost Price: ");
				float temp;
				scanf("%f",&temp);
				data[i].cost_price = temp;
			}
			else if(n == 4){
				printf("Enter Selling Price: ");
				float temp;
				scanf("%f",&temp);
				data[i].selling_price = temp;
			}
			else if(n == 5){
				printf("Enter Current Quantity: ");
				int temp;
				scanf("%d",&temp);
				data[i].current_quantity = temp;
			}
			else if(n == 6){
				printf("Enter Initial Quantity: ");
				int temp;
				scanf("%d",&temp);
				data[i].initial_quantity = temp;
			}
			flag = 1;
			break;
		}
	}
			
	if(flag == 0)
		printf("data not found\n");	
	
	FILE *fp = fopen("C:\\Users\\jeett\\Desktop\\abc.txt","w");
	
	for(int i=0;i<10;i++){
		fprintf(fp, "%d;%f;%f;\n", data[i].id,data[i].cost_price,data[i].selling_price);		
	}
	
	fclose(fp);	
}

int main(){
	
	int n;
	srand(time(NULL));   // Initialization, should only be called once.
	for(int i=0;i<10;i++){
		data[i].id =  rand() % 20;
		data[i].cost_price = rand();
		data[i].selling_price = rand();		
	}
	int temp_id;
	printf("Enter ID of product which you want to update: ");
	scanf("%d", &temp_id);
	int r = updateData(temp_id);	
}
