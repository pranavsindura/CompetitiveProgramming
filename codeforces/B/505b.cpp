#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
set<int> mat[105][105];
vector<int> adj[105];

bool bfs(int start, int end, int color)
{
    bool vis[105];
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(start);
    vis[start]=true;
    while(!q.empty())
    {
        int u = q.front();
        if(u == end)
            return true;
        vis[u] = true;
        q.pop();
        for(int x : adj[u])
        {
            if(mat[u][x].count(color) && !vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
        }
    }
    return false;
}

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mat[a][b].insert(c);
        mat[b][a].insert(c);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int count = 0;
        for(int i = 1; i <= m; i++)
        {
            if(bfs(a, b, i))
                count++;
        }
        cout << count << endl;
    }
    return 0;
}