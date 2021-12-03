#ifndef __UTILS_H__
#define __UTILS_H__

/*This header file creates the required structure needed for the data allocation of the program */

struct Product {
    int id;                     /* Product identification number */
    char name[30];             /* Product name */
    float cost_price;           /* Product price for company to purchase the item */
    float selling_price;        /* Product price for company to sell the item */
    int current_quantity;       /* Product quantity found at the end of the fiscal period */
    int initial_quantity;       /* Product quantity found at the beginning of the fiscal period */
    float profit;               /* Expected product net profits */
    int demand;                 /* Customer demand for the product */
    float product_budget;       /* Percentage of total budget allocated for restocking a specific product */
    int restock_amount;         /* Final decision for how many of a certain product should be purchased
                                 * at the beginning of the next fiscal period to ensure maximum profits */
};

#endif
