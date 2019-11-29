#ifndef _MYBANK_H_
#define _MYBANK_H_

#define NUMACCOUNTS 50//a constant that save the array size
#define AMOUNTSTATUS 2//a constant that save the account's status

extern double bank[AMOUNTSTATUS][NUMACCOUNTS];//declaration of bank accounts, in raw 0 - will save the amount and raw 1 will save the status of the account(close/open).

void newAccount(double amount);

void balance(int accountNum);

void deposit(int accountNum,double amount);

void cashWithdraw(int accountNum,double amount);

void closeAccount(int accountNum);

void interestRate(double rate);

void accountsDetails();

void closeAll();


#endif