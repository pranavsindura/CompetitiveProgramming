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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 30;

bool vis[MAXN], in_stack[MAXN], ok;

void dfs(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = true;
    in_stack[u] = true;

    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v, adj, top);
        else if(in_stack[v])
            ok = false;
    }

    top.pb(u);
    in_stack[u] = false;
}

void cp()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;

    ok = true;
    vector<vector<int>> adj(26);
    for(int i = 0; i < n - 1; i++)
    {
        int pos = -1;
        for(int j = 0; j < ln(arr[i]) && j < ln(arr[i + 1]) && pos == -1; j++)
            if(arr[i][j] != arr[i + 1][j])
                pos = j;

        if(~pos)
            adj[arr[i][pos] - 'a'].pb(arr[i + 1][pos] - 'a');
        else
            // arr[i] must be smaller than arr[i + 1] in length
            if(ln(arr[i]) > ln(arr[i + 1]))
                ok = false;
    }

    vector<int> top;
    for(int i = 0; i < 26; i++)
        if(!vis[i])
            dfs(i, adj, top);

    if(ok)
    {
        reverse(all(top));
        for(int x : top)
            cout << char(97 + x);
        cout << endl;
    }
    else
        cout << "Impossible\n";
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