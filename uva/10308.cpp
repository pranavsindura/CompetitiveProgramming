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
const int MAXN = 1e4 + 5;
vector<vector<pi>> adj(MAXN);
vector<bool> vis(MAXN);
int main()
{
    FASTIO;
    int u, v, l;
    string s;
    while(getline(cin, s) && ln(s))
    {
        stringstream ss(s);
        ss >> u >> v >> l;
        adj[u].pb({v, l});
        adj[v].pb({u, l});
        string s;
        while(getline(cin, s) && ln(s))
        {
            stringstream ss(s);
            ss >> u >> v >> l;
            adj[u].pb({v, l});
            adj[v].pb({u, l});
        }
        queue<pair<int, ll>> q;
        q.push({1, 0});
        pair<int, ll> farthest = q.front();
        while(!q.empty())
        {
            pair<int, ll> u_node = q.front();
            q.pop();
            int u = u_node.ff;
            ll len = u_node.ss;

            if(len > farthest.ss)
                farthest = u_node;

            vis[u] = true;
            for(pi v : adj[u])
                if(!vis[v.ff])
                    q.push({v.ff, len + v.ss}), vis[v.ff] = true;
        }
        fill(all(vis), false);
        farthest.ss = 0;
        q.push(farthest);
        while(!q.empty())
        {
            pair<int, ll> u_node = q.front();
            q.pop();
            int u = u_node.ff;
            ll len = u_node.ss;

            if(len > farthest.ss)
                farthest = u_node;

            vis[u] = true;
            for(pi v : adj[u])
                if(!vis[v.ff])
                    q.push({v.ff, len + v.ss}), vis[v.ff] = true;
        }
        cout << farthest.ss << endl;

        for(auto &v : adj)
            v.clear();
        fill(all(vis), false);
    }
    return 0;
}