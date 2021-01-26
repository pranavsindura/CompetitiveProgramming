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
const ll inf = 1e15;
const int MAXN = 3e2 + 5;

ll dp[MAXN][MAXN];
ll cost[MAXN][MAXN];

void cp()
{
    int n, K, m;
    cin >> n >> m >> K;
    vector<array<ll, 3>> arr(m);
    for(auto &v : arr)
        cin >> v[0] >> v[1] >> v[2];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            cost[i][j] = dp[i][j] = inf;

    for(int i = 0; i < m; i++)
        for(int j = arr[i][0]; j <= arr[i][1]; j++)
            cost[j][arr[i][1]] = min(cost[j][arr[i][1]], arr[i][2]);
    for(int i = 1; i <= n; i++)
        for(int j = n - 1; j >= i; j--)
            cost[i][j] = min(cost[i][j], cost[i][j + 1]);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= n; k++)
        {
            dp[i][k] = min(dp[i][k], dp[i - 1][k]);
            for(int j = 1; j <= i; j++)
                if(k - (i - j + 1) >= 0)
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - (i - j + 1)] + cost[j][i]);
        }

    ll ans = inf;
    for(int k = K; k <= n; k++) ans = min(ans, dp[n][k]);
    if(ans == inf) ans = -1;
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

