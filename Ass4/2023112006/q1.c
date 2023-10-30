#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -----------------------------
// Banking System Code
// -----------------------------

char HELP[] = "CREATE <AccountType> <Name> <Amount>\n"
              "Create a new account, AccountType could be SAVINGS or CURRENT\n"
              "\n"
              "DELETE <AccountType> <Name>\n"
              "Delete an existing account, AccountType could be SAVINGS or CURRENT\n"
              "\n"
              "TRANSACTION <AccountNumber> <Amount> <Code> \n"
              "Perform a transaction of a given amount, Code 0 for withdrawl and 1 for deposit \n"
              "\n"
              "LOWBALANCE \n"
              "Display all the accounts with balance < 100  \n"
              "\n"
              "DISPLAY \n"
              "Display all info about all the accounts \n"
              "\n"
              "HELP \n"
              "List all the available commands \n"
              "\n"
              "EXIT\n"
              "Exit the program \n";

// Declaring all the structs and enums required for ( According the question instructions)

enum AccountType // Account type enum according to question
{
    savings,
    current
};

struct AccountInfo // Account info struct according to question
{
    int accountNumber;
    float balance;
    enum AccountType type;
    char name[50];
};

struct Account // Node of linked list of accounts
{
    struct AccountInfo info;
    struct Account *next;
};

typedef struct Account Account;
struct Account *ACCOUNTS = NULL;    // global linked list of accounts
struct Account *DELACCOUNTS = NULL; // deleted accounts

void createAccount(enum AccountType type, char *name, float balance) // create account according to question
{
    int accountNumber = 100;
    for (Account *A = ACCOUNTS; A != NULL; A = A->next)
    {
        if (A->info.type == type && (strcmp(A->info.name, name) == 0))
        {
            printf(" \033[1;31mInvalid : \033[0m Account already exists\n");
            return;
        }
    }

    if (ACCOUNTS == NULL && DELACCOUNTS == NULL) // initial state ( making bank's first account )
    {
        ACCOUNTS = (Account *)malloc(sizeof(Account));
        ACCOUNTS->info.accountNumber = 100;
        strcpy(ACCOUNTS->info.name, name);
        ACCOUNTS->info.balance = balance;
        ACCOUNTS->info.type = type;
        ACCOUNTS->next = NULL;
    }
    else if (DELACCOUNTS != NULL) // reusing deleted account number
    {
        Account *temp = DELACCOUNTS;
        DELACCOUNTS = DELACCOUNTS->next;
        strcpy(temp->info.name, name);
        temp->info.balance = balance;
        temp->info.type = type;
        temp->next = NULL;
        accountNumber = temp->info.accountNumber;
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
    else // making new account ( not reusing deleted account number)
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
        accountNumber = lastacc->next->info.accountNumber;
    }
    printf("Created Account \n Account Number  : %d \n Name   \t : %s \n Type   \t : %s \n Balance   \t : Rs %.2f\n", accountNumber, name, type == 0 ? "Savings" : "Current", balance);
}

void deleteAccount(enum AccountType type, char *name) // delete account according to question
{

    int f = 1, delaccnum;
    for (Account *A = ACCOUNTS; A != NULL; A = A->next)
    {
        if (A->info.type == type && (strcmp(A->info.name, name) == 0))
        {
            f = 0;
            delaccnum = A->info.accountNumber; // finding account number of account to be deleted
            break;
        }
    }
    if (f)
    {
        printf(" \033[1;31mInvalid : \033[0m Account doesn't exist\n");

        return;
    }
    Account *A = ACCOUNTS;
    if (A->info.accountNumber == delaccnum) // deleting first account
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
        while (A->next->info.accountNumber != delaccnum) // deleting account which isnt the first account
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

int cmp_links(const void *a, const void *b) // comparator function for sorting linked lists function
{
    Account **na = (Account **)a;
    Account **nb = (Account **)b;
    return (*na)->info.accountNumber - (*nb)->info.accountNumber;
}

int sizeof_Linkedlist(Account *l) // size of linked list function for sorting function
{
    if (l == NULL)
        return 0;
    return 1 + sizeof_Linkedlist(l->next);
}

Account *sort_Linkedlist(Account *a) // sorting account linkedlist list
{
    Account *l = a;
    if (l == NULL)
    {
        return NULL;
    }

    int s = sizeof_Linkedlist(l);
    l = a;
    Account *elems[s];
    for (int i = 0; i < s; i++)
    {
        elems[i] = l;
        l = l->next;
    }
    qsort(elems, s, sizeof(Account *), cmp_links); // using q sort for speeed ;
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
    // sorting both ACCOUNTS and DELEACCOUNTS because the code logic depends on sorted linked lists
    ACCOUNTS = sort_Linkedlist(ACCOUNTS);
    DELACCOUNTS = sort_Linkedlist(DELACCOUNTS);
}

void printlinklist(Account *l) // defined for debugging purposes
{
    printf("--\n");
    while (l != NULL)
    {
        printf("%d \n", l->info.accountNumber);
        l = l->next;
    }
}

void display() // display all accounts according to question
{
    if (ACCOUNTS == NULL)
    {
        printf("No accounts exist right now\n");
        return;
    }
    printf("----------------------------------------------------------------------------------\n");
    Account *P = ACCOUNTS;
    printf("Account Number\t       Account Type \t     Name \t\t\t Balance\t \n");
    while (P != NULL)
    {

        printf(" %-20d  %-20s  %-25s  %8.2f\n",
               P->info.accountNumber,
               (P->info.type == savings) ? "Savings" : "Current",
               P->info.name,
               P->info.balance);

        P = P->next;
    }
    printf("----------------------------------------------------------------------------------\n");
}
void lowBalanceAccounts() // display all low balance accounts accordin to question
{
    if (ACCOUNTS == NULL)
    {
        printf(" \033[1;31mInvalid : \033[0m No accounts exist right now ! \n");
        return;
    }
    int f = 1;
    Account *P = ACCOUNTS;
    while (P != NULL)
    {
        if (P->info.balance < 100)
        {

            f = 0;
            break;
        }
        P = P->next;
    }
    P = ACCOUNTS;
    if (f)
    {
        printf("All accounts have balance >= Rs 100 \n");
    }
    else
    {
        printf("Low balance accounts are : \n");
        while (P != NULL)
        {
            if (P->info.balance < 100)
            {
                printf("Account Number: %d, Name: %s, Balance: %2.2f", P->info.accountNumber, P->info.name, P->info.balance);
                f = 0;
            }
            P = P->next;
        }
    }
}

enum AccountType checkinpacctype() // check input account type function for use while taking inputs for CREATE and DELETE commands to avoid repeating code
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

void transaction(int accountNumber, float amount, int transactiontype) // transaction function according to question ( transaction type withdrawl = 0 , deposit = 1 )
{
    Account *A = ACCOUNTS;
    // printf("%d %d %d\n", accountNumber, amount, transactiontype); // DEBUG
    while (A != NULL && A->info.accountNumber != accountNumber)
    {
        A = A->next;
    }
    if (A == NULL)
    {
        printf(" \033[1;31mInvalid : \033[0m Account doesn't exist\n");
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
    printf("Final Balance %8.2f \n ", A->info.balance);
    return;
}

int main()
{

    printf("\n------------------------------\n WELCOME TO BANKING SYSTEM\n------------------------------\n\n");
    printf(" Enter HELP for a list of commands available \n\n");

    struct AccountInfo info;
    int transactiontype;
    float amount;
    char inp[100];

    // ----------------------------------------------------------
    // Main while loop for taking inputs and evaluating them
    // ----------------------------------------------------------
    while (1)
    {
        sortAccounts();   // sort all linked linsts becuase code logic depends on it
        printf("\n-> ");  // DEBUG
        scanf("%s", inp); // scan only the first word of the command
        if (strcmp(inp, "CREATE") == 0)
        {
            info.type = checkinpacctype();

            if (info.type == -1)
                continue;
            scanf("%s %f", info.name, &info.balance);

            createAccount(info.type, info.name, info.balance);
        }
        else if (strcmp(inp, "DELETE") == 0)
        {
            info.type = checkinpacctype();
            if (info.type == -1)
                continue;
            scanf("%s", info.name);
            deleteAccount(info.type, info.name);
        }
        else if (strcmp(inp, "TRANSACTION") == 0)
        {

            scanf("%d %f %d", &info.accountNumber, &amount, &transactiontype);
            if (transactiontype >> 1 != 0)
            {
                printf("\033[1;31mInvalid transaction code: \033[0m use 0 for withdrawl , 1 for deposit ");
                continue;
            }
            transaction(info.accountNumber, amount, transactiontype);
        }
        else if (strcmp(inp, "DISPLAY") == 0)
        {
            display();
        }
        else if (strcmp(inp, "LOWBALANCE") == 0)
        {
            lowBalanceAccounts();
        }
        else if (strcmp(inp, "HELP") == 0)
        {
            printf("%s", HELP);
        }
        else if (strcmp(inp, "EXIT") == 0)
        {
            printf("Exiting now \n");
            return 0;
        }

        else
        {

            printf("\033[1;31mInvalid input\033[0m\n");
        }
    }

    return 0;
}
