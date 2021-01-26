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
const int MAXN = 5e4 + 5;

ll fact[MAXN];

void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}

ll fpow(ll x, ll y)
{
    ll res  = 1;
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
    return fpow(a, mod - 2);
}

ll ncr(int n, int r)
{
    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * inv(fact[n - r]) % mod) % mod;
    ans = (ans % mod * inv(fact[r]) % mod) % mod;
    return ans;
}

int main()
{
    FASTIO;
    int a, b, c;
    cin >> a >> b >> c;
    init();
    vector<int> s = {a, b, c};
    sort(all(s));
    a = s[0], b = s[1], c = s[2];
    ll A = 0, B = 0, C = 0;
    // a - b
    for(int i = 0; i <= a; i++)
    {
        ll me = ncr(a, i);
        me = (me * ncr(b, i)) % mod;
        me = (me * fact[i]) % mod;
        A = (A % mod + me % mod) % mod;
    }
    // b - c
    for(int i = 0; i <= b; i++)
    {
        ll me = ncr(b, i);
        me = (me * ncr(c, i)) % mod;
        me = (me * fact[i]) % mod;
        B = (B % mod + me % mod) % mod;
    }
    // a - c
    for(int i = 0; i <= a; i++)
    {
        ll me = ncr(a, i);
        me = (me * ncr(c, i)) % mod;
        me = (me * fact[i]) % mod;
        C = (C % mod + me % mod) % mod;
    }
    ll ans = A;
    ans = (ans%mod * B%mod)%mod;
    ans = (ans%mod * C%mod)%mod;
    cout<<ans;
    return 0;
}