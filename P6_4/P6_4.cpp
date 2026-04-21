#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account
{
protected:
    long long accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    Account()
    {
        accountNumber = 0;
        balance = 0.0;
    }
    Account(long long accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            transactionHistory.push_back("Withdrawn: " + to_string(amount));
        }
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
        transactionHistory.push_back("Deposited: " + to_string(amount));
    }

    void displayBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void viewTransactions()
    {
        cout << "Viewing transactions for account: " << accountNumber << endl;
        for (const auto &tx : transactionHistory)
        {
            cout << "Transaction: " << tx << endl;
        }
    }

    void undoLastTransaction()
    {
        if (transactionHistory.empty())
        {
            cout << "No transactions to undo!" << endl;
            return;
        }

        string lastTransaction = transactionHistory.back();
        transactionHistory.pop_back();

        cout << "Undoing last transaction: " << lastTransaction << endl;

        if (lastTransaction.find("Deposited: ") == 0)
        {
            double amount = stod(lastTransaction.substr(11));
            balance -= amount;
        }
        else if (lastTransaction.find("Withdrawn: ") == 0)
        {
            double amount = stod(lastTransaction.substr(11));
            balance += amount;
        }
    }

    void setAccountNumber(long long accNum)
    {
        accountNumber = accNum;
    }

    long long getAccountNumber()
    {
        return accountNumber;
    }
};

class SavingsAccount : public Account
{
protected:
    double interestRate;

public:
    SavingsAccount()
    {
        interestRate = 0.0;
    }
    SavingsAccount(long long accNum, double bal, double rate) : Account(accNum, bal), interestRate(rate) {}
};

class CurrentAccount : public Account
{
protected:
    double overdraftLimit;

public:
    CurrentAccount()
    {
        overdraftLimit = 0.0;
    }
    CurrentAccount(long long accNum, double bal, double limit) : Account(accNum, bal), overdraftLimit(limit) {}
};

int main()
{
    int choice, no_savings = 0, no_current = 0;
    long long accNum;

    SavingsAccount savings[5];
    CurrentAccount current[5];

    cout << "Welcome to the Bank Account Management System!" << endl;

    while (true)
    {
        cout << "\n1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Display Balance" << endl;
        cout << "6. View Transactions" << endl;
        cout << "7. Undo Last Transaction" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
            break;

        switch (choice)
        {
        case 1:
        {
            if (no_savings >= 5)
            {
                cout << "Savings account limit reached!" << endl;
                break;
            }
            double bal, rate;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter initial balance: ";
            cin >> bal;
            cout << "Enter interest rate: ";
            cin >> rate;
            savings[no_savings++] = SavingsAccount(accNum, bal, rate);
            break;
        }

        case 2:
        {
            if (no_current >= 5)
            {
                cout << "Current account limit reached!" << endl;
                break;
            }
            double bal, limit;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter initial balance: ";
            cin >> bal;
            cout << "Enter overdraft limit: ";
            cin >> limit;
            current[no_current++] = CurrentAccount(accNum, bal, limit);
            break;
        }

        case 3:
        {
            double amount;
            bool found = false;

            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            for (int i = 0; i < no_savings; ++i)
            {
                if (savings[i].getAccountNumber() == accNum)
                {
                    savings[i].deposit(amount);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (int i = 0; i < no_current; ++i)
                {
                    if (current[i].getAccountNumber() == accNum)
                    {
                        current[i].deposit(amount);
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                cout << "Account not found!" << endl;

            break;
        }

        case 4:
        {
            double amount;
            bool found = false;

            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            for (int i = 0; i < no_savings; ++i)
            {
                if (savings[i].getAccountNumber() == accNum)
                {
                    savings[i].withdraw(amount);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (int i = 0; i < no_current; ++i)
                {
                    if (current[i].getAccountNumber() == accNum)
                    {
                        current[i].withdraw(amount);
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                cout << "Account not found!" << endl;

            break;
        }

        case 5:
        {
            bool found = false;

            cout << "Enter account number: ";
            cin >> accNum;

            for (int i = 0; i < no_savings; ++i)
            {
                if (savings[i].getAccountNumber() == accNum)
                {
                    savings[i].displayBalance();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (int i = 0; i < no_current; ++i)
                {
                    if (current[i].getAccountNumber() == accNum)
                    {
                        current[i].displayBalance();
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                cout << "Account not found!" << endl;

            break;
        }

        case 6:
        {
            bool found = false;

            cout << "Enter account number: ";
            cin >> accNum;

            for (int i = 0; i < no_savings; ++i)
            {
                if (savings[i].getAccountNumber() == accNum)
                {
                    savings[i].viewTransactions();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (int i = 0; i < no_current; ++i)
                {
                    if (current[i].getAccountNumber() == accNum)
                    {
                        current[i].viewTransactions();
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                cout << "Account not found!" << endl;

            break;
        }

        case 7:
        {
            bool found = false;

            cout << "Enter account number: ";
            cin >> accNum;

            for (int i = 0; i < no_savings; ++i)
            {
                if (savings[i].getAccountNumber() == accNum)
                {
                    savings[i].undoLastTransaction();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (int i = 0; i < no_current; ++i)
                {
                    if (current[i].getAccountNumber() == accNum)
                    {
                        current[i].undoLastTransaction();
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                cout << "Account not found!" << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
