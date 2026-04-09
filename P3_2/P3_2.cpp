#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

int recursiveSum(int arr[],int n)
{
    if(n==0)
        return 0;
    return arr[n-1]+recursiveSum(arr,n-1);
}

int iterativeSum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}

int main()
{
    int n;
    cout<<"Enter size of array:";
    cin>>n;

    int* arr=new int[n];

    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    auto start1=high_resolution_clock::now();
    int rsum=recursiveSum(arr, n);
    auto end1=high_resolution_clock::now();
    auto duration1=duration_cast<nanoseconds>(end1-start1);

    auto start2=high_resolution_clock::now();
    int isum=iterativeSum(arr,n);
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-start2);

    cout<<"Recursive Sum:"<<rsum<<endl;
    cout<<"Recursive Time(ns):"<<duration1.count()<<endl;

    cout<<"Iterative Sum:"<<isum<<endl;
    cout<<"Iterative Time(ns):"<<duration2.count()<<endl;

    delete[] arr;
    return 0;
}
