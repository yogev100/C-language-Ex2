#include <stdio.h>
#include "myBank.h"
#include <math.h>
#define NUMACCOUNTS 50//a constant that save the array size
#define AMOUNTSTATUS 2//a constant that save the account's status

double bank[AMOUNTSTATUS][NUMACCOUNTS]={0};//initial a bank accounts, in raw 0 - will save the amount and raw 1 will save the status of the account(close/open).


void twodigits(double x);//a void function that gets a double and make it at most with 2 digits after the point.


enum flag{false,true};//a new type variable for knowing if the accounts have been opened or no.

void newAccount(double amount){
    enum flag opened=false;
    for(int i = 0; i < NUMACCOUNTS; i++){
        if(bank[1][i]==0){
            bank[0][i]=amount;
            twodigits(bank[0][i]);//for 2 digits after the point.
            bank[1][i]=1;
            opened=true;//a new account is opened.
            printf("new account number:%d\n",901+i);//901+i - because requried  the account numbers will be between 901-950.
            return;
        }
    }
    if(opened==false){//a case that the bank is full.
        printf("the bank is full\n");
    }

}
void balance(int accountNum){
    if((accountNum>950)||(accountNum<901)){//a case that the user insert an invalid acounts number.
        printf("invalid account number\n");
        return;
    }
    else if(bank[1][accountNum-901]==0){//a case that the account number is closed right now.
        printf("the account is not opened yet or closed\n");
        return;
    }
    else {//the standrad case
        printf("your balance is:%0.2lf\n",bank[0][accountNum-901]);
    }
}

void deposit(int accountNum,double amount){// the 2 first cases are the same like one function before.
    if((accountNum>950)||(accountNum<901)){
        printf("invalid account number\n");
        return;
    }
    else if(bank[1][accountNum-901]==0){
        printf("the account is not opened yet or closed\n");
        return;
    }
    else if(amount<=0){// a case that the user want to deposit no money.
        printf("transaction falied\n");
        return;
    }
    else {//the standard case
        bank[0][accountNum-901]=bank[0][accountNum-901]+amount;// accountNum-901: because this is the real location for deposit in the array.
        twodigits(bank[0][accountNum-901]);//for 2 digits after the point.
        printf("your new balance is:%0.2lf\n",bank[0][accountNum-901]);
    }
}
void cashWithdraw(int accountNum,double amount){//the 2 first cases are the same like one function before.
    if((accountNum>950)||(accountNum<901)){
        printf("invalid account number\n");
        return;
    }
    else if(bank[1][accountNum-901]==0){
        printf("the account is not opened yet or closed\n");
        return;
    }
    else if(amount<=0){//a case that the user want to wihtdraw no money.
        printf("transaction falied\n");
        return;
    }
    else if(bank[0][accountNum-901]-amount<=0){//a case that the user want to withdraw less money than he has.
        printf("transaction failed\n");
        return;
    }
    else {//the standard case.
        twodigits(amount);//for 2 digits after the point.
        bank[0][accountNum-901]=bank[0][accountNum-901]-amount;
        printf("your new balance is:%0.2lf\n",bank[0][accountNum-901]);
    }

}
void closeAccount(int accountNum){
    if((accountNum>950)||(accountNum<901)){
        printf("invalid account number\n");
        return;
    }
    else if(bank[1][accountNum-901]==0){
        printf("the account is not opened yet or closed\n");
        return;
    }
    else {//the standard case - closing account
        bank[1][accountNum-901]=0;
        bank[0][accountNum-901]=0;
    }
}
void interestRate(double rate){
    rate=1+(rate/100);//a number that we will multiply with the amount of each account.(for get the right rate)
    for(int i=0;i<NUMACCOUNTS;i++){
        if(bank[1][i]==1){
            bank[0][i]=(bank[0][i])*rate;
            twodigits(bank[0][i]);//for 2 digits fater the point.

        }
    }
}
void accountsDetails(){
    for(int i=0;i<NUMACCOUNTS;i++){
        if(bank[1][i]==1){//enter only to opened accounts.
            printf("account number %d balance:%0.2lf\n",i+901,bank[0][i]);
        }
    }
}
void closeAll(){
    for(int i=0;i<NUMACCOUNTS;i++){
        if(bank[1][i]==1){//all the opened accounts will closed.
            bank[1][i]=0;
            bank[0][i]=0;
        }
    }
}
void twodigits(double x){
    int temp=x*100;
    x=temp;
    x=x/100;
}