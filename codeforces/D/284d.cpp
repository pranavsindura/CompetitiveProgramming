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
const int MAXN = 2e5 + 5;

int arr[MAXN], n;
ll dp[MAXN][2];

ll solve(int i, int dir)
{
    if(i <= 0 || i > n)
        return 0;

    ll &ret = dp[i][dir];
    if(~ret)
        return ret;
    // how to handle cycles?
    // if there is cycle then there will be infinite loop
    // so set ret to some value first
    // we need to set ret = something not -1, because we have visited it
    ret = -3e14;

    if(dir)
        ret = arr[i] + solve(i - arr[i], dir ^ 1);
    else
        ret = arr[i] + solve(i + arr[i], dir ^ 1);
    return ret;
}

void cp()
{
    cin >> n;
    for(int i = 2; i <= n; i++)
        cin >> arr[i];
    clr(dp, -1);
    for(int i = 1; i <= n - 1; i++)
    {
        ll ans = i + solve(i + 1, 1);
        ans = max(ans, -1LL);
        cout << ans << endl;
    }
}

// Graph Building + DFS + DP

// int arr[MAXN];
// ll dp[MAXN][2];
// bool vis[MAXN][2], in_stack[MAXN][2];
// int adj[MAXN][2];


// bool dfs(int u, int dir)
// {
//     vis[u][dir] = 1;
//     in_stack[u][dir] = 1;
//     dp[u][dir] = arr[u];

//     bool cycle = false;

//     if(~adj[u][dir])
//     {
//         if(!vis[ adj[u][dir] ][dir ^ 1])
//             cycle |= dfs(adj[u][dir], dir ^ 1);
//         else if(in_stack[adj[u][dir]][dir ^ 1])
//             cycle = true;
//         dp[u][dir] += dp[adj[u][dir]][dir ^ 1];
//     }

//     if(cycle)
//         dp[u][dir] = -3e14;

//     in_stack[u][dir] = 0;
//     return cycle;
// }


// void cp()
// {
//     int n;
//     cin >> n;
//     for(int i = 2; i <= n; i++)
//         cin >> arr[i];

//     for(int i = 2; i <= n; i++)
//     {
//         int pos = i + arr[i];
//         adj[i][0] = adj[i][1] = -1;
//         if(pos >= 1 && pos <= n)
//             adj[i][0] = pos;
//         pos = i - arr[i];
//         if(pos >= 1 && pos <= n)
//             adj[i][1] = pos;
//     }

//     adj[1][1] = -1;
//     vis[1][0] = in_stack[1][0] = 1;

//     for(int i = 2; i <= n; i++)
//     {
//         if(!vis[i][0])
//             dfs(i, 0);
//         if(!vis[i][1])
//             dfs(i, 1);
//     }

//     for(int i = 1; i <= n - 1; i++)
//     {
//         int pos = i + 1;
//         ll ans;
//         if(pos >= 1 && pos <= n)
//         {
//             if(dp[pos][1] <= 0)
//                 ans = -1;
//             else
//                 ans = dp[pos][1] + i;
//         }
//         else
//             ans = i;
//         cout << ans << endl;
//     }
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