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
const ll mod = 998244353;
const int MAXN = 1e6 + 5;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y = y / 2;
    }
    return res;
}

void cp()
{
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    reverse(all(a)), reverse(all(b));
    int need = abs(n - m);
    if(n > m)
        for(int i = 0; i < need; i++)
            b += '0';
    else
        for(int i = 0; i < need; i++)
            a += '0';
    ll cnt = 0;
    ll ans = 0;
    for(int i = sz(a) - 1; i >= 0; i--)
    {
    	cnt += b[i]-'0';
    	ans += ((a[i]-'0') * fpow(2, i) * cnt);
    	ans %= mod;
    }
    cout<<ans;
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