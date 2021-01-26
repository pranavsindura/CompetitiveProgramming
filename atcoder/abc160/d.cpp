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
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

map<int, int> fre;
bool marked[2005][2005];

void bfs(int st, vector<vector<int>> &adj)
{
    vector<bool> vis(2005, false);
    queue<pii> q;
    q.push(mp(st, 0));
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        vis[u.ff] = true;
        if(!marked[st][u.ff])
        {
            fre[u.ss]++;
            marked[st][u.ff] = true;
            marked[u.ff][st] = true;
        }
        for(int x : adj[u.ff])
        {
            if(!vis[x])
            {
                vis[x] = true;
                q.push(mp(x, u.ss + 1));
            }
        }
    }
}

void cp()
{
    int n, x, y;
    cin >> n >> x >> y;
    memset(marked, false, sizeof(marked));
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++)
    {
        adj[i].pb(i + 1);
        adj[i + 1].pb(i);
    }
    adj[x].pb(y);
    adj[y].pb(x);
    for(int i = 1; i <= n; i++)
    {
    	bfs(i, adj);
    }
    for(int i=1;i<n;i++)
    {
    	cout<<fre[i]<<endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}