#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    ll n;
    cin>>n;
    while(n)
    {
        ll x = (ll)sqrt(n);
        if(x*x == n)
            cout<<"yes\n";
        else
            cout<<"no\n";
        cin>>n;
    }
}