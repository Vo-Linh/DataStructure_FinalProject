#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.cpp"

int payment(int amountBrand)
{
    int idx[amountBrand];
    int amount[amountBrand];
    int total;
    
    for (int i = 0; i <= amountBrand; i++)
    {
        printf("Enter id");
        scanf("%d", &idx[i]);
        printf("Enter Amount");
        scanf("%d", &amount[i]);
    }

    for (int i = 0; i < amountBrand; i++)
    {
        //  total = amount[i]*FindId(idx[i]);
    }

    return total;
}