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
const int inf = 1e5 + 5;

struct node
{
    int v, len, cost;
    node() {}
    node(int v, int l, int t): v(v), len(l), cost(t) {}
    const bool operator<(const node &m) const
    {
        return len > m.len;
    }
};

void cp()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<node>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int s, d, l, t;
        cin >> s >> d >> l >> t;
        adj[s].pb(node(d, l, t));
    }
    // Dijkstra but only use edges such that total cost < k
    // I cannot store distances in array either because i want to minimise cost
    // so i should return as soon as i hit node n
    priority_queue<node> pq;
    pq.push(node(1, 0, 0));
    int ans = -1;
    while(!pq.empty())
    {
        node u_node = pq.top();
        pq.pop();
        int cost = u_node.cost;
        int len = u_node.len;
        int u = u_node.v;

        if(u == n)
        {
            // must be the shortest length and cost <= k
            ans = len;
            break;
        }

        for(node v_node : adj[u])
        {
            // see if cost is < k
            if(v_node.cost + cost <= k)
            {
                // now we can push the path length to be handled by pq
                pq.push(node(v_node.v, len + v_node.len, cost + v_node.cost));
            }
        }
    }

    cout << ans << endl;
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