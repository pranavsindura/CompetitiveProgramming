#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

const int MAX_CHAR = 27;
const char base = 'a';
struct trie
{
    trie *child[MAX_CHAR];
    bool isLeaf;
    int pos;
    trie()
    {
        clr(child, 0);
        isLeaf = 0;
        pos = -1;
    }

    void insert(const string &s, int _pos, int idx = 0)
    {
        if(idx == ln(s))
            isLeaf = 1, pos = _pos;
        else
        {
            int c = isalpha(s[idx]) ? s[idx] - base : 26;
            if(child[c] == 0)
                child[c] = new trie;
            child[c]->insert(s, _pos, idx + 1);
        }
    }

    vector<int> dfs(const string &s, int idx = 0)
    {
        if(idx == ln(s))
            return {pos};
        else
        {
            vector<int> match;
            int c = s[idx] - base;
            if(child[c])
            {
                vector<int> cmatch = child[c]->dfs(s, idx + 1);
                for(int x : cmatch) match.push_back(x);
            }
            c = 26;
            if(child[c])
            {
                vector<int> cmatch = child[c]->dfs(s, idx + 1);
                for(int x : cmatch) match.push_back(x);
            }
            return match;
        }
    }
};

bool cycle;
void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, vector<int> &instack, vector<int> &top)
{
    vis[u] = 1;
    instack[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj, vis, instack, top);
        else if(instack[v])
            cycle = 1;
    top.pb(u);
    instack[u] = 0;
}

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> pat(n), text(m);
    vector<int> need(m), used(n);
    for(auto &x : pat)
        cin >> x;
    for(int i = 0; i < m; i++)
        cin >> text[i] >> need[i], need[i]--;

    trie *root = new trie();
    for(int i = 0; i < n; i++)
        root->insert(pat[i], i);

    bool ok = true;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++)
    {
        vector<int> match = root->dfs(text[i]);
        bool does = false;
        for(int x : match)
            if(x != need[i])
                adj[need[i]].push_back(x);
            else
                does = true;
        ok &= does;
    }

    cycle = false;
    vector<int> top, vis(n), instack(n);
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i, adj, vis, instack, top);
    ok &= !cycle;

    reverse(all(top));

    cout << (ok ? "YES\n" : "NO\n");
    if(ok)
    {
        for(int x : top)
            cout << x + 1 << " ";
        cout << endl;
    }
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

