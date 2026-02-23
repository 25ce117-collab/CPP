#include <iostream>
#include <string>

using namespace std;

class Bank_Account
{
    string account_holder_name;

    long double balance;
    double acct_no;

    public:

        void withdraw();
        void deposit();
        void view_bal();
        void create_account();
        int search_account(double);
};

int Bank_Account::search_account(double account_no_input)
{
        if(acct_no==account_no_input)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

void Bank_Account::create_account()
{
    char newline;
    cout << "Enter User's Name" << endl;

    getline(cin >> newline,account_holder_name);
    cout << "Enter Account Number" << endl;
    cin >> acct_no;
    cout << "Enter User's Balance" << endl;
    cin >> balance;
}

void Bank_Account::withdraw()
{
    long double withdraw=0;
    cout << "Enter Amount to withdraw" << endl;
    cin >> withdraw;
    if((withdraw<balance) && withdraw > 0)
    {
        balance -= withdraw;
    }
    else
    {
        cout << "Insufficient Funds" << endl;
    }
}

void Bank_Account::deposit()
{
    long double deposit=0;
    cout << "Enter Amount to deposit" << endl;
    cin >> deposit;
    if(deposit > 0)
    {
        balance += deposit;
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }
}

void Bank_Account::view_bal()
{
    cout << "User's Name is" << account_holder_name << endl;
    cout << "User's Balance is Rupees " << balance << endl;
}

int main()
{
    int choice,t=0,i;
    double acct_no;
    Bank_Account user[10];
    menu:
    cout << "Welcome to the Bank!" << endl
         << "1. Create Account" << endl
         << "2. View Account Balance" << endl
         << "3. Deposit Money" << endl
         << "4. Withdraw Money" << endl
         << "5. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            user[t].create_account();
            t++;
            goto menu;
        case 2:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<t;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].view_bal();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Account not found!" << endl;
                }
            goto menu;
        case 3:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<t;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].deposit();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Account not found!" << endl;
                }
            goto menu;
        case 4:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<t;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].withdraw();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Account not found!" << endl;
                }
            goto menu;
        case 5:
            break;
        default:
            cout << "Invalid Choice, Please try again!" << endl;
            goto menu;
    }

    cout << "Visit Again!" << endl;
}
