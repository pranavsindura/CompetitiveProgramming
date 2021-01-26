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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e3 + 5;
using namespace std;

vector<vector<int>> adj(MAXN);
int mxd;

void dfs(int u, int d)
{
    mxd = max(mxd, d);
    for(int v : adj[u])
        dfs(v, d + 1);
}

void cp()
{
    int n;
    cin >> n;
    vector<int> roots;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if(p == -1)
            roots.pb(i);
        else
            adj[p-1].pb(i);
    }
    for(int u : roots)
        dfs(u, 1);
    cout << mxd << endl;
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