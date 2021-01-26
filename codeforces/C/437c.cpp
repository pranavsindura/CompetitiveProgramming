#include<bits/stdc++.h>
#define ll 			long long int
#define pi 			pair<int,int>
#define eps 		0.000000001
#define all(x) 		x.begin(), x.end()
#define allr(x) 	x.rbegin(), x.rend()
#define sz(x) 		((int)x.size())
#define ln(x) 		((int)x.length())
#define mp 			make_pair
#define pb 			push_back
#define ff 			first
#define ss 			second
#define endl 		'\n'
#define dbg(x) 		cout<<#x<<" "<<x<<endl
#define clr(x,v) 	memset(x, v, sizeof(x))
#define FASTIO 		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    vector<int> cost(n + 1, 0);
    for(int i = 0; i < n; i++)
        cin >> cost[i + 1];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int done = 0;
    ll total = 0;
    // break n-1 connections in total
    while(done < n - 1)
    {
        int node = 0;
        ll mx = 0;
        // remove node with maximum cost first so that it does not get added later on
        for(int i = 1; i <= n; i++)
        {
            if(adj[i].empty())
                continue;
            if(cost[i] * 1LL > mx)
                mx = cost[i], node = i;
        }
        // add up the cost incured by removing the node
        ll removing_cost = 0;
        for(int x : adj[node])
            removing_cost += cost[x];
        total += removing_cost;
        // break all connections that go to the node and from the node
        for(int x : adj[node])
            adj[x].erase(node);
        adj[node].clear();

        done++;
    }
    cout << total;
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