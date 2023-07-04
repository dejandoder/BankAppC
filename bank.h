#ifndef BANK_H
#define BANK_H

#include <stdbool.h>

void initializeAccounts();
void createAccount();
bool findAccount(int accountNumber, int *index);
void deposit();
void withdraw();
void transferFunds();
void printAccounts();

#endif