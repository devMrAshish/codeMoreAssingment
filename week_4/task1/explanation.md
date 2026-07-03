# Program Flow Explanation — Bank Management System

## 1. Class Design

```
            Account (abstract base class)
            ├── accountNumber, holderName, balance (protected)
            ├── deposit()               [concrete]
            ├── withdraw()              [virtual, has default logic]
            ├── applyMonthlyUpdate()    [pure virtual]
            ├── accountType()           [pure virtual]
            └── displayInfo()           [virtual]
                    │
        ┌───────────┴───────────┐
        │                       │
 SavingsAccount           CurrentAccount
 - interestRate           - overdraftLimit
 - withdraw() override    - withdraw() override
 - applyMonthlyUpdate()   - applyMonthlyUpdate()
   (adds interest)          (deducts flat fee)
```

`Account` cannot be instantiated directly because it declares two pure
virtual functions. Every account created in the program is actually a
`SavingsAccount` or `CurrentAccount` object, but the rest of the program
(the `Bank` class, the menu) only ever talks to it through an `Account*`
pointer. This is **polymorphism in action** — the correct `withdraw()` or
`applyMonthlyUpdate()` is chosen automatically at runtime based on the
object's real type.

## 2. The `Bank` Class (Manager / Controller)

- Holds a `vector<Account*> accounts` — the in-memory "database".
- `createAccount()` decides which subclass to instantiate based on the
  type string the user typed, assigns it an auto-incrementing account
  number starting at `1001`, and stores the pointer.
- `findAccount()` performs a linear search by account number.
- `listAllAccounts()` and `applyMonthlyUpdatesToAll()` loop over every
  stored account and call a virtual method on each — since the pointers
  are `Account*`, C++ automatically dispatches to the correct override.
- The destructor `~Bank()` deletes every account pointer to avoid memory
  leaks (manual memory management, since raw pointers are used here for
  simplicity).

## 3. Program Flow (main)

1. Program starts, prints a welcome banner, and creates one `Bank` object.
2. Enters a `do...while` loop that repeatedly:
   - Prints the menu.
   - Reads the user's choice via `readInt()` (a helper that loops until
     valid numeric input is given, protecting against crashes from bad
     input like letters).
3. Based on the choice, a `switch` statement dispatches to the
   corresponding action:
   - **1 – Create Account:** asks for type, name, and initial deposit,
     then calls `bank.createAccount(...)`.
   - **2 – Deposit:** looks up the account by number, then calls
     `acc->deposit(amount)`.
   - **3 – Withdraw:** looks up the account, then calls
     `acc->withdraw(amount)`. Because `withdraw()` is virtual, a savings
     account enforces the $100 minimum balance rule while a current
     account allows overdraft up to its limit — same call site, different
     behavior.
   - **4 – View Account:** prints one account's details.
   - **5 – List All:** prints every account.
   - **6 – Monthly Update:** applies interest (savings) or a maintenance
     fee (current) to every account in the bank.
   - **0 – Exit:** ends the loop; `Bank`'s destructor cleans up memory.

## 4. Why This Design Demonstrates OOP Well

- **Encapsulation** keeps `balance` safe from being modified directly —
  every change goes through `deposit()`/`withdraw()`, which validate the
  amount first.
- **Abstraction** means the `main()` menu code never needs to know
  *how* interest or fees are calculated — it just calls
  `applyMonthlyUpdate()` and trusts the object to do the right thing.
- **Inheritance** avoids duplicating the shared fields
  (`accountNumber`, `holderName`, `balance`) and shared logic
  (`deposit()`) across two nearly-identical classes.
- **Polymorphism** is what lets a single `vector<Account*>` hold a mix
  of savings and current accounts and still behave correctly when
  looped over — this is the core "aha" of OOP that the task is testing.

## 5. Possible Extensions (not required, but noted for completeness)

- Persist accounts to a file so data survives between runs.
- Add a `FixedDepositAccount` subclass to show how easily new account
  types can be added without touching existing code (Open/Closed
  Principle).
- Add transaction history logging per account.
