#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    ll n, x, d=0;
    cin>>n>>x;
    while(n--)
    {
        char c;
        ll m;
        cin>>c>>m;
        if(c == '+')
            x+=m;
        else
        {
            if(x < m)
                d++;
            else
                x -= m;
        }
    }
    cout<<x<<" "<<d;
    return 0;
}