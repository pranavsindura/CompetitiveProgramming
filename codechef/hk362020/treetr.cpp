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
ll val[100005];
ll ans[500005];
bool vis[100005];
vector<vector<int>> adj(100005);
vector<int> tour;
int entry[100005], exi[100005];
void dfs(int u, int par)
{
    tour.push_back(u);
    for(int x : adj[u])
    {
    	if(x != par)
        	dfs(x, u);
    }
    tour.push_back(u);
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        ans[v] = val[tour[tl]] * val[tour[tl]];
    else
    {
        int tm = (tr + tl) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        ans[v] = ans[2 * v] + ans[2 * v + 1];
    }
}
void update(int v, int tl, int tr, int pos, ll newval)
{
    if(tl == tr)
    {
    	// cout<<v<<"-> "<<ans[v]<<endl;
        ans[v] = newval * newval;
        val[tour[tl]] = newval;
    }
    else
    {
        int tm = (tr + tl) / 2;
        if(pos <= tm)
        {
            update(2 * v, tl, tm, pos, newval);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, newval);
        }
        ans[v] = ans[2 * v] + ans[2 * v + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return ans[v];
    else
    {
        int tm = (tr + tl) / 2;
        return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    }

}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> val[i + 1];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < sz(tour); i++)
    {
        if(vis[tour[i]])
            exi[tour[i]] = i;
        else
        {
            entry[tour[i]] = i;
            vis[tour[i]] = true;
        }
    }
    // for(int x: tour)
    // 	cout<<x<<" ";
    // cout<<endl;
    // for(int x: tour)
    // 	cout<<entry[x]<<" "<<exi[x]<<endl;
    // cout<<endl;
    build(1, 0, sz(tour) - 1);
    // for(int i = 0; i < 4 * sz(tour); i++)
    //     cout << ans[i] << " ";
    // cout << endl;
    int q;
    cin >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int node;
            ll newval;
            cin >> node >> newval;
            update(1, 0, sz(tour) - 1, entry[node], newval);
            update(1, 0, sz(tour) - 1, exi[node], newval);
        //                     for(int i = 0; i < sz(tour); i++)
        //     cout << tour[i] << ": " << query(1, 0, sz(tour) - 1, entry[tour[i]], exi[tour[i]]) / 2 <<endl;
        // cout << endl;
        }
        else
        {
            int node;
            cin >> node;
            cout << query(1, 0, sz(tour) - 1, entry[node], exi[node]) / 2 << endl;
        }
    }
    return 0;
}