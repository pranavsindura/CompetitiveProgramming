#include<bits/stdc++.h>
#define ll 			long long int
#define pi 			pair<int,int>
#define eps 		0.000000001
#define all(x) 		x.begin(), x.end()
#define allr(x) 	x.rbegin(), x.rend()
#define sz(x) 		((int)x.size())
#define ln(x) 		((int)x.length())
#define mp 			make_pair
#define pb 			push_back
#define ff 			first
#define ss 			second
#define endl 		'\n'
#define dbg(x) 		cout<<#x<<" "<<x<<endl
#define clr(x,v) 	memset(x, v, sizeof(x))
#define FASTIO 		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    ll x, y, m;
    cin >> x >> y >> m;

    if(m > 0)
    {
        if(x > 0 || y > 0)
        {
            //ok
        }
        else
        {
            cout << -1;
            return;
        }
    }
    else
    {
        if(x < m && y < m)
        {
            cout << -1;
            return;
        }
    }
    bool ok = true;
    ll step = 0;
    while(x < m && y < m)
    {
        if(x > y)
            swap(x, y);
        ll diff = y - x;
        ll p = diff / y + 1;
        x = x + p * y;
        step += p;
    }
    cout << (!ok ? -1 : step);
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}