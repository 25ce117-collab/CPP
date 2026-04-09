#include<iostream>
#include<string>
using namespace std;

class Account
{
    int accNo;
    string name;
    double balance;
    static int totalAccounts;

public:
    Account()
    {
        accNo=0;
        name="";
        balance=0;
    }

    void create(int no,string n,double bal)
    {
        accNo=no;
        name=n;
        balance=bal;
        totalAccounts++;
    }

    int getAccNo()
    {
        return accNo;
    }

    void deposit(double amt)
    {
        balance+=amt;
    }

    void withdraw(double amt)
    {
        if(amt<=balance)
            balance-=amt;
        else
            cout<<"Insufficient balance"<<endl;
    }

    bool transfer(Account& to,double amt)
    {
        if(amt<=balance)
        {
            balance-=amt;
            to.balance+=amt;
            return true;
        }
        return false;
    }

    void display()
    {
        cout<<"Account No: "<<accNo<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Balance:"<<balance<<endl;
        cout<<endl;
    }

    static int getTotalAccounts()
    {
        return totalAccounts;
    }
};

int Account::totalAccounts=0;

int main()
{
    int n;
    cout<<"Enter number of accounts:";
    cin>>n;

    Account* acc=new Account[n];

    for(int i=0;i<n;i++)
    {
        int no;
        string name;
        double bal;
        cout<<"Enter account number, name and balance:";
        cin>>no>>name>>bal;
        acc[i].create(no,name,bal);
    }

    int choice;
    do
    {
        cout<<"1.Transfer 2.Deposit 3.Withdraw 4.Display 5.Total Accounts 6.Exit\n";
        cin>>choice;

        if(choice==1)
        {
            int from,to;
            double amt;
            cout<<"Enter from account no, to account no and amount:";
            cin>>from>>to>>amt;
            bool foundFrom=false,foundTo=false;
            for(int i=0;i<n;i++)
            {
                if(acc[i].getAccNo()==from)
                    for(int j=0;j<n;j++)
                    {
                        if(acc[j].getAccNo()==to)
                        {
                            foundFrom=foundTo=true;
                            if(acc[i].transfer(acc[j],amt))
                                cout<<"Transfer successful\n";
                            else
                                cout<<"Transfer failed\n";
                        }
                    }
            }
            if(!foundFrom || !foundTo)
                cout<<"Invalid account\n";
        }

        else if(choice==2)
        {
            int no;
            double amt;
            cout<<"Enter account no and amount: ";
            cin>>no>>amt;
            for(int i=0;i<n;i++)
                if(acc[i].getAccNo()==no)
                    acc[i].deposit(amt);
        }

        else if(choice==3)
        {
            int no;
            double amt;
            cout<<"Enter account no and amount:";
            cin>>no>>amt;
            for(int i=0;i<n;i++)
                if(acc[i].getAccNo()==no)
                    acc[i].withdraw(amt);
        }

        else if(choice==4)
        {
            for(int i=0;i<n;i++)
                acc[i].display();
        }

        else if(choice==5)
        {
            cout<<"Total Accounts:"<<Account::getTotalAccounts()<<endl;
        }

    }
    while(choice!=6);

    delete[] acc;
    return 0;
}
