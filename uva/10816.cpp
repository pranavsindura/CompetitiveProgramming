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
const double inf = 5e6;
/*
	BS on Temparature find shortest path with dijkstra
*/
int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

struct node
{
    int no;
    double temp, dist;
    node(): no(0), temp(0), dist(0) {}
    node(int no, double temp, double dist): no(no), temp(temp), dist(dist) {}
    const bool operator<(const node &v)const
    {
        return dist > v.dist;
    }
};
double dist[200];
int prv[200];
int n, src, dest;
double dijkstra(vector<vector<node>> &adj, double mx_temp)
{
    fill(dist, dist + n + 1, 5e6);
    dist[src] = 0, prv[src] = src;
    priority_queue<node> pq;
    pq.push(node(src, 0, 0));

    while(!pq.empty())
    {
        node u = pq.top();
        pq.pop();
        if(dist[u.no] < u.dist)
            continue;

        for(node v : adj[u.no])
        {
            if(dcmp(v.temp, mx_temp) <= 0 && dist[v.no] > dist[u.no] + v.dist)
            {
                dist[v.no] = dist[u.no] + v.dist;
                pq.push(node(v.no, 0, dist[v.no]));
                prv[v.no] = u.no;
            }
        }
    }
    return dist[dest];
}

void cp()
{
    int m;
    while(cin >> n >> m)
    {
        vector<vector<node>> adj(n + 1);
        cin >> src >> dest;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            double temp, dist;
            cin >> u >> v >> temp >> dist;
            adj[u].pb(node(v, temp, dist));
            adj[v].pb(node(u, temp, dist));
        }
        double lo = 20, hi = 50;
        for(int itr = 0; itr < 200; itr++)
        {
            double mid = (lo + hi) / 2;

            double d = dijkstra(adj, mid);
            if(dcmp(d, inf) == 0)
                lo = mid;
            else
                hi = mid;
        }

        double d = dijkstra(adj, hi);

        vector<int> path;
        int u = dest;
        while(u != prv[u])
            path.pb(u), u = prv[u];
        path.pb(u);
        reverse(all(path));
        for(int x : path)
        {
            cout << x;
            if(x != path.back())
                cout << " ";
        }
        cout << endl;
        dblout(1);
        cout << d << " " << hi << endl;
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