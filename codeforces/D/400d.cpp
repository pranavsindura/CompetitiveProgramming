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
const int MAXN = 1e5 + 5;

// 'type' of each node
int type_of[MAXN];
// counts nodes
int counter = 1;
int adj[502][502];

struct edge
{
    int u, v, w;
    edge() {}
    edge(int u, int v, int w): u(u), v(v), w(w) {}
    const bool operator<(const edge &e) const
    {
        return w < e.w;
    }
};

int parent[MAXN];
int size[MAXN];
int total_cost[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(size, size + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool union_set(int a, int b, int cost)
{
    int u = a, v = b;
    a = find_set(a), b = find_set(b);
    if(a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        total_cost[a] += total_cost[b];
        // add cost of edge only if they are of same type
        if(type_of[u] == type_of[v])
            total_cost[a] += cost;
        return true;
    }
    else
        return false;
}


void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt_of(k + 1);
    for(int i = 1; i <= k; i++)
    {
        cin >> cnt_of[i];
        for(int j = 0; j < cnt_of[i]; j++)
            type_of[counter++] = i;
    }
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= k; j++)
            adj[i][j] = INT_MAX;
    vector<edge> edge_list;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge e(u, v, w);
        edge_list.pb(e);
        if(type_of[u] != type_of[v])
        {
            adj[type_of[u]][type_of[v]] = min(adj[type_of[u]][type_of[v]], w);
            adj[type_of[v]][type_of[u]] = min(adj[type_of[v]][type_of[u]], w);
        }
    }

    bool ok = true;

    make_set(n + 1);
    // Kruskal MST
    sort(all(edge_list));
    for(edge &e : edge_list)
        union_set(e.u, e.v, e.w);

    counter = 1;
    for(int i = 1; i <= k; i++)
    {
        int first_one = counter;
    	// All nodes of type i must have same parent
    	// and cost of that parent's connected components should be zero
        int par = find_set(first_one);

        if(total_cost[par])
            ok = false;

        for(int j = 0; j < cnt_of[i]; j++)
            if(find_set(first_one + j) != par)
                ok = false;

        counter += cnt_of[i];
    }

    // Floyd Warshall
    for(int a = 1; a <= k; a++)
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <= k; j++)
                if(adj[i][a] != INT_MAX && adj[a][j] != INT_MAX)
                    adj[i][j] = min(adj[i][j], adj[i][a] + adj[a][j]);

    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= k; j++)
            if(i == j)
                adj[i][j] = 0;
            else if(adj[i][j] == INT_MAX)
                adj[i][j] = -1;

    if(ok)
    {
        cout << "Yes\n";
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= k; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No\n";
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