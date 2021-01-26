#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
vector<int> one, two;
int colour[MAXN];
bool vis[MAXN];
bool bfs(int st, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(st);
    colour[st] = 1;
    one.pb(st);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int x : adj[u])
        {
            if(colour[x] == -1)
            {
                colour[x] = (colour[u] == 1 ? 2 : 1);
                if(colour[x] == 1)
                    one.pb(x);
                else
                    two.pb(x);
                q.push(x);
            }
            else if(colour[x] == colour[u])
            {
                //cycle
                return false;
            }
        }
    }
    return true;
}

void cp()
{
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
    fill(colour, colour + MAXN, -1);
    bool ok = true;
    for(int i = 1; i <= n; i++)
    {
        if(colour[i] == -1)
        {
            if(!bfs(i, adj))
                ok = false;
        }
    }
    if(ok)
    {
        cout << sz(one) << endl;
        for(int x : one)
            cout << x << " ";
        cout << endl;
        cout << sz(two) << endl;
        for(int x : two)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << -1;
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