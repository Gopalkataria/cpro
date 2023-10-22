#include <stdio.h>

enum AccountType
{
    Savings,
    Current
};
struct AccountInfo
{
    int accountNumber;
    float accountBalance;
    enum AccountType accountType;
    char name[50];
};

void display(struct AccountInfo *Accounts, int n)
{
    printf("\nAccount Number \t Account Type \t  Name \t\t\t Balance");
    printf("\n--------------------------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\n %-15d %-16s %-15s %f", Accounts[i].accountNumber, Accounts[i].accountType == 0 ? "Savings" : "Current", Accounts[i].name, Accounts[i].accountBalance);
    }
}
void lowBalanceAccounts(struct AccountInfo *Accounts, int n)
{
    for (int i = 0; i < n; i++)
        if (Accounts[i].accountBalance < 100)
        {
            printf("\nAccount Number: %d, Name: %s", Accounts[i].accountNumber, Accounts[i].name);
        }
}

void transaction( )

int main()
{
    struct AccountInfo account[10];
    for (int i = 0; i < 10; i++)
    {
        account[i].accountNumber = i + 100;
        account[i].accountBalance = (i*i*9 + 70) % 300 ;
        account[i].accountType = i % 2;
        strcpy(account[i].name, "Nqweiort");
        account[i].name[0] = 'A' + i;
    }
    display(account, 10);
    lowBalanceAccounts(account, 10);
    return 0;
}