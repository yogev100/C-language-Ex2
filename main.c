#include <stdio.h>
#include "myBank.h"


enum bool{no,yes};//a new type variable for knowing when to close all the accounts.

int main(){
    enum bool exit=no;

    while(exit==no){
        char transType;//input of transaction
        int accountNum;//input of account number
        double amount;//input of amount
        double rate;//input of rate
        printf("\nTransaction type?:\n");
        if(scanf(" %c",&transType)!=1){
            printf("You have inserted a wrong character, please try again!\n");
            continue;
        }
        else {
        
        switch(transType)//the standard cases, each case check if the input is valid , and if not - returns to the next iteration.
        {
        case 'O':
            printf("Initial deposit?:\n");
            if(scanf("%lf",&amount)==1){
                newAccount(amount);
            }
            else{
                printf("You have inserted a wrong amount, please try again!\n");
            }
            break;
        case 'B':
            printf("Account number?:\n");
            if(scanf("%d",&accountNum)==1){
                balance(accountNum);
            }
            else {
                printf("You have inserted a wrong account number, please try again!\n");
            }

            break;
        case 'D':
            printf("‫‪Account_number‬‬?:\n");
            if(scanf("%d",&accountNum)==1){
                printf("‫‪Amount?:\n");
                if(scanf("%lf",&amount)==1){
                    deposit(accountNum,amount);
                }
                else {
                    printf("You have inserted a wrong amount, please try again!\n");                    
                }
            }
            else {
                printf("You have inserted a wrong account number, please try again!\n");
            }
            break;
        case 'W':
            printf("‫‪Account_number‬‬?:\n");
            if(scanf("%d",&accountNum)==1){
                printf("‫‪Amount?:\n");
                if(scanf("%lf",&amount)==1){
                    cashWithdraw(accountNum,amount);
                }
                else {
                    printf("You have inserted a wrong amount, please try again!\n");
                }
            }
            else {
                printf("You have inserted a wrong account number, please try again!\n");
            }
            break;
        case 'C':
            printf("Account number?:\n");
            if(scanf("%d",&accountNum)==1){
                closeAccount(accountNum);
            }
            else {
                printf("You have inserted a wrong account number, please try again!\n");
            }       

            break;
        case 'I':
            printf("‫‪‬‬ ‫‪Interest rate?:\n");
            if(scanf("%lf",&rate)==1){
                interestRate(rate);
            }
            else{
                printf("You have inserted a wrong rate, please try again!\n");
            }
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
            printf("Invalid transaction\n");
            break;
            }
        }
    }

    return 0;
}
