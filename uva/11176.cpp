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

double dp[505][505];
int n;
double p;

/*
    O(n^3)
    dp(i, curstreak, longeststreak) =
        p * dp(i+1, curstreak+1, max(curstreak+1, longeststreak)) // winning
        + (1 - p) * dp(i+1, 0, longeststreak) // losing

    O(n^2) little bit of math magic
    just find prob of having at most j as the longest streak
    Then prob of having j as the longest streak = at most (j) - at most (j - 1)

    i-th game, with streak at most j

    try to win, j > 0

    some special cases to consider
    winning can cause a segment of j+1 consecutive wins, we need to remove that

    try to lose

*/

void cp()
{
    fix(6);
    while(cin >> n >> p && n)
    {
        clr(dp, 0);
        for(int i = 0; i <= n; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                // win
                if(j > 0)
                {
                    dp[i][j] += dp[i - 1][j] * p;
                    if(j <= i - 2)
                        dp[i][j] -= dp[i - j - 2][j] * pow(p, j + 1) * (1 - p);
                    else if(j == i - 1)
                        dp[i][j] -= pow(p, i);
                }
                // lose
                dp[i][j] += dp[i - 1][j] * (1 - p);
            }
        }
        double ans = 0;
        for(int i = 1; i <= n; i++)
            ans += i * (dp[n][i] - dp[n][i-1]);
        cout << ans << endl;
    }
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

