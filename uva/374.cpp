#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll f(ll x, ll y, ll m)
{
    ll res = 1;
    while(y>0)
    {
        if(y&1)
            res = (res%m * x%m)%m;
        x = (x%m*x%m)%m;
        y = y/2;
    }
    return res;
}

int main()
{
    FASTIO;
    ll b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m) == 3)
    {
        cout<<f(b,p,m)<<endl;
    }
    return 0;
}