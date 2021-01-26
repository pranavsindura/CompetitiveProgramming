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

/*
	First find the nodes at level d, and the level of each node
	then using a brute force recursion
	for each node at level d
	try all edges going to it from some node at level d - 1
	and construct the shortest path trees, we only need k
*/

vector<vector<int>> edges, adj, by_depth;
vector<bool> vis;
vector<int> depth_of;

int mx_depth;
void bfs()
{
    queue<pi> q;
    q.push({1, 0});
    while(!q.empty())
    {
        int u, d;
        pi node = q.front();
        q.pop();
        u = node.ff, d = node.ss;
        mx_depth = max(mx_depth, d);
        by_depth[d].pb(u);
        depth_of[u] = d;
        vis[u] = 1;

        for(int i : adj[u])
        {
            int v = (edges[i][0] == u ? edges[i][1] : edges[i][0]);
            if(!vis[v])
                q.push({v, d + 1}), vis[v] = 1;
        }
    }
}

int rem;
vector<string> ans;

void rec(int d, int idx, string &picked)
{
    if(rem <= 0)
        return;

    if(d > mx_depth)
    {
        ans.pb(picked);
        rem--;
        return;
    }

    if(idx >= sz(by_depth[d]))
    {
        rec(d + 1, 0, picked);
        return;
    }

    // try edges of this node
    for(int i : adj[by_depth[d][idx]])
    {
        int v = (edges[i][0] == by_depth[d][idx] ? edges[i][1] : edges[i][0]);
        if(depth_of[v] == d - 1)
        {
            // try this edge
            picked[i] = '1';
            rec(d, idx + 1, picked);
            picked[i] = '0';
        }
    }
}

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    by_depth.resize(n + 1);
    depth_of.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(i);
        adj[v].pb(i);
        edges.pb({u, v});
    }

    vis.resize(n + 1);
    bfs();

    rem = k;
    string picked(m, '0');
    rec(1, 0, picked);

    cout << sz(ans) << endl;
    for(string &x : ans)
        cout << x << endl;
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