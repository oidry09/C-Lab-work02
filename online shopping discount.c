#include <stdio.h>

float calculateDiscount(float amount)
{
    if(amount >= 5000)
        return amount * 0.10;
    else if(amount >= 3000)
        return amount * 0.05;
    else
        return 0;
}

float calculateFinalAmount(float amount, float discount)
{
    return amount - discount;
}

void displayReceipt(char name[], float amount,
                    float discount, float final)
{
    printf("\n----- Receipt -----\n");
    printf("Customer Name : %s\n", name);
    printf("Purchase Amount : Tk %.2f\n", amount);
    printf("Discount : Tk %.2f\n", discount);
    printf("Final Payable : Tk %.2f\n", final);
}

int main()
{
    char name[50];
    float amount, discount, final;

    printf("Enter customer name: ");
    scanf(" %[^\n]", name);

    printf("Enter purchase amount: ");
    scanf("%f", &amount);

    if(amount < 0)
    {
        printf("Invalid amount!");
        return 0;
    }

    discount = calculateDiscount(amount);
    final = calculateFinalAmount(amount, discount);

    displayReceipt(name, amount, discount, final);

    return 0;
}
