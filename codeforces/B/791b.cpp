#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll nodes = 0, edges = 0;
vector<bool> vis(150005, false);
vector<vector<int>> adj(150005);
void dfs(int u)
{
    vis[u] = true;
    nodes++;
    for(int x : adj[u])
    {
    	edges++;
        if(!vis[x])
            dfs(x);
    }
}

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool f = true;
    for(int i = 1; i <= n; i++)
    {
        nodes = 0, edges = 0;
        if(!vis[i])
        {
            dfs(i);
            edges /= 2;
            // cout<<nodes<<" "<<edges<<endl;
            if(edges != ((nodes - 1)*nodes / 2))
                f = false;
        }

    }
    cout << (f ? "YES" : "NO");
    return 0;
}