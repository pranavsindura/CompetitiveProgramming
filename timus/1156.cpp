#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

vector<vector<int>> adj, black, white;
vector<int> colour, temp;
bool ok;

void bipart(int start, int u, int par)
{
    temp[u] = colour[u] = temp[par] % 2 + 1;
    if(colour[u] == 1)
        black[start].pb(u);
    else
        white[start].pb(u);
    for(int v : adj[u])
        if(!temp[v])
            bipart(start, v, u);
        else if(temp[v] == temp[u])
            ok = false;
}

int n, m;
int dp[105][105];
vector<int> up, down, picked;
bool solve(int i, int sum)
{
    if(i == sz(picked))
        return sum == n;
    int &ret = dp[i][sum];
    if(~ret)
        return ret;
    bool ans = false;
    ans |= solve(i + 1, sum + sz(black[picked[i]]));
    ans |= solve(i + 1, sum + sz(white[picked[i]]));
    return ret = ans;
}


void trace(int i, int sum)
{
    if(i == sz(picked))
        return;
    if(solve(i + 1, sum + sz(black[picked[i]])))
    {
        for(int x : black[picked[i]])
            up.pb(x);
        for(int x : white[picked[i]])
            down.pb(x);
        trace(i + 1, sum + sz(black[picked[i]]));
    }
    else
    {
        for(int x : white[picked[i]])
            up.pb(x);
        for(int x : black[picked[i]])
            down.pb(x);
        trace(i + 1, sum + sz(white[picked[i]]));
    }
}

void cp()
{
    cin >> n >> m;
    adj.resize(2 * n + 1);
    black.resize(2 * n + 1);
    white.resize(2 * n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    ok = true;
    colour.assign(2 * n + 1, 0);
    temp.assign(2 * n + 1, 0);

    for(int i = 1; i <= 2 * n; i++)
        if(!colour[i])
            temp.assign(2 * n + 1, 0), bipart(i, i, 0), picked.pb(i);

    clr(dp, -1);
    ok &= solve(0, 0);

    if(!ok)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    trace(0, 0);
    for(int x : up)
        cout << x << " ";
    cout << endl;
    for(int x : down)
        cout << x << " ";
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

