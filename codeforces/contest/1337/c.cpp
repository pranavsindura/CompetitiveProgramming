#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define clrf(x) memset(x, false, sizeof(x))
#define clrz(x) memset(x, 0, sizeof(x))
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

vector<vector<int>> adj(2 * 100005);
bool vis[2 * 100005];
int depth[2 * 100005], subtree[2 * 100005];
ll ans = 0;

int dfs(int u, int d)
{
    vis[u] = true;
    int st = 0;
    for(int x : adj[u])
    {
        if(!vis[x])
        {
            st += dfs(x, d + 1);
        }
    }
    depth[u] = d;
    subtree[u] = st;
    return st+1;
}

void cp()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {

        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    vector<int> v;
    for(int i = 0; i < n; i++)
        v.pb(i + 1);
    sort(all(v), [&](int a, int b)
    {
        return depth[a] - subtree[a] > depth[b] - subtree[b];
    });
    for(int i = 0; i < k; i++)
    {
        ans += depth[v[i]] - subtree[v[i]];
    }
    cout << ans;
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