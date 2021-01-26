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
bool vis[105];
int colour[105];
vector<int> ans_arr;
void dfs(int u, int n, vector<vector<int>> &adj)
{
    if(u > n)
    {
        vector<int> temp;
        for(int i = 1; i <= n; i++)
        {

            if(colour[i] == 1)
            {
                temp.pb(i);
            }

        }
        if(sz(temp) > sz(ans_arr))
        {
            ans_arr = temp;
        }
        return;
    }
    vis[u] = true;
    bool found_black = false;
    for(int x : adj[u])
    {
        if(vis[x] && colour[x] == 1)
            found_black = true;
    }
    if(!found_black)
    {
        colour[u] = 1;
        dfs(u + 1, n, adj);
    }
    colour[u] = 0;
    dfs(u + 1, n, adj);
    vis[u] = false;
}

void cp()
{
    memset(vis, false, sizeof(vis));
    memset(colour, 0, sizeof(colour));
    ans_arr.clear();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, n, adj);
    cout << sz(ans_arr);
    nl;
    for(int i=0;i<sz(ans_arr);i++){
        if(i)
            cout<< " " << ans_arr[i];
        else
            cout<<ans_arr[i];
    }
    nl;
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