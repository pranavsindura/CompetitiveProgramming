#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e5 + 5;
vector<vector<int>> adj(MAXN);
vector<int> init(MAXN, 0);
vector<int> goal(MAXN, 0);
vector<bool> vis(MAXN, false);
int n;
vector<int> ans;
void dfs(int u, int odd_carry, int even_carry, int depth)
{
    vis[u] = true;
    int curr = 0;
    if(depth & 1)
        curr = (init[u] + odd_carry) % 2;
    else
        curr = (init[u] + even_carry) % 2;
    if(curr != goal[u])
    {
        ans.pb(u);
        if(depth & 1)
            odd_carry++;
        else
            even_carry++;
    }
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, odd_carry, even_carry, depth + 1);
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        cin >> init[(i + 1)];
    for(int i = 0; i < n; i++)
        cin >> goal[(i + 1)];
    dfs(1, 0, 0, 0);
    cout << sz(ans) << endl;
    for(int x : ans)
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