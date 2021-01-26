#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e2 + 5;
ll dp[MAXN][MAXN][MAXN];
void cp()
{
    int n, m, K;
    cin >> n >> m >> K;

    vector<int> colour(n + 1, 0);
    for(int i = 0; i < n; i++)
        cin >> colour[i + 1];

    int cost[n + 1][m + 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> cost[i + 1][j + 1];

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            for(int k = 0; k < MAXN; k++)
                dp[i][j][k] = 1e18;

    if(colour[1] == 0)
    {
        for(int i = 1; i <= m; i++)
            dp[1][i][1] = cost[1][i];
    }
    else
    {
        dp[1][colour[1]][1] = 0;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int k = 1; k <= K; k++)
        {
            if(colour[i] == 0)
            {
                for(int j = 1; j <= m; j++)
                {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][j]);
                    for(int c = 1; c <= m; c++)
                    {
                        if(c == j)
                            continue;
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][c][k - 1] + cost[i][j]);
                    }
                }
            }
            else
            {
                dp[i][colour[i]][k] = min(dp[i][colour[i]][k], dp[i - 1][colour[i]][k]);
                for(int c = 1; c <= m; c++)
                {
                    if(c == colour[i])
                        continue;
                    dp[i][colour[i]][k] = min(dp[i][colour[i]][k], dp[i - 1][c][k - 1]);
                }
            }
        }
    }

    ll mi = 1e18;
    for(int j = 1; j <= m; j++)
        mi = min(mi, dp[n][j][K]);
    if(mi >= (ll)1e18)
        cout << -1;
    else
        cout << mi;
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