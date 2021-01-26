#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, p, d, w, win=0, draw=0, loss=0;
    cin>>n>>p>>w>>d;
    for(int i=0;i<w;i++)
    {
        ll a = (p - (d*i))/w;
        if(a<0 || a*w + i*d != p || n-a-i < 0)
            continue;
        else
        {
            cout<<a<<" "<<i<<" "<<n-a-i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}