#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -----------------------------
// Banking System Code
// -----------------------------

char HELP[] = "\nCREATE <AccountType> <Name> <Amount>\n"
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
    float accountBalance;
    enum AccountType accountType;
    char holderName[50];
};

struct Account // Node of linked list of accounts
{
    struct AccountInfo accountInfo;
    struct Account *nextAccount;
};

typedef struct Account Account;
struct Account *ACCOUNTS = NULL;    // global linked list of accounts
struct Account *DELACCOUNTS = NULL; // deleted accounts

void createAccount(enum AccountType type, char *name, float balance) // create account according to question
{
    int accountNumber = 100; // default account number is 100 ( according to question )
    for (Account *A = ACCOUNTS; A != NULL; A = A->nextAccount) // check if the account already exists or not
    {
        if (A->accountInfo.accountType == type && (strcmp(A->accountInfo.holderName, name) == 0))
        {
            printf("  Invalid :   Account already exists\n");
            return;
        }
    }

    if (ACCOUNTS == NULL && DELACCOUNTS == NULL) // initial state ( making bank's first account )
    {
        // make a new ( first ) account in ACCOUNTS
        ACCOUNTS = (Account *)malloc(sizeof(Account));
        ACCOUNTS->accountInfo.accountNumber = 100;
        strcpy(ACCOUNTS->accountInfo.holderName, name);
        ACCOUNTS->accountInfo.accountBalance = balance;
        ACCOUNTS->accountInfo.accountType = type;
        ACCOUNTS->nextAccount = NULL;
    }
    else if (DELACCOUNTS != NULL) // reusing deleted account number
    {
        // in case an account was previously deleted 
        // we can reuse that account number and make a new account in ACCOUNTS
        Account *reuse = DELACCOUNTS;
        DELACCOUNTS = DELACCOUNTS->nextAccount;
        strcpy(reuse->accountInfo.holderName, name);
        reuse->accountInfo.accountBalance = balance;
        reuse->accountInfo.accountType = type;
        reuse->nextAccount = NULL;
        accountNumber = reuse->accountInfo.accountNumber;
        if (ACCOUNTS == NULL) 
            ACCOUNTS = reuse;
        else
        {
            Account *lastacc = ACCOUNTS;
            while (lastacc->nextAccount != NULL)
            {
                lastacc = lastacc->nextAccount;
            }
            lastacc->nextAccount = reuse;
        }
    }
    else // making new account ( not reusing deleted account number)
    {
        // if no accounts were previously deleted we make a new account in ACCOUNTS
        Account *lastacc = ACCOUNTS;
        while (lastacc->nextAccount != NULL)
        {
            lastacc = lastacc->nextAccount;
        }
        lastacc->nextAccount = (Account *)malloc(sizeof(Account));
        lastacc->nextAccount->accountInfo.accountNumber = lastacc->accountInfo.accountNumber + 1;
        strcpy(lastacc->nextAccount->accountInfo.holderName, name);
        lastacc->nextAccount->accountInfo.accountBalance = balance;
        lastacc->nextAccount->accountInfo.accountType = type;
        accountNumber = lastacc->nextAccount->accountInfo.accountNumber;
    }
    printf("Created Account \n Account Number  : %d \n Name   \t : %s \n Type   \t : %s \n Balance   \t : Rs %.2f\n", accountNumber, name, type == 0 ? "Savings" : "Current", balance);
}

void deleteAccount(enum AccountType type, char *name) // delete account according to question
{

    int f = 1, delaccnum;
    for (Account *A = ACCOUNTS; A != NULL; A = A->nextAccount)
    {
        if (A->accountInfo.accountType == type && (strcmp(A->accountInfo.holderName, name) == 0))
        {
            f = 0;
            delaccnum = A->accountInfo.accountNumber; // finding account number of account to be deleted
            break;
        }
    }
    if (f)
    {
        printf("  Invalid :   Account doesn't exist\n");

        return;
    }
    Account *A = ACCOUNTS;
    if (A->accountInfo.accountNumber == delaccnum) // deleting first account
    {

        ACCOUNTS = ACCOUNTS->nextAccount;
        Account *D = DELACCOUNTS;
        A->nextAccount = NULL;
        // add deleted account to a linked list of deleted accounts DELACCOUNTS
        if (D == NULL)
        {
            DELACCOUNTS = A;
        }
        else
        {
            while (D->nextAccount != NULL)
            {
                D = D->nextAccount;
            }
            D->nextAccount = A;
        }
    }
    else
    {
        // deleting account which isnt the first account
        while (A->nextAccount->accountInfo.accountNumber != delaccnum) 
        {
            A = A->nextAccount;
        }
        Account *temp = A->nextAccount;
        A->nextAccount = A->nextAccount->nextAccount;
        Account *D = DELACCOUNTS;
        temp->nextAccount = NULL;
        // add deleted account to a linked list of deleted accounts DELACCOUNTS
        if (D == NULL)
        {
            DELACCOUNTS = temp;
        }
        else
        {
            while (D->nextAccount != NULL)
            {
                D = D->nextAccount;
            }
            D->nextAccount = temp;
        }
    }
    printf("Account Deleted Successfully\n");
    return;
}

int cmp_links(const void *a, const void *b) // comparator function for sorting linked lists function
{
    Account **na = (Account **)a;
    Account **nb = (Account **)b;
    // comparison on basis of account numbers
    return (*na)->accountInfo.accountNumber - (*nb)->accountInfo.accountNumber;
}

int sizeof_Linkedlist(Account *l) // size of linked list function for sorting function
{
    if (l == NULL)
        return 0;
    return 1 + sizeof_Linkedlist(l->nextAccount);
}

Account *sort_Linkedlist(Account *L) // sorting account linkedlist list
{
    Account *l = L;
    if (l == NULL)
    {
        return NULL;
    }

    int s = sizeof_Linkedlist(l);
    Account *elems[s]; // well store all the accounts in an array and sort them
    for (int i = 0; i < s; i++)
    {
        elems[i] = l;
        l = l->nextAccount;
    }
    qsort(elems, s, sizeof(Account *), cmp_links); // using q sort for simplicity ;
    Account *head = elems[0]; // creating a new linked lists in sorted order and returning its head 
    for (int i = 0; i < s - 1; i++)
    {
        elems[i]->nextAccount = elems[i + 1];
    }

    elems[s - 1]->nextAccount = NULL;
    return head;
}

void sortAccounts()
{
    // sorting both ACCOUNTS and DELEACCOUNTS because the code logic depends on sorted linked lists
    // since we are (re)using deleted account numbers, to make sure
    // that account numbers are alocated properply we need to sort the linked list
    // because if no accounts are in DELACCOUNTS we simply create a new account with
    // account number = last account number + 1
    // also we always use the first account number in DELACCOUNTS to make a new account
    // in both cases we need the DELACCOUNTS and ACCOUNTS to be sorted

    ACCOUNTS = sort_Linkedlist(ACCOUNTS);
    DELACCOUNTS = sort_Linkedlist(DELACCOUNTS);
}

void printlinklist(Account *l) // defined for debugging purposes
{
    printf("--\n");
    while (l != NULL)
    {
        printf("%d \n", l->accountInfo.accountNumber);
        l = l->nextAccount;
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
               P->accountInfo.accountNumber,
               (P->accountInfo.accountType == savings) ? "Savings" : "Current",
               P->accountInfo.holderName,
               P->accountInfo.accountBalance);

        P = P->nextAccount;
    }
    printf("----------------------------------------------------------------------------------\n");
}
void lowBalanceAccounts() // display all low balance accounts accordin to question
{
    if (ACCOUNTS == NULL)
    {
        printf("  Invalid :   No accounts exist right now ! \n");
        return;
    }
    int f = 1;
    Account *Temp = ACCOUNTS; // making a temporary pointer to ACCOUNTS, since we do not wish to change ACCOUNTS ( its a global variable )
    while (Temp != NULL)
    {
        if (Temp->accountInfo.accountBalance < 100)
        {

            f = 0;
            break;
        }
        Temp = Temp->nextAccount;
    }
    Temp = ACCOUNTS; 
    if (f)
    {
        printf("All accounts have balance >= Rs 100 \n");
    }
    else
    {
        printf("Low balance accounts are : \n");
        while (Temp != NULL)
        {
            if (Temp->accountInfo.accountBalance < 100)
            {
                printf("Account Number: %d, Name: %s, Balance: %2.2f", Temp->accountInfo.accountNumber, Temp->accountInfo.holderName, Temp->accountInfo.accountBalance);
                f = 0;
            }
            Temp = Temp->nextAccount;
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
    while (A != NULL && A->accountInfo.accountNumber != accountNumber)
    {
        A = A->nextAccount;
    }
    if (A == NULL)
    {
        printf("  Invalid :   Account doesn't exist\n");
        return;
    }
    if (transactiontype == 1)
    {
        A->accountInfo.accountBalance += abs(amount);
    }
    else if (transactiontype == 0)
    {
        if (A->accountInfo.accountBalance - abs(amount) < 100)
        {
            printf("Insufficient Balance for withdrawl \n ");
            return;
        }
        else
        {
            A->accountInfo.accountBalance -= abs(amount);
        }
    }
    printf("Final Balance %8.2f \n ", A->accountInfo.accountBalance);
    return;
}

int main()
{

    printf("\n------------------------------\n WELCOME TO BANKING SYSTEM\n------------------------------\n\n");
    printf(" Enter HELP for a list of commands available \n\n");

    char holderName[50] ; 
    int accountNumber , transactiontype , accountType ;
    float amount , accountBalance;
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
            accountType = checkinpacctype();

            if (accountType == -1)
                continue;
            scanf("%s %f", holderName, &accountBalance);

            createAccount(accountType, holderName, accountBalance);
        }
        else if (strcmp(inp, "DELETE") == 0)
        {
            accountType = checkinpacctype();
            if (accountType == -1)
                continue;
            scanf("%s", holderName);
            deleteAccount(accountType, holderName);
        }
        else if (strcmp(inp, "TRANSACTION") == 0)
        {

            scanf("%d %f %d", &accountNumber, &amount, &transactiontype);
            if (transactiontype >> 1 != 0)
            {
                printf(" Invalid transaction code:   use 0 for withdrawl , 1 for deposit ");
                continue;
            }
            transaction(accountNumber, amount, transactiontype);
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
            printf(" Invalid input \n");
        }
    }

    return 0;
}
