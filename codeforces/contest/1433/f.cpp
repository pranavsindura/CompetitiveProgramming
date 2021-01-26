#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int inf = 1e7;

// Iterative DP

int n, m, k;
int arr[100][100];
int dp[75][40][75];

void cp()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    // can remove the first dimension

    for(int j = 0; j <= m; j++)
        for(int a = 0; a < m / 2 + 1; a++)
            for(int b = 0; b <= k; b++)
                dp[j][a][b] = -inf;

    for(int i = 0; i < m / 2 + 1; i++)
        dp[0][i][0] = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m; j >= 0; j--)
        {
            for(int a = m / 2; a >= 0; a--)
            {
                for(int b = k - 1; b >= 0; b--)
                {
                    if(j == m)
                        dp[j][a][b] = dp[0][0][b];
                    else
                    {
                        if(a < m / 2)
                            dp[j][a][b] = max(dp[j][a][b], arr[i][j] + dp[j + 1][a + 1][(b + arr[i][j]) % k]);
                        dp[j][a][b] = max(dp[j][a][b], dp[j + 1][a][b]);
                    }
                }
            }
        }
    }

    int ans = dp[0][0][0];
    cout << ans << endl;
}

// Recursive DP

// int n, m, k;
// int arr[100][100];

// int dp[75][75][40][75];

// int solve(int i, int j, int picked, int rem)
// {
//     int &ret = dp[i][j][picked][rem];
//     if(~ret)
//         return ret;

//     if(j == m && i == n)
//         // base case
//         return ret = (rem ? -inf : 0);
//     else if(j == m)
//         // goto next row
//         return ret = solve(i + 1, 0, 0, rem);

//     // choose arr[i][j] or not
//     int ans = -inf;
//     // choose if can
//     if(picked < m / 2)
//         ans = max(ans, arr[i][j] + solve(i, j + 1, picked + 1, (rem + arr[i][j]) % k));
//     // dont choose
//     ans = max(ans, solve(i, j + 1, picked, rem));

//     return ret = ans;
// }

// void cp()
// {
//     cin >> n >> m >> k;
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < m; j++)
//             cin >> arr[i][j];
//     clr(dp, -1);
//     int ans = solve(0, 0, 0, 0);
//     cout << ans << endl;
// }

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