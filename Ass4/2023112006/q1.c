#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum AccountType
{
    Savings,
    Current
};

struct AccountInfo
{
    int accountNumber;
    float balance;
    enum AccountType type;
    char name[50];
};

struct Account
{
    struct AccountInfo info;
    int active;
    struct Account *next;
};

typedef struct Account Account;
struct Account *ACCOUNTS = NULL;
struct Account *DELACCOUNTS = NULL ; // deleted accounts

void createAccount(struct AccountInfo info)
{
    Account *P = ACCOUNTS;
    if (P->active == 0)
    {
        P->info.balance = info.balance;
        strcpy(P->info.name, info.name);
        P->info.balance = info.balance;
        P->active = 1;
        return;
    }
    else
    {
        while (P->active != 0 && P->next != NULL)
        {
            P = P->next;
        }
        if (P->active == 0)
        {
            P->info.balance = info.balance;
            strcpy(P->info.name, info.name);
            P->info.balance = info.balance;
            P->active = 1;
            return;
        }
       
        if (P->next == NULL)
        {
            P->next = (Account *)malloc(sizeof(Account));
            P->next->info.balance = info.balance;
            P->next->info.accountNumber = P->info.accountNumber + 1;
            strcpy(P->next->info.name, info.name);
            P->next->info.balance = info.balance;
            P->next->active = 1;
            P->next->next = NULL;
            return;
        }
    }
}

void printAccounts()
{
    printf("------------------------------------------------------------\n");
    Account *P = ACCOUNTS;
    int f = 1;
    printf(" Number Name \t\t\t balance \t \t Type\t Active\n"); 
    while (P != NULL)
    {
        if (P->active)
        {
            printf(" %d    %s \t\t %f \t %s \t %d\n", P->info.accountNumber, P->info.name, P->info.balance, P->info.type == Savings ? "Savings" : "Current", P->active);
            f = 0;
        }
        P = P->next;
    }
    if (f)
        printf("No accounts exist right now\n");
    printf("------------------------------------------------------------\n\n");
}

void deleteAccount(struct AccountInfo info)
{
    Account *P = ACCOUNTS;
    int f= 1 ; 

    if (P->info.accountNumber == info.accountNumber)
    {
        P->active = 0;
        f = 0 ; 
        return;
    }
    else
    {
        while (P->next != NULL)
        {
            if (P->info.accountNumber == info.accountNumber)
            {
                P->active = 0;
                f = 0 ; 
                return;
            }
            P = P->next;
        }
    }
    if ( f) printf("Account %s does not exist\n", info.name );
}

int main()
{
    struct Account firstAccount;
    firstAccount.info.accountNumber = 100;
    firstAccount.next = NULL;
    firstAccount.active = 0;
    ACCOUNTS = &firstAccount;

    struct AccountInfo Jethalal = {100, 1000.0, Savings, "Jethalal"};
    struct AccountInfo Champak = {105, 10.0, Savings, "Champak Lal"};
    struct AccountInfo Babita = {100, 150.0, Current, "Babita Ji"};
    struct AccountInfo Daya = {100, 500.0, Savings, "Daya Ben"};

    createAccount(Jethalal);
    createAccount(Babita);
    createAccount(Daya);
    printAccounts();


    deleteAccount(Jethalal);
   deleteAccount(Champak) ; 
    printAccounts();


    return 0;
}
