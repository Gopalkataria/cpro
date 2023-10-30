# Assignment 4 

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
- The initial state includes no accounts, and the first created account will have number 100.
- There is no persistent data storage; all accounts and data are lost when the program exits.
- The program assumes that input values are correctly formatted and within expected ranges. Error handling for invalid inputs is minimal.
- The transaction amount should be specified as an absolute value, and the program does not consider overdraft limits or negative account balances.
- The program does not support multiple users with same names and same account types

## Complex Number Calculator

This is a C program that allows you to perform various operations with complex numbers. You can use this program to add, subtract, compute the dot product, and calculate the cosine similarity of complex vectors.
### Code Structure

The code is organized into several functions and a `main` function. It defines a `complex` structure to represent complex numbers. The functions include:

- `add`: Adds two complex numbers.
- `sub`: Subtracts two complex numbers.
- `dot`: Computes the dot product of two complex numbers.
- `cosineSimilarity`: Calculates the cosine similarity of two complex vectors.
- `printComplex`: Displays complex numbers.
- `inputComplex`: Reads and initializes complex numbers.
- `freeComplexCoordinates`: Frees the memory used by complex coordinates, to avoid memory leaks while using malloc
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

### Code Structure

The code consists of the following functions:

- `struct Color`: This structure represents a color node in the linked list. It contains an `index` to store the color value and a `next` pointer to the next color node.

- `ColorList`: This is a pointer to the `struct Color` and represents the linked list of colors.

- `appendColor`: A function to append a color to the end of the linked list.

- `removeDuplicates`: A function to remove duplicate colors from the linked list.

- `printColorList`: A function to print the linked list of colors.

### Usage

The program provides the following functionality:

- Enter the number of colors in the list.
- Enter the colors one by one.
- The program will remove duplicate colors and display the modified linked list.

### Code Assumptions and Limitaitons

- The code assumes that the user will provide the colors **in non decreasing order**.
- The program expects non-negative integer color indices.
- Input validation for color values is minimal. Ensure that inputs are correctly formatted to avoid errors.



