/*
    Mini OOP Project: Bank Management System
    ------------------------------------------
    Demonstrates core OOP concepts in C++:
        - Classes and Objects
        - Encapsulation (private data, public methods)
        - Inheritance (SavingsAccount, CurrentAccount derived from Account)
        - Polymorphism (virtual functions for interest/withdrawal rules)
        - Abstraction (base class hides implementation details)

    Author: (Ashish Kumar)
    Week 4 - Task 1
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ---------------------------------------------------------
// Base Class: Account  (Abstraction + Encapsulation)
// ---------------------------------------------------------
class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double initialDeposit)
        : accountNumber(accNo), holderName(name), balance(initialDeposit) {}

    virtual ~Account() {}

    int getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << fixed << setprecision(2);
        cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    // Virtual so derived classes can enforce different withdrawal rules (Polymorphism)
    virtual bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return false;
        }
        balance -= amount;
        cout << fixed << setprecision(2);
        cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        return true;
    }

    // Pure-ish virtual "hook" for account-specific extras (interest, overdraft, etc.)
    virtual void applyMonthlyUpdate() = 0;

    virtual void displayInfo() const {
        cout << fixed << setprecision(2);
        cout << "Account No: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: $" << balance
             << " | Type: " << accountType() << "\n";
    }

    virtual string accountType() const = 0;
};

// ---------------------------------------------------------
// Derived Class: SavingsAccount (Inheritance + Polymorphism)
// ---------------------------------------------------------
class SavingsAccount : public Account {
private:
    double interestRate; // e.g., 0.03 = 3%

public:
    SavingsAccount(int accNo, string name, double initialDeposit, double rate = 0.03)
        : Account(accNo, name, initialDeposit), interestRate(rate) {}

    // Savings accounts cannot go below a minimum balance of $100
    bool withdraw(double amount) override {
        const double MIN_BALANCE = 100.0;
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive.\n";
            return false;
        }
        if (balance - amount < MIN_BALANCE) {
            cout << "Withdrawal denied: Savings account must maintain a $"
                 << MIN_BALANCE << " minimum balance.\n";
            return false;
        }
        balance -= amount;
        cout << fixed << setprecision(2);
        cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        return true;
    }

    void applyMonthlyUpdate() override {
        double interest = balance * interestRate;
        balance += interest;
        cout << fixed << setprecision(2);
        cout << "Interest applied to Account " << accountNumber
             << ": +$" << interest << " -> New balance: $" << balance << "\n";
    }

    string accountType() const override { return "Savings"; }
};

// ---------------------------------------------------------
// Derived Class: CurrentAccount (Inheritance + Polymorphism)
// ---------------------------------------------------------
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, string name, double initialDeposit, double overdraft = 500.0)
        : Account(accNo, name, initialDeposit), overdraftLimit(overdraft) {}

    // Current accounts allow overdraft up to a limit
    bool withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance + overdraftLimit) {
            cout << "Withdrawal denied: exceeds overdraft limit of $"
                 << overdraftLimit << ".\n";
            return false;
        }
        balance -= amount;
        cout << fixed << setprecision(2);
        cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        return true;
    }

    // Current accounts have no interest, but a small monthly maintenance fee
    void applyMonthlyUpdate() override {
        const double FEE = 5.0;
        balance -= FEE;
        cout << fixed << setprecision(2);
        cout << "Maintenance fee applied to Account " << accountNumber
             << ": -$" << FEE << " -> New balance: $" << balance << "\n";
    }

    string accountType() const override { return "Current"; }
};

// ---------------------------------------------------------
// Bank Class: manages a collection of Account objects
// ---------------------------------------------------------
class Bank {
private:
    vector<Account*> accounts;
    int nextAccountNumber;

public:
    Bank() : nextAccountNumber(1001) {}

    ~Bank() {
        for (Account* acc : accounts) delete acc;
    }

    Account* createAccount(const string& type, const string& name, double initialDeposit) {
        Account* newAcc = nullptr;
        if (type == "savings" || type == "S" || type == "s") {
            newAcc = new SavingsAccount(nextAccountNumber, name, initialDeposit);
        } else if (type == "current" || type == "C" || type == "c") {
            newAcc = new CurrentAccount(nextAccountNumber, name, initialDeposit);
        } else {
            cout << "Unknown account type.\n";
            return nullptr;
        }
        accounts.push_back(newAcc);
        cout << "Account created successfully! Account No: " << nextAccountNumber << "\n";
        nextAccountNumber++;
        return newAcc;
    }

    Account* findAccount(int accNo) {
        for (Account* acc : accounts) {
            if (acc->getAccountNumber() == accNo) return acc;
        }
        return nullptr;
    }

    void listAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts found.\n";
            return;
        }
        cout << "\n----- All Accounts -----\n";
        for (Account* acc : accounts) {
            acc->displayInfo();
        }
        cout << "-------------------------\n";
    }

    void applyMonthlyUpdatesToAll() {
        cout << "\n--- Applying monthly updates to all accounts ---\n";
        for (Account* acc : accounts) {
            acc->applyMonthlyUpdate();
        }
    }
};

// ---------------------------------------------------------
// Helper: safely read an integer from user input
// ---------------------------------------------------------
int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else {
            return value;
        }
    }
}

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else {
            return value;
        }
    }
}

// ---------------------------------------------------------
// Main: menu-driven console interface
// ---------------------------------------------------------
int main() {
    Bank bank;
    int choice;

    cout << "=====================================\n";
    cout << "   WELCOME TO MINI BANK MANAGEMENT   \n";
    cout << "=====================================\n";

    do {
        cout << "\n--------- MAIN MENU ---------\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Account Details\n";
        cout << "5. List All Accounts\n";
        cout << "6. Apply Monthly Update (interest/fees)\n";
        cout << "0. Exit\n";
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: {
                cin.ignore();
                string type, name;
                double deposit;
                cout << "Enter account type (savings/current): ";
                getline(cin, type);
                cout << "Enter account holder name: ";
                getline(cin, name);
                deposit = readDouble("Enter initial deposit amount: $");
                bank.createAccount(type, name, deposit);
                break;
            }
            case 2: {
                int accNo = readInt("Enter account number: ");
                Account* acc = bank.findAccount(accNo);
                if (acc) {
                    double amt = readDouble("Enter deposit amount: $");
                    acc->deposit(amt);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                int accNo = readInt("Enter account number: ");
                Account* acc = bank.findAccount(accNo);
                if (acc) {
                    double amt = readDouble("Enter withdrawal amount: $");
                    acc->withdraw(amt);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                int accNo = readInt("Enter account number: ");
                Account* acc = bank.findAccount(accNo);
                if (acc) {
                    acc->displayInfo();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 5:
                bank.listAllAccounts();
                break;
            case 6:
                bank.applyMonthlyUpdatesToAll();
                break;
            case 0:
                cout << "Thank you for using Mini Bank Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
