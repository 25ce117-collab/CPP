#include<iostream>
using namespace std;

template<typename T>
T findMax(T arr[],int n)
{
    T mx=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>mx)
            mx=arr[i];
    return mx;
}

template<typename T>
void reverseArray(T arr[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        T temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}

template<typename T>
void display(T arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" "<<endl;
}

template<typename T>
void leaders(T arr[],int n)
{
    T maxRight=arr[n-1];
    cout<<maxRight<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>maxRight)
        {
            maxRight=arr[i];
            cout<<maxRight<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int arr1[]={16,17,4,3,5,2};
    int n1=sizeof(arr1)/sizeof(arr1[0]);

    float arr2[]={1.1,3.5,2.2,5.6,4.4};
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    char arr3[]={'a','z','b','y','c'};
    int n3=sizeof(arr3)/sizeof(arr3[0]);

    cout<<findMax(arr1,n1)<<endl;
    reverseArray(arr1,n1);
    display(arr1,n1);
    leaders(arr1,n1);

    cout<<findMax(arr2,n2)<<endl;
    reverseArray(arr2,n2);
    display(arr2,n2);
    leaders(arr2,n2);

    cout<<findMax(arr3,n3)<<endl;
    reverseArray(arr3,n3);
    display(arr3,n3);
    leaders(arr3,n3);

    return 0;
}
