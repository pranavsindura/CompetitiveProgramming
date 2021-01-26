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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e3 + 5;

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
    if(n < r) return 0;

    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * inv(fact[n - r]) % mod) % mod;
    ans = (ans % mod * inv(fact[r]) % mod) % mod;
    return ans;
}

int n, x, pos;

int tp[MAXN];

void solve(int lo, int hi)
{
    if(lo < hi)
    {
        int mid = (lo + hi) / 2;
        if(pos < mid)
        {
            // i must go left
            tp[mid] = 2;
            hi = mid;
        }
        else
        {
            // i must go right
            tp[mid] = (pos == mid ? -1 : 1);
            lo = mid + 1;
        }
        solve(lo, hi);
    }
}

void cp()
{
    cin >> n >> x >> pos;

    solve(0, n);

    vector<int> cnt(3);
    for(int i = 0; i < n; i++)
        if(~tp[i])
            cnt[tp[i]]++;

    ll ans = 1;
    ans = (ans * (ncr(x - 1, cnt[1]) % mod * fact[cnt[1]] % mod) % mod) % mod;
    ans = (ans * (ncr(n - x, cnt[2]) % mod * fact[cnt[2]] % mod) % mod) % mod;
    ans = (ans * (ncr(n - (cnt[1] + cnt[2]) - 1, cnt[0]) % mod * fact[cnt[0]] % mod) % mod) % mod;

    cout << ans << endl;

    // for -1 i have 1 choice
    // for 1 i have x-1 choice
    // for 2 i have n-x-1 choice
    // for 0, we have whatever is not -1, 1, 2
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