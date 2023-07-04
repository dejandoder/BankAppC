#include <stdio.h>
#include "bank.h"

int main() {
    int choice;
    initializeAccounts();

    do {
        printf("Bank Application\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer Funds\n");
        printf("5. Print Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transferFunds();
                break;
            case 5:
                printAccounts();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid command. Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}