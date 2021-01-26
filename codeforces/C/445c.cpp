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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 505;
int n, m;
vector<vector<int>> adj(MAXN);
int val_edge[MAXN][MAXN], val_node[MAXN];

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> val_node[i + 1];
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        val_edge[a][b] = c;
        val_edge[b][a] = c;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    double ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int x : adj[i])
        {
            ans = max(ans, (1.0 * val_node[x] + val_node[i]) / (val_edge[i][x] * 1.0));
        }
    }
    cout << setprecision(15) << fixed << ans;
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