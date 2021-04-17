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

ll dp[MAXN + 5][MAXN + 5];
void cp()
{
    int n, k;
    cin >> n >> k;
    clr(dp, 0);
    for(int i = 2; i <= k; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = j;
            dp[i][j] = (dp[i][j] + dp[i - 1][n - 1]) % mod;
            if(n - j - 1)
                dp[i][j] = (dp[i][j] - dp[i - 1][n - j - 1] + mod) % mod;
        }
        for(int a = 1; a < n; a++)
            dp[i][a] = (dp[i][a] + dp[i][a - 1]) % mod;
    }
    cout << (dp[k][n] + 1) % mod << endl;
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
