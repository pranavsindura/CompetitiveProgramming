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

ll n;
int m;
vector<int> dig;
vector<ll> p(18);
ll dp[1 << 18][101];

ll solve(int mask, int rem)
{
    if(mask == 0)
        return rem == 0;

    ll &ret = dp[mask][rem];
    if(~ret)
        return ret;

    int last = -1;
    ll ans = 0;
    for(int i = 0; i < sz(dig); i++)
        if(((mask >> i) & 1) && (dig[i] || __builtin_popcount(mask) > 1))
        {
            if(dig[i] == last) continue;
            last = dig[i];
            ans += solve(mask ^ (1 << i), (p[sz(dig) - __builtin_popcount(mask)] * dig[i] + rem) % m);
        }
    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    while(n)
        dig.pb(n % 10), n /= 10;
    sort(all(dig));
    p[0] = 1;
    for(int i = 1; i < 18; i++)
        p[i] = (p[i - 1] * 10) % m;
    clr(dp, -1);
    cout << solve((1 << sz(dig)) - 1, 0) << endl;
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

