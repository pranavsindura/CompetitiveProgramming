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
const int MAXN = 1e5 + 5;

vector<vector<pi>> edges(MAXN);
int dp[3 * MAXN], inter[3 * MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].pb({u, v});
    }

    for(int i = 0; i < MAXN; i++)
    {
        for(pi e : edges[i])
            inter[e.ss] = 0;

        for(pi e : edges[i])
            inter[e.ss] = max(inter[e.ss], dp[e.ff] + 1);

        for(pi e : edges[i])
            dp[e.ss] = max(dp[e.ss], inter[e.ss]);
    }

    cout << *max_element(dp + 1, dp + n + 1) << endl;
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

// TLE 

// vector<vector<int>> adj;
// vector<array<int, 3>> edges;
// int processed[MAXN];

// int dfs(int u, int idx)
// {
//     if(~processed[idx])
//         return processed[idx];

//     processed[idx] = 0;
//     for(int &e : adj[u])
//     {
//         int v = edges[e][1];
//         int w = edges[e][2];
//         if(w > edges[idx][2])
//             processed[idx] = max(processed[idx], 1 + dfs(v, e));
//     }
//     return processed[idx];
// }

// void cp()
// {
//     int n, m;
//     cin >> n >> m;

//     adj.resize(n + 1);
//     fill(processed, processed + m, -1);

//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges.pb({u, v, w});
//         adj[edges[i][0]].pb(i);
//     }

//     edges.pb({0, 0, 0});

//     int ans = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         processed[m] = -1;
//         int me = dfs(i, m);
//         ans = max(ans, me);
//     }

//     cout << ans << endl;
// }