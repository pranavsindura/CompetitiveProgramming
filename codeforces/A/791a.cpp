#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll a, b;
    cin>>a>>b;
    int i=0;
    while(a<=b)
    {
        a*=3;
        b*=2;
        i++;
    }
    cout<<i;
    return 0;
}