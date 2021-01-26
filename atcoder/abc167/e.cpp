#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
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
const ll mod = 998244353;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

ll fact[MAXN];

void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
    {
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
    }
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
    return res % mod;
}

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

ll comb(int n, int r)
{
    if(r > n)
        return 0LL;
    return ((fact[n] % mod * inv(fact[n - r]) % mod) % mod * inv(fact[r]) % mod) % mod;
}

void cp()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    /*
    	from n-1 pairs, pick any i, and consider them one single blank for colouring
    	you will now have n-i blanks
    	for these blanks you have colouring of the form
    	m, m-1, m-1, m-1, m-1, ...... m-1

    	ans = Σ C(n-1, i) * m * (m-1)^(n-i-1) for all 0<=i<=k
    */
    for(int i = 0; i <= k; i++)
    {
        int blank = n - i;
        ans = (ans % mod + ((comb(n - 1, i) * m) % mod * fpow(m - 1, blank - 1) % mod) % mod ) % mod;
    }
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