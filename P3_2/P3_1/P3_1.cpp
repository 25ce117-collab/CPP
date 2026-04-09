#include<iostream>
#include<string>
using namespace std;

class Employee
{
    string name;
    double basicSalary;
    double bonus;

public:
    Employee()
    {
        name="";
        basicSalary=0;
        bonus=0;
    }

    Employee(string n,double b)
    {
        name=n;
        basicSalary=b;
        bonus=1000;
    }

    Employee(string n,double b,double bo)
    {
        name=n;
        basicSalary=b;
        bonus=bo;
    }

    inline double totalSalary()
    {
        return basicSalary+bonus;
    }

    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Basic Salary:"<<basicSalary<<endl;
        cout<<"Bonus:"<<bonus<<endl;
        cout<<"Total Salary:"<<totalSalary()<<endl;
        cout<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter number of employees:";
    cin>>n;

    Employee* emp=new Employee[n];

    for(int i=0;i<n;i++)
    {
        string name;
        double basic,bonus;
        int choice;

        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter basic salary:";
        cin>>basic;
        cout<<"Default bonus (1) or custom bonus (2):";
        cin>>choice;

        if(choice==1)
        {
            emp[i]=Employee(name,basic);
        }
        else
        {
            cout<<"Enter bonus:";
            cin>>bonus;
            emp[i]=Employee(name,basic,bonus);
        }
    }

    for(int i=0;i<n;i++)
    {
        emp[i].display();
    }

    delete[] emp;
    return 0;
}
