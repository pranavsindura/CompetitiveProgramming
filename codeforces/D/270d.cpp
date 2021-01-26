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
const int MAXN = 5e3 + 5;

// Iterative DP

int arr[MAXN];
int dp[MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    double garb;
    for(int i = 0; i < n; i++)
        cin >> arr[i] >> garb;

    // Can remove 1 dimension

    for(int i = n - 1; i >= 0; i--)
        for(int j = m; j >= 0; j--)
            if(arr[i] < j)
                dp[j] = 1 + dp[j];
            else
                dp[j] = min(1 + dp[j], dp[arr[i]]);

    cout << dp[0] << endl;
}

// Recursive DP

// int arr[MAXN];
// int dp[MAXN][MAXN];
// int n, m;

// int solve(int i, int last)
// {
//     if(i == n)
//         return 0;

//     int &ret = dp[i][last];
//     if(~ret)
//         return ret;

//     int ans = 1e5;
//     if(arr[i] < last) // must be uprooted
//         ans = 1 + solve(i + 1, last);
//     else
//     {
//         // uproot?
//         ans = min(ans, 1 + solve(i + 1, last));
//         // dont uproot?
//         ans = min(ans, solve(i + 1, arr[i]));
//     }
//     return ret = ans;
// }

// void cp()
// {
//     cin >> n >> m;
//     double garb;
//     for(int i = 0; i < n; i++)
//         cin >> arr[i] >> garb;
//     clr(dp, -1);
//     int ans = solve(0, 0);
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