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

int n, h;
ll dp[40][40][40][2];

ll solve(int l, int r, int d, int make)
{
    ll &ret = dp[l][r][d][make];
    if(~ret) return ret;

    if(l > r) return ret = 1;
    if(l == r) return ret = make ? d >= h : d < h;

    ll ans = 0;
    for(int i = l; i <= r; i++)
    {
        if(make)
        {
            if(i + 1 <= r)
                ans += solve(l, i - 1, d + 1, 0) * solve(i + 1, r, d + 1, 1);
            if(i - 1 >= l)
                ans += solve(l, i - 1, d + 1, 1) * solve(i + 1, r, d + 1, 0);
            if(i - 1 >= l && i + 1 <= r)
                ans += solve(l, i - 1, d + 1, 1) * solve(i + 1, r, d + 1, 1);
        }
        else
            ans += solve(l, i - 1, d + 1, 0) * solve(i + 1, r, d + 1, 0);
    }
    return ret = ans;
}

void cp()
{
    cin >> n >> h;
    clr(dp, -1);
    cout << solve(1, n, 1, 1) << endl;
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
