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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;
int parent[100005];
int rankd[100005];
int ans[100005], lp[1000005], impar[100005];
unordered_map<int, int> tree[100005];
unordered_map<int, int> save[1000005];
bool vis[100005];
vector<vector<int>> adj(100005);
vector<vector<pii>> query(100005);
vector<int> arr(100005), ancestor(100005);
vector<int> prime;

void init()
{
    for(int i = 2; i < 1000005; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.pb(i);
        }
        for(int j = 0; j < sz(prime) && i * prime[j] < 1000005; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

void factor(int x)
{
    int temp = x;
    unordered_map<int, int> m;
    while(x > 1)
    {
        m[lp[x]]++;
        x /= lp[x];
    }
    save[temp] = m;
}

void make_set(int v)
{
    parent[v] = v;
    rankd[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    else
    {
        return parent[v] = find_set(parent[v]);
    }
}

int union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rankd[a] < rankd[b])
            swap(a, b);
        parent[b] = a;
        if(rankd[a] == rankd[b])
            rankd[a]++;

    }
}

void dfs(int u, int par)
{
    vis[u] = true;
    ancestor[u] = u;
    factor(arr[u]);
    for(auto x : save[arr[u]])
        tree[u][x.ff] += x.ss;
    impar[u] = par;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v, u);
            union_sets(u, v);
            ancestor[find_set(u)] = u;
        }
    }
    for(pii node : query[u])
    {
        if(vis[node.ff])
            ans[node.ss] = ancestor[find_set(node.ff)];

    }
}

struct Query
{
    int l, r, i;
};

void cp()
{
    tree[1] = unordered_map<int, int>();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        adj[i].clear(), query[i].clear();
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[b].pb(a);
        adj[a].pb(b);
    }
    for(int i = 1; i <= n; i++)
        cin >> arr[i], make_set(i);
    int q;
    scanf("%d", &q);
    vector<pii> qq;
    vector<Query> qarr;
    for(int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Query temp;
        temp.l = a, temp.r = b, temp.i = i;
        qarr.pb(temp);
        query[a].pb(mp(b, i));
        query[b].pb(mp(a, i));
        qq.pb(mp(a, b));
    }
    memset(vis, false, sizeof(vis));
    dfs(1, 1);
    int S = sqrt(n);
    sort(all(qarr), [](Query A, Query B)
    {
        if (A.l / S ！ = B.l / S) return A.l / S < B.l / S;
        return A.r > B.r;
    });
    for(int i = 0; i < q; i++)
    {
        ll mul = 1;
        int anc = ans[i];
        int a = qarr[i].l, b = qarr[i].l;
        unordered_map<int, int> res;
        for(auto x : tree[a])
            res[x.ff] += x.ss;
        for(auto x : tree[b])
            res[x.ff] += x.ss;
        for(auto x : tree[anc])
            res[x.ff] -= x.ss;
        if(anc != 1)
        {
            for(auto x : tree[impar[anc]])
                res[x.ff] -= x.ss;
        }
        for(auto x : res)
            mul = (mul % mod * (x.ss + 1) % mod) % mod;
        printf("%d\n", mul);
    }
}
int main()
{
    int t;
    init();
    t = 1;
    scanf("%d", &t);
    while(t--)
    {
        cp();
    }
    return 0;
}