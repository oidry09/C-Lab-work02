#include <stdio.h>

int checkBalance(int balance, int amount) {
    if (balance >= amount)
        return 1;
    else
        return 0;
}

int validateWithdrawal(int amount) {
    if (amount > 0 && amount % 500 == 0)
        return 1;
    else
        return 0;
}

int withdrawMoney(int balance, int amount) {
    return balance - amount;
}

void displayTransaction(int status, int amount, int balance) {
    if (status == 1) {
        printf("\nTransaction Status : Successful\n");
        printf("Amount Withdrawn   : Tk %d\n", amount);
        printf("Remaining Balance  : Tk %d\n", balance);
    } else {
        printf("\nTransaction Status : Failed\n");
        printf("Remaining Balance  : Tk %d\n", balance);
    }
}

int main() {
    int balance, amount, newBalance;
    int valid, sufficient;

    printf("Enter account balance: ");
    scanf("%d", &balance);
    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    valid = validateWithdrawal(amount);
    sufficient = checkBalance(balance, amount);

    if (valid == 1 && sufficient == 1) {
        newBalance = withdrawMoney(balance, amount);
        displayTransaction(1, amount, newBalance);
    } else {
        displayTransaction(0, amount, balance);
    }

    return 0;
}
