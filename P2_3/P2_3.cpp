#include<iostream>
using namespace std;
class account
{
	long int UID;
	float balance;
	char name[30];

public:
	void createAccount(int,account *);
	void withdraw();
	void deposit();
	void display();
	char searchUser(long int);
};

int main()
{
	int c,x=0,i;
	long int ID;
	account a[30];
	r1:
	cout<<"\n1-Create Account\n2-Withdraw\n3-Deposit\n4-Display Summery\n0-Exit\nEnter Choice : ";
	cin>>c;
	switch(c)
	{
		case 1:
			a[x].createAccount(x,a);
			x++;
			goto r1;
		case 2:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(a[i].searchUser(ID)=='y')
				{
					a[i].withdraw();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nAccount not found!\n";
			}
			goto r1;
		case 3:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(a[i].searchUser(ID)=='y')
				{
					a[i].deposit();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nAccount not found!\n";
			}
			goto r1;
		case 4:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(a[i].searchUser(ID)=='y')
				{
					a[i].display();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nAccount not found!\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			return 0;
		default:
			cout<<"\nInvalid Choice!\n";
			goto r1;
	}
	return 0;
}

void account::createAccount(int x,account *a)
{
	int i;
	r2:
	cout<<"\nEnter UID : ";
	cin>>UID;
	for(i=0;i<x;i++)
	{
		if(a[i].searchUser(UID)=='y')
		{
			cout<<"\nDuplicate ID found!\n";
			goto r2;
		}
	}
	getchar();
	cout<<"Enter User Name : ";
	cin.getline(name,30);
	cout<<"Enter Initial Balance : ";
	cin>>balance;
}

void account::withdraw()
{
	float amt;
	cout<<"Enter withdrawal amount : ";
	cin>>amt;
	balance-=amt;
}

void account::deposit()
{
	float amt;
	cout<<"Enter deposit amount : ";
	cin>>amt;
	balance+=amt;
}

void account::display()
{
	cout<<"\nUID : "<<UID<<"\nUser Name : "<<name<<"\nCurrent Balance : "<<balance<<endl;
}

inline char account::searchUser(long int ID)
{
	if(ID == UID)
		return 'y';
	return 'n';
}
