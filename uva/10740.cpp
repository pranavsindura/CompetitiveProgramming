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
using pi = pair<ll, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1e16;
const int MAXN = 1e5 + 5;

/*
	Kth shortest path
	Graph has cycles

	Handle repetitions, each node must be visited atmost k times
	dont visit it again and again
*/


void cp()
{
    int n, m;
    while(cin >> n >> m && n + m)
    {
        int X, Y, K;
        cin >> X >> Y >> K;
        X--, Y--;

        vector<vector<pi>> adj(n);

        for(int i = 0, u, v, w; i < m; i++)
            cin >> u >> v >> w, u--, v--, adj[u].pb({w, v});

        vector<ll> ans;
        vector<int> vis(n, 0);

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, X});
        while(!pq.empty() && sz(ans) < K)
        {
            ll d = pq.top().ff;
            int u = pq.top().ss;
            pq.pop();
            vis[u]++;
            if(u == Y) ans.push_back(d);
            if(vis[u] > K) continue;
            for(auto &e : adj[u])
            {
                int w = e.ff;
                int v = e.ss;
                pq.push({d + w, v});
            }
        }
        if(sz(ans) < K) cout << -1 << endl;
        else cout << *ans.rbegin() << endl;
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

