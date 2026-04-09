#include<iostream>
#include<string>
using namespace std;

int superDigit(long long n)
{
    if(n<10)
        return n;

    long long sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }

    return superDigit(sum);
}

int main()
{
    string n;
    long long k;
    cin>>n>>k;

    long long sum=0;
    for(int i=0;i<n.size();i++)
    {
        sum+=n[i]-'0';
    }

    sum=sum*k;

    cout<<superDigit(sum);

    return 0;
}
