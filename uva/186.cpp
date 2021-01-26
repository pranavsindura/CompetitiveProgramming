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
const int MAXN = 1e6 + 5;

void cp()
{
    map<string, int> comp;
    vector<tuple<string, string, string, int>> edges;
    string s;
    while(getline(cin, s) && !s.empty())
    {
        string u, v, route;
        int w;
        vector<string> arr;
        for(char x : s)
            if(x == ',')
                arr.pb(route), route = "";
            else
                route += x;
        arr.pb(route);
        u = arr[0], v = arr[1], route = arr[2], w = stoi(arr[3]);
        comp[u], comp[v];
        edges.pb(make_tuple(u, v, route, w));
        edges.pb(make_tuple(v, u, route, w));
    }
    int n = 0;
    for(auto &x : comp)
        x.ss = n++;
    int inf = 1 << 17;
    vector<vector<int>> adj(n, vector<int>(n, inf));
    vector<vector<int>> path(n, vector<int>(n, -1));
    vector<vector<int>> edge_idx(n, vector<int>(n, -1));
    for(int i = 0; i < sz(edges); i++)
    {

        int u = comp[get<0>(edges[i])];
        int v = comp[get<1>(edges[i])];
        int w = get<3>(edges[i]);
        if(w < adj[u][v])
            adj[u][v] = w, edge_idx[u][v] = i;
        adj[u][u] = 0, adj[v][v] = 0;
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(adj[i][k] < inf && adj[k][j] < inf && adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j], path[i][j] = k;

    function<int(int, int)> build_path = [&](int u, int v)
    {
        if(path[u][v] == -1)
        {
            int idx = edge_idx[u][v];
            string a, b, route;
            int w;
            tie(a, b, route, w) = edges[idx];
            cout << setw(20) << left << a << " ";
            cout << setw(20) << left << b << " ";
            cout << setw(10) << left << route << " ";
            cout << setw(5) << right << w << endl;
            return w;
        }
        else
            return build_path(u, path[u][v]) + build_path(path[u][v], v);
    };

    while(getline(cin, s) && !s.empty())
    {
        int u, v;
        string a;
        vector<string> arr;
        for(char x : s)
            if(x == ',')
                arr.pb(a), a = "";
            else
                a += x;
        arr.pb(a);
        cout << endl << endl;
        cout << "From                 To                   Route      Miles" << endl;
        cout << "-------------------- -------------------- ---------- -----" << endl;
        u = comp[arr[0]], v = comp[arr[1]];
        int total = build_path(u, v);
        cout << "                                                     -----" << endl;
        cout << "                                          Total      " << setw(5) << right << total << endl;

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