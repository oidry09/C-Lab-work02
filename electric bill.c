#include <stdio.h>

// Function to calculate electricity bill
float calculateBill(float units)
{
    float charge;

    if(units < 0)
    {
        return -1;
    }
    else if(units <= 100)
    {
        charge = units * 5;
    }
    else if(units <= 200)
    {
        charge = (100 * 5) + (units - 100) * 6;
    }
    else
    {
        charge = (100 * 5) + (100 * 6)
                 + (units - 200) * 8;
    }

    return charge;
}

// Function to calculate VAT
float calculateVAT(float charge)
{
    float vat;

    vat = charge * 5 / 100;

    return vat;
}

// Function to display bill
void displayBill(int customerID, char name[],
                 float units, float charge,
                 float vat, float finalBill)
{
    printf("\n------ Electricity Bill ------\n");

    printf("Customer ID        : %d\n", customerID);
    printf("Customer Name      : %s\n", name);
    printf("Units Consumed     : %.0f\n", units);
    printf("Electricity Charge : Tk %.2f\n", charge);
    printf("VAT (5%%)           : Tk %.2f\n", vat);
    printf("Final Bill         : Tk %.2f\n", finalBill);
}

// Main function
int main()
{
    int customerID;
    char name[50];

    float units, charge, vat, finalBill;

    // Taking input
    printf("Enter customer ID: ");
    scanf("%d", &customerID);

    printf("Enter customer name: ");
    scanf(" %[^\n]", name);

    printf("Enter units consumed: ");
    scanf("%f", &units);

    // Checking invalid consumption
    if(units < 0)
    {
        printf("Invalid input! Units cannot be negative.\n");
        return 0;
    }

    // Function calling
    charge = calculateBill(units);

    vat = calculateVAT(charge);

    finalBill = charge + vat;

    // Displaying bill
    displayBill(customerID, name, units,
                charge, vat, finalBill);

    return 0;
}
