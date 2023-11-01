# Assignment 4 
###### P.S. use a markdown viewer to open file 
### Table of Contents

- [Banking System](#banking-system)
- [Complex Number Calculator](#complex-number-calculator)
- [Color List Operations](#color-list-operations)

## Banking System

This is a C program for a simple banking system that allows you to create and manage accounts, perform transactions, and view account information.

### Features 

- Create and Delete Savings and Current accounts with a unique account number.
- Perform transactions such as deposits and withdrawals.
- Display account information, including account number, type, name, and balance.
- Identify low-balance accounts with balances below Rs 100.


### Data Structures and Global Variables

1. **Enum AccountType**: This enumeration defines two account types, 'SAVINGS' and 'CURRENT.'

2. **struct AccountInfo**:
   - This structure is used to represent the essential information related to a bank account.
   - The structure includes the following fields:
     - **accountNumber**: An integer representing the unique account number assigned to each account.
     - **accountBalance**: A floating-point number indicating the current balance in the account.
     - **accountType**: An enum value (`savings` or `current`) that specifies the type of the account.
     - **holderName**: A character array (string) that stores the name of the account holder.

3. **struct Account**:
   - This structure is designed to function as a node in a linked list of bank accounts. 
   - The structure includes the following fields::
     - **accountInfo**: An instance of the `AccountInfo` structure that stores the specific account information (account number, balance, type, and name).
     - **nextAccount**: A pointer to the next node in the linked list. This pointer allows for the construction of a linked list of account nodes, making it easy to traverse and manage a collection of accounts.
   - The linked list of `struct Account` nodes forms the basis for maintaining and managing the bank's account records.


4. **ACCOUNTS**: A global linked list of accounts to store the active accounts.

5. **DELACCOUNTS**: A global linked list to store deleted accounts for potential reusage.

### Functions

1. **createAccount(enum AccountType type, char *name, float balance)**: Creates a new account based on the given account type, name, and initial balance. It checks for duplicate accounts and reuses account numbers of delted accounts if possible.

2. **deleteAccount(enum AccountType type, char *name)**: Deletes an existing account by its account type and name. The deleted account number can be reused later.

3. **transaction(int accountNumber, float amount, int transactiontype)**: Performs a transaction (withdrawal or deposit) on a specified account. transactiontype could be 0 for withdrawl and 1 for deposit 

4. **display**: Displays information about all accounts in a tabular format.

5. **lowBalanceAccounts**: Lists accounts with a balance lower than Rs 100.

6. **checkinpacctype**: Checks and validates the input account type.

7. **sortAccounts**: Sorts both `ACCOUNTS` and `DELACCOUNTS` linked lists, ensuring that account numbers are allocated correctly.

There are some more helper functions defined to avoid repetitive code like **checkinpacctype**: Checks and validates the input account type, **sortAccounts**: Sorts both `ACCOUNTS` and `DELACCOUNTS` linked lists, ensuring that account numbers are allocated correctly , **sort_Linkedlist**: Sorts the linked list of accounts based on account numbers.

### Main Function

The `main` function sets up the banking system and enters a loop to continuously accept user commands. The available commands are:


### Commands

The program supports the following commands:

- `CREATE <AccountType> <Name> <Amount>`: Create a new account. `AccountType` can be "SAVINGS" or "CURRENT". Name should **not have spaces**
- `DELETE <AccountType> <Name>`: Delete an existing account. `AccountType` can be "SAVINGS" or "CURRENT".
- `TRANSACTION <AccountNumber> <Amount> <Code>`: Perform a transaction, where `Code` is 0 for withdrawal and 1 for deposit.
- `LOWBALANCE`: Display all accounts with a balance less than 100.
- `DISPLAY`: Display information about all accounts.
- `HELP`: List available commands.
- `EXIT`: Exit the program.

### Code Assumptions and limitations 

- Account numbers are generated incrementally, starting from 100.
- Account names are limited to 50 characters and **Account holder names cannot contain spaces**.
- The program uses a linked list data structure to manage accounts.
- The program assumes that minimum balance in a account is Rs 100, and account is low balance only when balance < 100 ( note strict inequality sign )
- The initial state includes no accounts, and the first created account will have number 100.
- There is no persistent data storage; all accounts and data are lost when the program exits.
- The program assumes that input values are correctly formatted and within expected ranges. Error handling for invalid inputs is minimal.
- The transaction amount should be specified as an absolute value, and the program does not consider overdraft limits or negative account balances.
- The program does not support multiple users with same names and same account types

## Complex Number Calculator

This is a C program that allows you to perform various operations with complex numbers. You can use this program to add, subtract, compute the dot product, and calculate the cosine similarity of complex vectors.

### Compiling 
while compiling make sure to include the -lm flag to properly link the math.h header file 
<pre>
#compiling code 
gcc q2.c -lm -o q2.out
#executing code 
./q2.out 
</pre>


### Functions and Data Structures

The code defines several functions for performing operations on complex numbers:

1. **add(complex c1, complex c2)**:
   - Calculates the sum of two complx numbers `c1` and `c2`.
   - Allocates memory for the result, initializes it, and returns the result as a new complex number.

2. **sub(complex c1, complex c2)**:
   - Calculates the difference between two complx numbers `c1` and `c2`.
   - Allocates memory for the result, initializes it, and returns the result as a new complex number.

3. **dot(complex c1, complex c2)**:
   - Computes the dot product of two complx numbers `c1` and `c2`.
   - Returns the result as a floating-point number.

4. **mod(complex c1)**:
   - Calculates the modulus (magnitude) of a complx number `c1`.
   - Returns the result as a floating-point number.

5. **cosineSimilarity(complex c1, complex c2)**:
   - Computes the cosine similarity between two complx numbers `c1` and `c2`.
   - Returns the result as a floating-point number representing the cosine of the angle between the vectors.

6. **printComplex(complex c)**:
   - Prints the coordinates of a complex number in the format (a1, a2, a3, ..., an).

7. **inputComplex(complex *c, int dimensions)**:
   - Initializes a complex number with the given number of dimensions and inputs the coordinates.
   - Dynamically allocates memory for the coordinates.

8. **freeComplexCoordinates(complex *c)**:
   - Frees the dynamically allocated memory for the coordinates of a complex number.
9.  **struct complex**:
   - This structure represents a complex number and is used for storing complex numbers.
   - It consists of two fields:
     - **dimension**: An integer representing the number of dimensions in the complex number.
     - **coordinates**: A dynamic array of floating-point numbers that stores the individual coordinates of the complex number.

### Main Function

The `main` function sets up the banking system and enters a loop to continuously accept user commands. The available commands are:

### Commands

The program supports the following commands:

- `ADD <n>`: Add two complex numbers of dimension `n`.
- `SUB <n>`: Subtract two complex numbers of dimension `n`.
- `DOT <n>`: Compute the dot product of two complex numbers of dimension `n`.
- `COSINE <n>`: Calculate the cosine similarity of two complex vectors of dimension `n`.
- `-1`: Exit the program.


### Code Limitations and Assumptions

- The program assumes that complex numbers have a fixed dimension specified by `<n>` when performing operations. It is important to provide the correct dimension to avoid errors.

- The program doesn't handle invalid inputs gracefully. Ensure that inputs are correctly formatted, and the dimensions match when performing operations.

## Color List Operations

This C program is designed to perform operations on a linked list of colors. It allows you to create a list of colors, remove duplicate colors, and print the modified linked list.


### Data Structures

- **Color Structure**: A structure named `Color` is defined to represent a color node in the linked list. It contains two fields:
    - `int index`: Stores the color value as an integer.
    - `struct Color *next`: A pointer to the next color node.

- **ColorList Pointer**: The type `ColorList` is defined as a pointer to the `Color` structure. It represents the linked list of colors.

### Functions

- **`appendColor`**: This function appends a new color to the end of the linked list. It takes two parameters:
    - `ColorList *C`: A pointer to the linked list to which the new color is appended.
    - `int index`: The color value to be added.

- **`removeDuplicates`**: This function removes duplicate colors from the linked list. It returns a new linked list without duplicates. It takes one parameter:
    - `ColorList C`: The input linked list with possible duplicate colors.

- **`printColorList`**: This function prints the elements of the linked list. It takes one parameter:
    - `ColorList C`: The linked list to be printed.

### Main Function

- **`main` Function**: The program's main function handles user input and interaction. It follows these steps:
    1. Accept the number of colors `n`.
    2. Accept color values one by one and create a linked list.
    3. Call the `removeDuplicates` function to remove duplicate colors.
    4. Print the modified linked list using the `printColorList` function.


### Usage

The program provides the following functionality:

- Enter the number of colors in the list.
- Enter the colors one by one.
- The program will remove duplicate colors and display the modified linked list.

### Code Assumptions and Limitaitons

- The code assumes that the user will provide the colors **in non decreasing order**.
- The program expects non-negative integer color indices.
- Input validation for color values is minimal. Ensure that inputs are correctly formatted to avoid errors.



