#include<bits/stdc++.h>
#define ll long long int
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 2e5 + 5;
int color[MAXN];
bool vis[MAXN];
vector<vector<int>> adj(MAXN);
map<int, int> freq;

void dfs(int u)
{
    vis[u] = true;
    freq[color[u]]++;
    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v);
    }
}

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> color[i + 1];
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int cost = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            freq.clear();
            dfs(i);
            int mx = INT_MIN;
            int total = 0;
            for(auto x : freq)
            {
                total += x.ss;
                mx = max(mx, x.ss);
            }
            cost += total - mx;
        }
    }
    cout << cost;
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