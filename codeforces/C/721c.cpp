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
const int MAXN = 5e3 + 5;
int n, m, T;
vector<vector<pi>> adj(MAXN);
pi prev_node[MAXN][MAXN];
void dfs(int u, int par, int count, int total)
{
    if(total > T)
        return;
    if(prev_node[u][count].ss <= total)
        return;
    // cout << u << " " << count << " " << total << endl;
    prev_node[u][count] = {par, total};
    if(u == n)
    {
        return;
    }
    for(pi v : adj[u])
    {
        dfs(v.ff, u, count + 1, total + v.ss);
    }
}

void cp()
{
    cin >> n >> m >> T;
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
    }

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            prev_node[i][j] = {-1, INT_MAX};

    dfs(1, 0, 0, 0);
    int len = -1;
    int u = n;
    for(int i = MAXN - 1; i >= 0; i--)
    {
        if(prev_node[n][i].ff != -1)
        {
            len = i;
            break;
        }
    }
    vector<int> ans;
    while(true)
    {
        if(u == 0 || len < 0)
            break;
        ans.pb(u);
        u = prev_node[u][len].ff;
        len--;
    }
    cout << sz(ans) << endl;
    while(!ans.empty())
        cout << ans.back() << " ", ans.pop_back();
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