#include<iostream>
using namespace std;

int main()
{
    int capacity=1;
    int size=0;
    int *arr=new int[capacity];

    int choice;

    while(true)
    {
        cin>>choice;

        if(choice==1)
        {
            int value;
            cin>>value;

            if(size==capacity)
            {
                capacity*=2;
                int *newArr=new int[capacity];
                for(int i=0;i<size;i++)
                {
                    newArr[i]=arr[i];
                }
                delete[] arr;
                arr=newArr;
            }

            arr[size]=value;
            size++;
        }
        else if(choice==2)
        {
            int pos;
            cin>>pos;

            if(pos>=0 && pos<size)
            {
                for(int i=pos;i<size-1;i++)
                {
                    arr[i]=arr[i+1];
                }
                size--;
            }
        }
        else if(choice==3)
        {
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else if(choice==4)
        {
            break;
        }
    }

    delete[] arr;
    return 0;
}
