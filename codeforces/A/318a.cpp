#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k;
    cin>>n>>k;
    if(n&1)
    {
        if(k<=(n+1)/2)
        {
            cout<<2*(k-1)+1;
        }
        else
        {
            k = k - ((n+1)/2);
            cout<<2*k;
        }
    }
    else
    {
        //n/2 odd numbers n/2 even numbers
        //odd numbers
        if(k<=n/2)
        {
            cout<<2*(k-1)+1;
        }
        //even numbers
        else
        {
            k = k - (n/2);
            cout<<2*k;
        }
    }
}