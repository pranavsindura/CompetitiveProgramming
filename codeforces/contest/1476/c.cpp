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

bool can(int a, int b, int c, int d)
{
    int x = min(a, b), y = max(a, b);
    int p = min(c, d), q = max(c, d);
    return !(max(x, p) <= min(y, q));
}

void cp()
{
    int n;
    cin >> n;
    vector<int> c(n), a(n), b(n);
    for(int &x : c)
        cin >> x;
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    for(int i = 0; i < n; i++)
        if(a[i] > b[i])
            swap(a[i], b[i]);
    vector<vector<ll>> dp(n, vector<ll>(2, - 1));

    function<ll(int, int)> dfs = [&](int i, int state)
    {
        if(i == n) return 0LL;
        ll &ret = dp[i][state];
        if(~ret) return ret;
        ll ans = 0;
        if(state == 0)
        {
            if(i + 1 < n)
                ans = max(ans, b[i + 1] - a[i + 1] + 2 + dfs(i + 1, 1));
            ans = max(ans, dfs(i + 1, 0));
        }
        else
        {
            ans = max(ans, (c[i] - 1) * 1LL);
            if(i + 1 < n && a[i + 1] != b[i + 1])
            {
                ans = max(ans, a[i + 1] - 1 + c[i] - b[i + 1] + 2 + dfs(i + 1, 1));
            }
        }
        return ret = ans;
    };
    ll ans = dfs(0, 0);
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

