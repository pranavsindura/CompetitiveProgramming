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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e3 + 5;

ll a, b, n;
string s;
ll dp[MAXN][3];
ll solve(ll i, ll f)
{
    if(i == n) return 0;
    ll &ret = dp[i][f];
    if(~ret) return ret;

    ll ans = inf;
    if(i == 0)
    {
        if(s[i] == 'C')
            ans = min(ans, solve(i + 1, 0));
        else if(s[i] == 'J')
            ans = min(ans, solve(i + 1, 1));
        else
        {
            ans = min(ans, solve(i + 1, 0));
            ans = min(ans, solve(i + 1, 1));
        }
    }
    else
    {
        string t = s.substr(i - 1, 2);
        if(s[i] == 'C')
        {
            if(f == 0)
                ans = min(ans, solve(i + 1, 0));
            else if(f == 1)
                ans = min(ans, b + solve(i + 1, 0));
        }
        else if(s[i] == 'J')
        {
            if(f == 0)
                ans = min(ans, a + solve(i + 1, 1));
            else if(f == 1)
                ans = min(ans, solve(i + 1, 1));
        }
        else
        {
            if(f == 0)
            {
                ans = min(ans, solve(i + 1, 0));
                ans = min(ans, a + solve(i + 1, 1));
            }
            else if(f == 1)
            {
                ans = min(ans, b + solve(i + 1, 0));
                ans = min(ans, solve(i + 1, 1));
            }
        }
    }
    return ret = ans;
}

void cp()
{
    cin >> a >> b >> s;
    n = sz(s);
    clr(dp, -1);
    cout << solve(0, 2) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
