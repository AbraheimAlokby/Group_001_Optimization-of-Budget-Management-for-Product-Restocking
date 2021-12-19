#include "../include/updateData.h"

int update_data(int temp_id, char *filePath, struct Product *data, int no_of_rows){
    if(!temp_id){
        printf("Enter Valid number");
        return 4;
    }

    int n,flag = 0;
    for(int i=0;i<no_of_rows;i++){
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

    FILE *fp = fopen(filePath,"w");
    fprintf(fp,"Product ID,Name,Price,Selling Price,Quantity,Initial Quantity\n");
    for(int i=0;i<no_of_rows;i++){
        fprintf(fp, "%d,%s,%d,%f,%f,%d,%d\n", data[i].id,data[i].name,data[i].cost_price,data[i].selling_price,data[i].current_quantity,data[i].initial_quantity);
    }
    fclose(fp);
}