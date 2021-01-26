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
const int mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2e5 + 5;

// 10^8 can run in 2s easily, just don't use long long and mod only when needed

int R, G;
int dp[2][MAXN], ways[2][MAXN];
void cp()
{
    cin >> R >> G;
    int x = 0;
    for(int h = 1; h <= 900; h++)
    {
        for(int r = 0; r <= R; r++)
        {
            dp[x][r] = dp[x ^ 1][r];
            if(r >= h) // make with red
                dp[x][r] = max(dp[x][r], 1 + dp[x ^ 1][r - h]);
            if(h * (h + 1) / 2 - r <= G) // make with green
                dp[x][r] = max(dp[x][r], 1 + dp[x ^ 1][r]);
        }
        x ^= 1;
    }
    int H = dp[1][R];
    x = 1;
    ways[0][0] = 1;
    for(int h = 1; h <= H; h++)
    {
        for(int r = 0; r <= R; r++)
        {
            ways[x][r] = 0;
            if(r >= h) // make with red
                (ways[x][r] += ways[x ^ 1][r - h]) %= mod;
            if(h * (h + 1) / 2 - r <= G) // make with green
                (ways[x][r] += ways[x ^ 1][r]) %= mod;
        }
        x ^= 1;
    }
    int ans = 0;
    for(int i = 0; i <= R; i++)
        ans = (ans + ways[x ^ 1][i]) % mod;
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

