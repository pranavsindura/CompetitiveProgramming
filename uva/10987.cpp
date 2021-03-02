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

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int w;
            cin >> w;
            adj[i][j] = adj[j][i] = w;
        }
    }
    vector<vector<int>> F = adj;
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                F[i][j] = min(F[i][j], F[i][k] + F[k][j]);

    if(F == adj)
    {
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                edges.push_back({i, j, adj[i][j]});

        sort(all(edges), [&](vector<int> A, vector<int> B)
        {
            return A[2] < B[2];
        });

        adj.assign(n, vector<int>(n, inf));
        for(int i = 0; i < n; i++) adj[i][i] = 0;

        vector<vector<int>> keep;
        for(int i = 0; i < sz(edges); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(w < adj[u][v])
            {
                adj[u][v] = adj[v][u] = w;
                for(int a = 0; a < n; a++)
                    for(int b = 0; b < n; b++)
                        adj[a][b] = min({adj[a][b], adj[a][u] + w + adj[v][b], adj[a][v] + w + adj[u][b]});
                keep.push_back(edges[i]);
            }
        }

        sort(all(keep));
        cout << sz(keep) << endl;
        for(auto v : keep)
            cout << v[0] + 1 << " " << v[1] + 1 << " " << v[2] << endl;
    }
    else
        cout << "Need better measurements.\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ":\n";
        cp();
        cout << endl;
    }
    return 0;
}
