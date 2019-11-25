#include <stdio.h>
#include "myBank.h"

enum bool{no,yes};


int main(){
    enum bool exit=no;

    // do{
    //      char transType;
    //      printf("\nTransaction type?:");
    //      int input=scanf(" %c",&transType);
    //      printf("\n"); 
    while()
    while(exit==no){
        char transType;
        int accountNum;
        double amount;
        double rate;
        printf("\nTransaction type?:");
        while(scanf(" %c",&transType)!=1){
        // while(transType!='O' &&transType!='B' &&transType!='D' &&transType!='W' &&transType!='C' &&transType!='P' &&transType!='I' &&transType!='E')
        // {
            printf("You have inserted a wrong character, please try again!\n");
            printf("\nTransaction type?");
            scanf(" %c",&transType); 

         }
        printf("\n");
        switch(transType)
        {
        case 'O':
            printf("Initial deposit?:");
            scanf("%lf",&amount);
            printf("\n");
            newAccount(amount);
            break;
        case 'B':
            printf("Account number?:");
            scanf("%d",&accountNum);
            printf("\n");
            balance(accountNum);
            break;
        case 'D':
            printf("‫‪Account_number‬‬?:");
            scanf("%d",&accountNum);
            printf("\n");
            printf("‫‪Amount?:");
            scanf("%lf",&amount);
            printf("\n");
            deposit(accountNum,amount);
            break;
        case 'W':
            printf("‫‪Account_number‬‬?:");
            scanf("%d",&accountNum);
            printf("\n");
            printf("‫‪Amount?:");
            scanf("%lf",&amount);
            printf("\n");
            cashWithdraw(accountNum,amount);           
            break;
        case 'C':
            printf("Account number?:");
            scanf("%d",&accountNum);
            closeAccount(accountNum);
            break;
        case 'I':
            printf("‫‪‬‬ ‫‪Interest rate?:");
            scanf("%lf",&rate);
            interestRate(rate);
            break;
        case 'P':
            accountsDetails();
            break;
        case 'E':
            closeAll();
            printf("All the accounts are closed\n");
            exit=yes;
            break;
            
        default:
            printf("Invalid transaction");
            break;
        }
    }

    return 0;
}