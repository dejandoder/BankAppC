#include <stdio.h>
#include <stdbool.h>
#include "bank.h"

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char accountName[50];
    double balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void initializeAccounts() {
    accountCount = 0;
}

void createAccount() {
    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account name: ");
    scanf("%s", newAccount.accountName);
    printf("Enter initial balance: ");
    scanf("%lf", &newAccount.balance);

    accounts[accountCount++] = newAccount;
    printf("Account created successfully.\n");
}

bool findAccount(int accountNumber, int *index) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            *index = i;
            return true;
        }
    }
    return false;
}

void deposit() {
    int accountNumber, amount, index;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    if (findAccount(accountNumber, &index)) {
        accounts[index].balance += amount;
        printf("Deposit successful.\n");
    } else {
        printf("Account not found.\n");
    }
}

void withdraw() {
    int accountNumber, amount, index;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (findAccount(accountNumber, &index)) {
        if (accounts[index].balance >= amount) {
            accounts[index].balance -= amount;
            printf("Withdrawal successful.\n");
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void transferFunds() {
    int senderAccount, receiverAccount, amount, senderIndex, receiverIndex;
    printf("Enter sender account number: ");
    scanf("%d", &senderAccount);
    printf("Enter receiver account number: ");
    scanf("%d", &receiverAccount);
    printf("Enter amount to transfer: ");
    scanf("%d", &amount);

    if (findAccount(senderAccount, &senderIndex) && findAccount(receiverAccount, &receiverIndex)) {
        if (accounts[senderIndex].balance >= amount) {
            accounts[senderIndex].balance -= amount;
            accounts[receiverIndex].balance += amount;
            printf("Transfer successful.\n");
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("One or both accounts not found.\n");
    }
}

void printAccounts() {
    printf("Account Information:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Name: %s\n", accounts[i].accountName);
        printf("Balance: %.2lf\n\n", accounts[i].balance);
    }
}
