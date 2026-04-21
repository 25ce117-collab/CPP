#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person() {}
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    void display();
    string getName();
};

class Employee:public Person
{
protected:
    int EmployeeID;

public:
    Employee() {}
    Employee(int EmployeeID,string name,int age):Person(name, age)
    {
        this->EmployeeID=EmployeeID;
    }
    void display();
};

class Manager:public Employee
{
protected:
    string departmentOverseen;

public:
    Manager() {}
    Manager(string departmentOverseen,int EmployeeID,string name,int age):Employee(EmployeeID,name,age)
    {
        this->departmentOverseen=departmentOverseen;
    }
    void display();
};

void Employee::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Role: Employee" << endl;
    cout << "Employee ID: " << EmployeeID << endl;
}

void Manager::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Role: Person" << endl;
    cout << "Employee ID: " << EmployeeID << endl;
    cout << "Department Overseen: " << departmentOverseen << endl;
}

void Person::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Role: Person" << endl;
}

string Person::getName()
{
    return name;
}

int main()
{
    int choice,no_person=0,no_employee=0,no_manager=0,age,id_choice,des_choice;
    string name,departmentOverseen;
    Person p[10];
    Employee e[10];
    Manager m[5];
start:
    cout << "Please enter your choice" << endl;
    cout << "1. Add New Person" << endl
         << "2. Add New Employee" << endl
         << "3. Add new Manager" << endl
         << "4. Display Names" << endl
         << "5. Display Details" << endl
         << "6. Exit" << endl;
    cin >> choice;

    switch(choice)
    {
    case 1:
    {
        cout << "Enter Name" << endl;
        cin >> name;
        cout << "Enter Age" << endl;
        cin >> age;
        p[no_person++]=Person(name,age);
        goto start;
    }
    case 2:
    {
        cout << "Enter Name" << endl;
        cin >> name;
        cout << "Enter Age" << endl;
        cin >> age;
        e[no_employee++]=Employee(no_employee,name,age);
        goto start;
    }
    case 3:
    {
        cout << "Enter Name" << endl;
        cin >> name;
        cout << "Enter Age" << endl;
        cin >> age;
        cout << "Enter Department Overseen" << endl;
        cin >> departmentOverseen;
        m[no_manager++]=Manager(departmentOverseen,no_employee,name,age);
        goto start;
    }
    case 4:
    {
        for(int i=0; i<no_person; i++)
        {
            cout << "Person " << i+1 << " Name: " << p[i].getName() << endl;
        }
        for(int i=0; i<no_employee; i++)
        {
            cout << "Employee " << i+1 << "Name: " << e[i].getName() << endl;
        }
        for(int i=0; i<no_manager; i++)
        {
            cout << "Manager " << i+1 << "Name: " << m[i].getName() << endl;
        }
        goto start;
    }
    case 5:
    {
        cout << "Enter ID of person for Required Details" << endl;
        cin >> id_choice;
        cout << "Select their Designation" << endl;
        cout << "1. Person" << endl <<
             "2. Employee" << endl <<
             "3. Manager" << endl;
        cin >> des_choice;
        switch(des_choice)
        {
        case 1:
        {
            p[--id_choice].display();
            break;
        }
        case 2:
        {
            e[--id_choice].display();
            break;
        }
        case 3:
        {
            m[--id_choice].display();
            break;
        }
        }
        goto start;
    }
    case 6:
    {
        break;
    }
    }

    return 0;
}


