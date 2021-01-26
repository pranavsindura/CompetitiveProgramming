#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e6 + 5;

ll fact[MAXN], invfact[MAXN];

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    invfact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        invfact[i] = inv(fact[i]);
}

ll perm(string &a, string &b)
{
    int n = ln(a);

    vector<int> freq(26, 0);
    for(char x : a)
        freq[x - 'a']++;

    ll perm = fact[n];
    for(int x : freq)
        perm = (perm * invfact[x]) % mod;

    int len = n;
    ll up = 0;
    for(int i = 0; i < n; i++)
    {
        // less at i, equal before
        for(char c = 'a'; c < b[i]; c++)
        {
            if(freq[c - 'a'] == 0) continue;
            ll nperm = (perm * fact[freq[c - 'a']]) % mod;
            nperm = (nperm * invfact[freq[c - 'a'] - 1]) % mod;
            nperm = (nperm * invfact[len]) % mod;
            nperm = (nperm * fact[len - 1]) % mod;
            up = (up + nperm) % mod;
        }
        if(freq[b[i] - 'a'] == 0) break;
        ll nperm = (perm * fact[freq[b[i] - 'a']]) % mod;
        nperm = (nperm * invfact[freq[b[i] - 'a'] - 1]) % mod;
        nperm = (nperm * invfact[len]) % mod;
        nperm = (nperm * fact[len - 1]) % mod;
        perm = nperm;
        freq[b[i] - 'a']--;
        len--;
    }
    return up;
}

string a, b;

void cp()
{
    init();

    cin >> a >> b;

    ll up = perm(a, b);
    ll down = perm(a, a);
    down = (down + 1) % mod;

    cout << (up - down + mod) % mod << endl;
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

