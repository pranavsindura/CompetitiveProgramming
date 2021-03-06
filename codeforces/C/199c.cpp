#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll fpow(ll x, int y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}

void cp()
{
    ll k, b, n, t;
    cin >> k >> b >> n >> t;
    if(k > 1)
    {
        ll p = k * t + b - t;
        ll q = k + b - 1;
        int ans = 0;
        for(int y = n; y >= 0; y--)
        {
            if(fpow(k, n - y) * q <= p)
                ans = y;
            else
                break;
        }
        cout << ans;
    }
    else
    {
        ll res = 1 + (n - 1) * b;
        ll ans = 0;
        while(t + (ans - 1)*b < res)
            ans++;
        cout << ans;
    }
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