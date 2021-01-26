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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e4 + 5;

/*
Every path except the start and end path will be visited twice
It makes sense to not visit the diameter twice as it is the longest path
*/

int dist[MAXN];

void dfs(int u, int par, vector<vector<int>> &adj)
{
    for(int v : adj[u])
    {
        if(v != par)
        {
            dist[v] = dist[u] + 1;
            dfs(v, u, adj);
        }
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        adj[i].resize(m);
        for(int &x : adj[i])
            cin >> x, x--;
    }

    fill(dist, dist + n, 0);
    dfs(0, -1, adj);

    int p = max_element(dist, dist + n) - dist;

    fill(dist, dist + n, 0);
    dfs(p, -1, adj);

    int dia = *max_element(dist, dist + n);

    int ans = 2 * (n - 1) - dia;

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}