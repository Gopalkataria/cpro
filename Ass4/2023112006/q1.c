#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum AccountType
{
    savings,
    current
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
    struct Account *next;
};

typedef struct Account Account;
struct Account *ACCOUNTS = NULL;
struct Account *DELACCOUNTS = NULL; // deleted accounts

void createAccount(enum AccountType type, char *name, float balance)
{
    for (Account *A = ACCOUNTS; A != NULL; A = A->next)
    {
        if (A->info.type == type && (strcmp(A->info.name, name) == 0))
        {
            printf(" Account already exists \n");
            return;
        }
    }

    if (ACCOUNTS == NULL && DELACCOUNTS == NULL) // initial state ( making banks first account )
    {
        ACCOUNTS = (Account *)malloc(sizeof(Account));
        ACCOUNTS->info.accountNumber = 100;
        strcpy(ACCOUNTS->info.name, name);
        ACCOUNTS->info.balance = balance;
        ACCOUNTS->info.type = type;
        ACCOUNTS->next = NULL;
    }
    else if (DELACCOUNTS != NULL) // there is a deleted account number which we can reuse
    {
        Account *temp = DELACCOUNTS;
        DELACCOUNTS = DELACCOUNTS->next;
        strcpy(temp->info.name, name);
        temp->info.balance = balance;
        temp->info.type = type;
        temp->next = NULL;
        if (ACCOUNTS == NULL)
            ACCOUNTS = temp;
        else
        {
            Account *lastacc = ACCOUNTS;
            while (lastacc->next != NULL)
            {
                lastacc = lastacc->next;
            }
            lastacc->next = temp;
        }
    }
    else
    {
        Account *lastacc = ACCOUNTS;
        while (lastacc->next != NULL)
        {
            lastacc = lastacc->next;
        }
        lastacc->next = (Account *)malloc(sizeof(Account));
        lastacc->next->info.accountNumber = lastacc->info.accountNumber + 1;
        strcpy(lastacc->next->info.name, name);
        lastacc->next->info.balance = balance;
        lastacc->next->info.type = type;
    }
}

void deleteAccount(enum AccountType type, char *name)
{

    int f = 1, delaccnum;
    for (Account *A = ACCOUNTS; A != NULL; A = A->next)
    {
        if (A->info.type == type && (strcmp(A->info.name, name) == 0))
        {
            f = 0;
            delaccnum = A->info.accountNumber;
            break;
        }
    }
    if (f)
    {
        printf(" Account doesnt exist \n");
        return;
    }
    Account *A = ACCOUNTS;
    if (A->info.accountNumber == delaccnum)
    {

        ACCOUNTS = ACCOUNTS->next;
        Account *P = DELACCOUNTS;
        A->next = NULL;
        if (P == NULL)
        {
            DELACCOUNTS = A;
        }
        else
        {
            while (P->next != NULL)
            {
                P = P->next;
            }
            P->next = A;
        }
    }
    else
    {
        while (A->next->info.accountNumber != delaccnum)
        {
            A = A->next;
        }
        Account *temp = A->next;
        A->next = A->next->next;
        Account *P = DELACCOUNTS;
        temp->next = NULL;
        if (P == NULL)
        {
            DELACCOUNTS = temp;
        }
        else
        {
            while (P->next != NULL)
            {
                P = P->next;
            }
            P->next = temp;
        }
    }
    printf("Account Deleted Successfully\n");
    return;
}

int cmp_links(const void *a, const void *b)
{
    Account **na = (Account **)a;
    Account **nb = (Account **)b;
    return (*na)->info.accountNumber - (*nb)->info.accountNumber;
}

int sizeof_Linkedlist(Account *l)
{
    if (l == NULL)
        return 0;
    return 1 + sizeof_Linkedlist(l->next);
}

Account *sort_Linkedlist(Account *l)
{
    if (l == NULL)
    {
        return NULL;
    }

    int s = sizeof_Linkedlist(l);
    Account *elems[s];
    for (int i = 0; i < s; i++)
    {
        elems[i] = l;
        l = l->next;
    }
    qsort(elems, s, sizeof(Account *), cmp_links);
    Account *head = elems[0];
    for (int i = 0; i < s - 1; i++)
    {
        elems[i]->next = elems[i + 1];
    }

    elems[s - 1]->next = NULL;
    return head;
}

void sortAccounts()
{
    sort_Linkedlist(ACCOUNTS);
    sort_Linkedlist(DELACCOUNTS);
}



void display()
{
    if (ACCOUNTS == NULL)
    {
        printf("No accounts exist right now\n");
        return;
    }
    printf("-------------------------------------------------\n");
    Account *P = ACCOUNTS;
    printf("Account Number\t       Account Type \t     Name \t\t\t Balance\t \n");
    while (P != NULL)
    {

        // printf(" %d    %s \t\t %4.2f \t\t %s \t \n", P->info.accountNumber, P->info.name, P->info.balance, P->info.type == savings ? "Savings" : "Current");
        printf(" %-20d  %-20s  %-25s  %8.2f\n",
               P->info.accountNumber,
               (P->info.type == savings) ? "Savings" : "Current",
               P->info.name,
               P->info.balance);

        P = P->next;
    }
    printf("-------------------------------------------------\n\n");
}
void lowBalanceAccounts()
{
    if (ACCOUNTS == NULL)
    {
        printf("No accounts exist right now ! \n");
        return;
    }
    int f = 1 ; 
    Account *P = ACCOUNTS;
    printf(" Number Name \t\t\t balance \t \t Type\t \n");
    while (P != NULL)
    {
        if( P->info.balance < 100 ){
            printf("Account Number: %d, Name: %s, Balance: %2.2f", P->info.accountNumber , P->info.name , P->info.balance) ; 
            f = 0 ; 
        }
        P = P->next;
    }
    if ( f) {
        printf("All accounts have balance >= Rs 100 \n") ; 
    }
}

enum AccountType checkinpacctype()
{
    char acctype[100];
    scanf("%s", acctype);
    if (strcmp(acctype, "SAVINGS") == 0)
        return savings;
    else if (strcmp(acctype, "CURRENT") == 0)
        return current;
    else
    {
        printf("Invalid Account Type %s \n", acctype);
        scanf("%[^\n]", acctype); // clean the input line in case of stray inputs remaining from last command
        return -1;
    }
}

void transaction(int accountNumber , float amount, int transactiontype)
{
    Account *A = ACCOUNTS;
    while (A->info.accountNumber != accountNumber && A != NULL)
    {
        A = A->next;
    }
    if (A == NULL)
    {
        printf("Account doesnt exist \n ");
        return;
    }
    if (transactiontype == 1)
    {
        A->info.balance += abs(amount);
    }
    else if (transactiontype == 0)
    {
        if (A->info.balance - abs(amount) < 100)
        {
            printf("Insufficient Balance for withdrawl \n ");
            return;
        }
        else
        {
            A->info.balance -= abs(amount);
        }
    }
    printf("Final Balance %f \n ", A->info.balance);
    return;
}

int main()
{

    printf("\n------------------------------\n WELCOME TO MY BANKING SYSTEM\n------------------------------\n\n");
    printf(" Enter HELP for a list of commands available \n\n");
    

    struct AccountInfo info;
    int transactiontype;
    float amount;
    char inp[100];
    while (1)
    {
        sortAccounts();   // sort all linked linsts in case user wants to print them
        printf("\n-> ");  // DEBUG
        scanf("%s", inp); // scan only the first word of the command
        if (strcmp(inp, "CREATE") == 0)
        {
            info.type = checkinpacctype();

            if (info.type == -1)
                continue;
            scanf("%s %f", info.name, &info.balance);
            printf("Created Account \n Name : %s \n Balance : %f \n Type : %s\n", info.name, info.balance, info.type == 0 ? "Savings" : "Current");
            createAccount(info.type, info.name, info.balance);
            continue;
        }
        else if (strcmp(inp, "DELETE") == 0)
        {
            info.type = checkinpacctype();
            if (info.type == -1)
                continue;
            scanf("%s", info.name);
            deleteAccount(info.type, info.name);
            continue;
        }
        else if (strcmp(inp, "TRANSACTION") == 0)
        {

            scanf("%d %f %d", &info.accountNumber, &amount, &transactiontype);
            if (transactiontype >> 1 != 0)
            {
                printf("Invalid transaction code, use 0 for withdrawl , 1 for deposit ");
                continue;
            }
            transaction(info.accountNumber, amount, transactiontype);
            continue;
        }
        else if (strcmp(inp, "DISPLAY") == 0)
        {
            display();
            continue;
        }
        else if (strcmp(inp, "LOWBALANCE") == 0)
        {
            lowBalanceAccounts();
            continue;
        }
        else if (strcmp(inp, "HELP") == 0)
        {
            printf("loLL yoU NeEeD hElP \n");
            return 0;
        }
        else if (strcmp(inp, "EXIT") == 0)
        {
            printf("Exiting now \n");
            return 0;
        }

        else
        {

            printf("invalid command entered \n ");
        }
    }

    return 0;
}
