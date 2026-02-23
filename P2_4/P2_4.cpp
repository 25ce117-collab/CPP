#include<iostream>
#include<string.h>
using namespace std;

class Item_Inventory
{
public:
    Item_Inventory()
    {
        Item_ID=0;
        Item_name="Nill";
        Item_price=0.0;
        Item_quantity=0;
    }
    Item_Inventory(int i,string n,float p,int q)
    {
        Item_ID=i;
        Item_name=n;
        Item_price=p;
        Item_quantity=q;
    }
    char Search_item(int);
    void Refill_item();
    void Sale_item();
    void Display_details();
private:
    int Item_ID;
    string Item_name;
    float Item_price;
    int Item_quantity;
};

char Item_Inventory::Search_item(int x)
{
    if(x==Item_ID)
    {
        return 'V';
    }
    else
    {
        return 'I';
    }
}

void Item_Inventory::Refill_item()
{
    int q1;
    cout<<endl<<"Enter the Amount of stock to update :- ";
    cin>>q1;
    cout<<endl;
    Item_quantity=Item_quantity+q1;
}

void Item_Inventory::Sale_item()
{
    int q2;
    cout<<endl<<"Enter the Amount of stock to sale :- ";
    cin>>q2;
    cout<<endl;
    if(q2<=Item_quantity)
    {
        Item_quantity=Item_quantity-q2;
    }
    else
    {
        cout<<"Insufficient Stock"<<endl;
    }
}

void Item_Inventory::Display_details()
{
    cout<<endl<<"Item Id :- "<<Item_ID<<endl;
    cout<<"Item Name :- "<<Item_name<<endl;
    cout<<"Item price :- "<<Item_price<<endl;
    cin.ignore();
    cout<<"Item's Stock :- "<<Item_quantity<<endl;
}

int main()
{
    Item_Inventory item[15];
    int ch,i,t=0,id,stock;
    string name;
    float price;
lable:
    cout<<"1. Add Items"<<endl;
    cout<<"2. New stock addition"<<endl;
    cout<<"3. Item sale"<<endl;
    cout<<"4. Display details"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter the item ID :- ";
        cin>>id;
        cout<<endl;

        cin.ignore();
        cout<<"Enter the item name:- ";
        cin>>name;
        cout<<endl;

        cout<<"Enter the price of item :- ";
        cin>>price;
        cout<<endl;


        cout<<"Enter the stock of item :- ";
        cin>>stock;
        cout<<endl;
        item[t]=Item_Inventory(id,name,price,stock);
        t++;
        goto lable;

    case 2:
        int ID1;
        cout<<"Enter the item id :- ";
        cin>>ID1;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(item[i].Search_item(ID1) == 'V')
            {
                item[i].Refill_item();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Item Id is invalid"<<endl;
        }
        goto lable;

    case 3:
        int ID2;
        cout<<"Enter the item id :- ";
        cin>>ID2;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(item[i].Search_item(ID2) == 'V')
            {
                item[i].Sale_item();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Item Id is invalid"<<endl;
        }
        goto lable;

    case 4:
        int ID3;
        cout<<"Enter the item id :- ";
        cin>>ID3;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(item[i].Search_item(ID3) == 'V')
            {
                item[i].Display_details();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Item Id is invalid"<<endl;
        }
        goto lable;

    case 5:
        return 0;

    default:
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}
