#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -----------------------------
// Banking System Code
// -----------------------------

char HELP[] = "\nCREATE <AccountType> <Name> <Amount>\nCreate a new account, AccountType could be SAVINGS or CURRENT\n\nDELETE <AccountType> <Name>\nDelete an existing account, AccountType could be SAVINGS or CURRENT\n\nTRANSACTION <AccountNumber> <Amount> <Code> \nPerform a transaction of a given amount, Code 0 for withdrawl and 1 for deposit \n\nLOWBALANCE \nDisplay all the accounts with balance < 100  \n\nDISPLAY \nDisplay all info about all the accounts \n\nHELP \nList all the available commands \n\nEXIT\nExit the program \n";

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
struct Account *ACCOUNTS = NULL; // global linked list of accounts

void createAccount(enum AccountType type, char *name, float balance) // create account according to question
{
    int accountNumber = 100;                                   // default account number is 100 ( according to question )
    for (Account *A = ACCOUNTS; A != NULL; A = A->nextAccount) // check if the account already exists or not
        if (A->accountInfo.accountType == type && (strcmp(A->accountInfo.holderName, name) == 0))
        {
            printf("  Invalid :   Account already exists\n");
            return;
        }

    if (ACCOUNTS == NULL) // initial state ( making bank's first account )
    {
        // make a new ( first ) account in ACCOUNTS
        ACCOUNTS = (Account *)malloc(sizeof(Account));
        ACCOUNTS->accountInfo.accountNumber = 100;
        strcpy(ACCOUNTS->accountInfo.holderName, name);
        ACCOUNTS->accountInfo.accountBalance = balance;
        ACCOUNTS->accountInfo.accountType = type;
        ACCOUNTS->nextAccount = NULL;
    }
    else // making new account
    {
        if (ACCOUNTS->accountInfo.accountNumber != 100)
        { // the first account isn't 100
            Account *Temp = (Account *)malloc(sizeof(Account));
            Temp->accountInfo.accountNumber = 100;
            strcpy(Temp->accountInfo.holderName, name);
            Temp->accountInfo.accountBalance = balance;
            Temp->accountInfo.accountType = type;
            Temp->nextAccount = ACCOUNTS;
            ACCOUNTS = Temp;
        }
        else
        {
            accountNumber++;
            Account *A = ACCOUNTS;
            while (A->nextAccount != NULL && A->nextAccount->accountInfo.accountNumber == accountNumber)
            {
                A = A->nextAccount;
                accountNumber++;
            }
            Account *Temp = A->nextAccount;
            A->nextAccount = (Account *)malloc(sizeof(Account));
            A->nextAccount->accountInfo.accountNumber = accountNumber;
            strcpy(A->nextAccount->accountInfo.holderName, name);
            A->nextAccount->accountInfo.accountBalance = balance;
            A->nextAccount->accountInfo.accountType = type;
            A->nextAccount->nextAccount = Temp;
        }
    }
    printf("Created Account \n Account Number  : %d \n Name   \t : %s \n Type   \t : %s \n Balance   \t : Rs %.2f\n", accountNumber, name, type == 0 ? "Savings" : "Current", balance);
}

void deleteAccount(enum AccountType type, char *name) // delete account according to question
{

    int f = 1, delaccnum;
    for (Account *A = ACCOUNTS; A != NULL; A = A->nextAccount)
        if (A->accountInfo.accountType == type && (strcmp(A->accountInfo.holderName, name) == 0))
        {
            f = 0;
            delaccnum = A->accountInfo.accountNumber; // finding account number of account to be deleted
            break;
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
        free(A);
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
        free(temp);
    }
    printf("Account Deleted Successfully\n");
    return;
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
                printf("Account Number: %d, Name: %s, Balance: %2.2f\n", Temp->accountInfo.accountNumber, Temp->accountInfo.holderName, Temp->accountInfo.accountBalance);
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
    while (A != NULL && A->accountInfo.accountNumber != accountNumber)
        A = A->nextAccount;
    if (A == NULL)
    {
        printf("  Invalid :   Account doesn't exist\n");
        return;
    }
    if (transactiontype == 1)
        A->accountInfo.accountBalance += abs(amount);
    else if (transactiontype == 0)
    {
        if (A->accountInfo.accountBalance - abs(amount) < 100)
        {
            printf("Insufficient Balance for withdrawl \n ");
            return;
        }
        else
            A->accountInfo.accountBalance -= abs(amount);
    }
    printf("Final Balance %8.2f \n ", A->accountInfo.accountBalance);
    return;
}

int main()
{

    printf("\n------------------------------\n WELCOME TO BANKING SYSTEM\n------------------------------\n\n");
    printf(" Enter HELP for a list of commands available \n\n");

    char holderName[50], inp[100];
    int accountNumber, transactiontype, accountType;
    float amount, accountBalance;

    // ----------------------------------------------------------
    // Main while loop for taking inputs and evaluating them
    // ----------------------------------------------------------
    while (1)
    {
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
            display();
        else if (strcmp(inp, "LOWBALANCE") == 0)
            lowBalanceAccounts();
        else if (strcmp(inp, "HELP") == 0)
            printf("%s", HELP);
        else if (strcmp(inp, "EXIT") == 0)
        {
            printf("Exiting now \n");
            return 0;
        }

        else
            printf(" Invalid input \n");
    }

    return 0;
}
