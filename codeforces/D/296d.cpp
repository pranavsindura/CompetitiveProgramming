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

const ll inf = 1e12;

ll arr[505][505], adj[505][505];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<int> removed_nodes(n);
    for(int &x : removed_nodes)
        cin >> x;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = (i == j ? 0 : inf);

    vector<ll> result;

    vector<int> exist;

    while(!removed_nodes.empty())
    {
        int x = removed_nodes.back();
        x--;
        removed_nodes.pop_back();
        exist.pb(x);
        // add edges
        for(int y : exist)
            adj[y][x] = arr[y][x], adj[x][y] = arr[x][y];

        // optimise (u, x)
        for(int i : exist)
            for(int j : exist)
                if(adj[i][j] < inf && adj[j][x] < inf)
                    adj[i][x] = min(adj[i][x], adj[i][j] + adj[j][x]);
        // optimise (x, u)
        for(int i : exist)
            for(int j : exist)
                if(adj[x][j] < inf && adj[j][i] < inf)
                    adj[x][i] = min(adj[x][i], adj[x][j] + adj[j][i]);

        // optimise (u, v)
        for(int i : exist)
            for(int j : exist)
                if(adj[i][x] < inf && adj[x][j] < inf)
                    adj[i][j] = min(adj[i][j], adj[i][x] + adj[x][j]);
        ll ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(adj[i][j] < inf)
                    ans += adj[i][j];

        result.pb(ans);
    }

    while(!result.empty())
        cout << result.back() << " ", result.pop_back();
    cout << endl;
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