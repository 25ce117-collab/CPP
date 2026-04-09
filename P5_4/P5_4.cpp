#include<iostream>
#include<iomanip>

using namespace std;

ostream& currency(ostream& out)
{
    out<<"₹";
    return out;
}

int main()
{
    const int SIZE=3;

    string names[SIZE]= {"Amit","Neha","Raj"};
    int marks[SIZE]= {85,92,78};
    double fees[SIZE]= {25000.5,30000.75,27500.25};

    cout<<setfill('=')<<setw(50)<<""<<endl;
    cout<<setfill(' ');

    cout <<setw(15)<<"Name"<<setw(10)<<"Marks"<<setw(15)<<"Fees"<<endl;

    cout<<setfill('-')<<setw(50)<<""<<endl;
    cout<<setfill(' ');

    for(int i=0; i<SIZE; i++)
    {
        cout<<setw(15)<<names[i]<<setw(10)<<marks[i]<<setw(5)<<currency<<setw(10)<<fixed<<setprecision(2)<<fees[i]<<endl;
    }

    cout<<setfill('=')<<setw(50)<<""<<endl;

    return 0;
}
