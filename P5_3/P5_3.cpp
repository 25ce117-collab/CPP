#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>

using namespace std;

void toLower(char str[])
{
    for(int i=0; str[i]!='\0'; i++)
    {
        str[i]=tolower(str[i]);
    }
}

int compareIgnoreCase(char a[],char b[])
{
    char x[100],y[100];
    strcpy(x,a);
    strcpy(y,b);
    toLower(x);
    toLower(y);
    return strcmp(x,y);
}

void addItem()
{
    ofstream file("inventory.txt",ios::app);

    if(!file)
    {
        cout<<"Error opening file\n";
        return;
    }

    char name[100];
    int quantity;
    float price;

    cout<<"Enter item name: ";
    cin.ignore();
    cin.getline(name,100);

    cout<<"Enter quantity:";
    cin>>quantity;

    cout<<"Enter price:";
    cin>>price;

    file<<name<<"|"<<quantity<<"|"<<price<<"\n";

    file.close();
}

void viewItems()
{
    ifstream file("inventory.txt");

    if(!file)
    {
        cout<<"Error opening file\n";
        return;
    }

    char name[100];
    int quantity;
    float price;

    while(file.getline(name,100,'|'))
    {
        file>>quantity;
        file.ignore();
        file>>price;
        file.ignore();

        cout<<"Name:"<<name<<endl;
        cout<<"Quantity:"<<quantity<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"------------------\n";
    }

    file.close();
}

void searchItem()
{
    ifstream file("inventory.txt");

    if(!file)
    {
        cout<<"Error opening file\n";
        return;
    }

    char search[100];
    cout<<"Enter item name to search:";
    cin.ignore();
    cin.getline(search,100);

    char name[100];
    int quantity;
    float price;

    int found=0;

    while(file.getline(name,100,'|'))
    {
        file>>quantity;
        file.ignore();
        file>>price;
        file.ignore();

        if(compareIgnoreCase(name,search)==0)
        {
            cout<<"Item Found\n";
            cout<<"Name:"<<name<<endl;
            cout<<"Quantity:"<<quantity<<endl;
            cout<<"Price:"<<price<<endl;
            found=1;
        }
    }

    if(!found)
    {
        cout<<"Item not found\n";
    }

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout<<"\n1. Add Item\n2. View Items\n3. Search Item\n4. Exit\n";
        cout<<"Enter choice:";
        cin>>choice;

        if(choice==1)addItem();
        else if(choice==2)viewItems();
        else if(choice==3)searchItem();

    }
    while(choice!=4);

    return 0;
}
