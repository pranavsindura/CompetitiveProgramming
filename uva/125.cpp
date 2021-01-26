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

void cp()
{
    int n;
    int test = 0;
    while(cin >> n)
    {
        vector<pi> intersections;
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            intersections.pb({u, v});
            mx = max({mx, u, v});
        }
        mx++;
        ll adj[mx][mx];
        clr(adj, 0);

        for(auto x : intersections)
            adj[x.ff][x.ss]++;

        // Finding Number of Paths
        for(int k = 0; k < mx; k++)
            for(int i = 0; i < mx; i++)
                for(int j = 0; j < mx; j++)
                    adj[i][j] += adj[i][k] * adj[k][j];

        // Handling Cycles/Infinite paths
        for(int k = 0; k < mx; k++)
            for(int i = 0; i < mx; i++)
                for(int j = 0; j < mx; j++)
                    if(adj[i][k] && adj[k][j] && (adj[k][k] > 0 || adj[k][k] == -1))
                        adj[i][j] = -1;
                   
        cout << "matrix for city " << test++ << endl;
        for(int i = 0; i < mx; i++)
            for(int j = 0; j < mx; j++)
                cout << adj[i][j] << " \n"[j == mx - 1];

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