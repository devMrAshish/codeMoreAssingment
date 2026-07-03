# Mini OOP Project — Bank Management System

**Internship:** C++ Programming Internship
**Week:** 4 · Task 1
**Difficulty:** Intermediate
**Category:** C++ Development

## About

A console-based Bank Management System built in C++ to demonstrate core
Object-Oriented Programming concepts. Users can create savings or current
accounts, deposit and withdraw funds, view account details, and apply
monthly interest/fees.

## OOP Concepts Demonstrated

| Concept | Where it's used |
|---|---|
| **Encapsulation** | `Account` keeps `accountNumber`, `holderName`, and `balance` as `protected`, exposed only through public methods. |
| **Abstraction** | `Account` is an abstract base class (`applyMonthlyUpdate()` and `accountType()` are pure virtual) — you can't create a plain `Account`, only its concrete subtypes. |
| **Inheritance** | `SavingsAccount` and `CurrentAccount` both inherit from `Account`. |
| **Polymorphism** | `withdraw()` and `applyMonthlyUpdate()` are overridden differently per account type and called through a base-class pointer. |

## Features

- Create Savings or Current accounts
- Deposit money
- Withdraw money (with account-specific rules: minimum balance for savings, overdraft limit for current)
- View a single account's details
- List all accounts
- Apply monthly interest (savings) / maintenance fee (current) to all accounts

## Files

```
BankManagementSystem.cpp   # Complete source code
README.md                  # This file
explanation.md             # Program flow explanation
```

## How to Compile & Run

```bash
g++ -std=c++17 -Wall -o bank BankManagementSystem.cpp
./bank
```

On Windows (with g++ installed, e.g. via MinGW):

```bash
g++ -std=c++17 -Wall -o bank.exe BankManagementSystem.cpp
bank.exe
```

## Sample Run

```
=====================================
   WELCOME TO MINI BANK MANAGEMENT
=====================================

--------- MAIN MENU ---------
1. Create New Account
2. Deposit Money
3. Withdraw Money
4. View Account Details
5. List All Accounts
6. Apply Monthly Update (interest/fees)
0. Exit
Enter your choice: 1
Enter account type (savings/current): savings
Enter account holder name: Alice Smith
Enter initial deposit amount: $1000
Account created successfully! Account No: 1001

...

----- All Accounts -----
Account No: 1001 | Holder: Alice Smith | Balance: $1184.50 | Type: Savings
Account No: 1002 | Holder: Bob Jones   | Balance: $-405.00 | Type: Current
-------------------------
```

## Author

Submitted as part of Week 4, Task 1 of the C++ Programming Internship.
