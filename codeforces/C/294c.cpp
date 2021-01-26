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
    return res % mod;
}

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

ll fact[1005];
void init()
{
    fact[0] = 1;
    for(int i = 1; i < 1005; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        arr[x] = 1;
    }
    int l = 1;
    ll num = n - m, den = 1;
    ll ans = 1;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i])
        {
            //l to i-1
            int len = i - l;
            den = (den % mod * fact[len] % mod) % mod;
            if(l != 1 && len)
            {
                ans = (ans % mod * fpow(2, len - 1));
            }
            l = i + 1;
        }
    }
    if(l < n)
    {
        int len = n + 1 - l;
        den = (den % mod * fact[len] % mod) % mod;
    }
    num = fact[num];
    ans = (ans % mod * num % mod) % mod;
    ans = (ans % mod * inv(den) % mod) % mod;
    cout << ans;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}