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
const int MAXN = 1e6 + 5;

bool vis[MAXN];
vector<vector<int>> adj(MAXN);
int idx;
map<string, int> compress;

int get_idx(string &s)
{
    if(compress.count(s))
        return compress[s];
    else
        return compress[s] = idx++;
}

int mx_file, mx_folder;
// folder, file
pi dfs(int u, int depth)
{
    // cout << depth << ": " << u << endl;
    vis[u] = true;
    pi res = {0, 0};
    bool leaf = true;

    for(int v : adj[u])
    {
        if(!vis[v])
        {
            leaf = false;
            pi child = dfs(v, depth + 1);
            res.ff += child.ff, res.ss += child.ss;
        }
    }

    if(leaf)
        res = {0, 1};
    if(depth)
    {
        mx_folder = max(mx_folder, res.ff);
        mx_file = max(mx_file, res.ss);
    }

    if(!leaf)
    	res.ff++;

    return res;
}

void cp()
{
    string s;
    vector<int> roots;
    while(cin >> s)
    {
        vector<string> split;
        string temp;
        for(char x : s)
        {
            if(x == '\\')
                split.pb(temp);
            else
                temp += x;
        }
        split.pb(temp);

        vector<int> nodes;
        temp = "";
        for(string &x : split)
        {
        	temp += x;
            nodes.pb(get_idx(temp));
        }

        roots.pb(nodes.front());
        for(int i = 0; i < sz(nodes) - 1; i++)
            adj[nodes[i]].pb(nodes[i + 1]);
    }

    for(int u : roots)
        dfs(u, 0);

    cout << mx_folder << " " << mx_file;
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