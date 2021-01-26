#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        ll x, y;
        cin>>x>>y;
        if(x==1 && y>1)
            cout<<"NO\n";
        else if(x>=y)
            cout<<"YES\n";
        else if(x==2 && y > 3)
            cout<<"NO\n";
        else if(x==3)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}