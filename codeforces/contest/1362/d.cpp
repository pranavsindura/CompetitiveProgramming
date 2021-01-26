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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

vector<vector<int>> topic(MAXN);
vector<vector<int>> adj(MAXN);
bool vis[MAXN];
int topic_of[MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        topic[t].pb(i + 1);
        topic_of[i + 1] = t;
    }
    bool ok = true;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
        sort(all(adj[i]), [&](int a, int b)
    {
        return topic_of[a] < topic_of[b];
    });

    for(int i = 1; i <= n; i++)
    {
        for(int u : topic[i])
        {
            int mex = 1;
            for(int v : adj[u])
            {
                if(vis[v])
                {
                    if(topic_of[v] == mex)
                        mex++;
                }
            }
            ans.pb(u);
            vis[u] = true;
            if(mex != i)
                ok = false;
        }
    }
    if(ok)
        for(int x : ans)
            cout << x << " ";
    else
        cout << -1;
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