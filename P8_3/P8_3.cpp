#include <iostream>
#include <stdexcept>
#include <string>

const int MAX_LOGS = 100;

class Logger
{
    std::string logs[MAX_LOGS];
    int count = 0;
public:
    void log(const std::string& msg)
    {
        if (count < MAX_LOGS) logs[count++] = msg;
    }
    void show() const
    {
        std::cout << "\nTransaction Log:\n";
        for (int i = 0; i < count; ++i) std::cout << logs[i] << std::endl;
    }
};

Logger logger;

class BankAccount
{
    double balance;
public:
    BankAccount(double initial) : balance(initial)
    {
        logger.log("BankAccount::BankAccount - Entry");
        logger.log("BankAccount::BankAccount - Exit");
    }
    void deposit(double amount)
    {
        logger.log("BankAccount::deposit - Entry");
        if (amount <= 0)
        {
            logger.log("BankAccount::deposit - Invalid deposit amount");
            throw std::invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
        logger.log("BankAccount::deposit - Exit");
    }
    void withdraw(double amount)
    {
        logger.log("BankAccount::withdraw - Entry");
        if (amount <= 0)
        {
            logger.log("BankAccount::withdraw - Invalid withdraw amount");
            throw std::invalid_argument("Withdraw amount must be positive");
        }
        if (amount > balance)
        {
            logger.log("BankAccount::withdraw - Insufficient funds");
            throw std::runtime_error("Insufficient funds");
        }
        balance -= amount;
        logger.log("BankAccount::withdraw - Exit");
    }
    double getBalance() const
    {
        return balance;
    }
};

void performWithdrawal(BankAccount& acc, double amt)
{
    logger.log("performWithdrawal - Entry");
    acc.withdraw(amt);
    logger.log("performWithdrawal - Exit");
}

void transaction(BankAccount& acc, double depositAmt, double withdrawAmt)
{
    logger.log("transaction - Entry");
    acc.deposit(depositAmt);
    performWithdrawal(acc, withdrawAmt);
    logger.log("transaction - Exit");
}

int main()
{
    logger.log("main - Entry");
    BankAccount acc(100.0);
    try
    {
        transaction(acc, 50.0, 200.0);
    }
    catch (const std::exception& ex)
    {
        logger.log(std::string("Exception caught in main: ") + ex.what());
    }
    logger.log("main - Exit");
    logger.show();
    return 0;
}
