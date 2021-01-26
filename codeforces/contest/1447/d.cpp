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
const int MAXN = 5e3 + 5;

int n, m;
string a, b;
int dp[MAXN][MAXN][2];

void cp()
{
    cin >> n >> m >> a >> b;

    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
        {
            dp[i][j][1] = max(dp[i][j][1], 4 * (a[i] == b[j]) - 2 + dp[i + 1][j + 1][1]);
            dp[i][j][1] = max(dp[i][j][1], -1 + dp[i + 1][j][1]);
            dp[i][j][1] = max(dp[i][j][1], -1 + dp[i][j + 1][1]);
            dp[i][j][0] = max(dp[i][j][0], dp[i][j][1]);
            dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][0]);
            dp[i][j][0] = max(dp[i][j][0], dp[i][j + 1][0]);
        }

    cout << dp[0][0][0] << endl;
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

/*
int solve(int i, int j, int stat)
{
    if(stat == 2 || i == n || j == m)
        return 0;
 
    int &ret = dp[i][j][stat];
    if(~ret)
        return ret;
 
    int ans = 0;
    if(stat == 0) // not started yet
    {
        // choose to start
        ans = max(ans, solve(i, j, 1));
        // skip i
        ans = max(ans, solve(i + 1, j, 0));
        // skip j
        ans = max(ans, solve(i, j + 1, 0));
    }
    else // started
    {
        // choose to end
        ans = max(ans, 4 * (a[i] == b[j]) - 2 + solve(i, j, 2));
        // LCS
        if(a[i] == b[j])
            ans = max(ans, 4 - 2 + solve(i + 1, j + 1, 1));
        // skip i
        ans = max(ans, - 1 + solve(i + 1, j, 1));
        // skip j
        ans = max(ans, - 1 + solve(i, j + 1, 1));
    }
 
    return ret = ans;
}
*/