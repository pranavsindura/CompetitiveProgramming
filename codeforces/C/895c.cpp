#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

int dp[75][1 << 19];
int freq[75], val[75];

const vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int get_mask(int n)
{
    int mask = 0;
    for(int i = 0; i < sz(prime); i++)
        while(n % prime[i] == 0)
            mask ^= 1 << i, n /= prime[i];
    return mask;
}

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

int solve(int i, int mask)
{
    ll &ret = dp[i][mask];
    if(~ret) return ret;

    if(i > 70) return ret = !mask;
    if(!freq[i]) return ret = solve(i + 1, mask);

    ll ans = 0;
    ll p = fpow(2, freq[i] - 1);
    ans = (ans + (p * solve(i + 1, mask)) % mod) % mod;
    ans = (ans + (p * solve(i + 1, mask ^ val[i])) % mod) % mod;
    return ret = ans;
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    for(int i = 1; i <= 70; i++)
        val[i] = get_mask(i);

    clr(dp, -1);
    int ans = solve(0, 0);
    ans = (ans - 1 + mod) % mod;

    cout << ans << endl;
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
