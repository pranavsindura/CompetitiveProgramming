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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 5e5 + 5;
ll fact[MAXN];
void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (i % mod * fact[i - 1] % mod) % mod;
}

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

ll inv(ll a)
{
    return fpow(a, mod - 2) % mod;
}

ll ncr(ll n, ll r)
{
    ll ans = fact[n];
    ans = (ans * inv(fact[n - r])) % mod;
    ans = (ans * inv(fact[r])) % mod;
    return ans % mod;
}

void cp()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    ll sg;
    for(int i = 0; i <= n; i++)
    {
        sg = (i % 2 ? -1 : 1);
        ll p = ncr(n, i);
        ll q = (fact[m] % mod * inv(fact[m - i]) % mod) % mod;
        ll r = ncr(m - i, n - i);
        ll s = fact[n - i];

        ll t = (r % mod * s % mod) % mod;
        t = fpow(t, 2) % mod;

        ll here = (p % mod * q % mod) % mod;
        here = (here % mod * t % mod) % mod;
        here *= sg;
        ans = (ans + here + mod) % mod;
    }
    cout << ans % mod;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}