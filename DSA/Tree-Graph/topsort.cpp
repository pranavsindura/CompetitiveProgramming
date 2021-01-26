#include <bits/stdc++.h>
using namespace std;

/*
    Topsort
    Heirarchical order

    Unique topsort?
        Find topsort, if there is edge between every pair of adjacent nodes
        then topsort is unique
*/

void topsort(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, top);
    top.pb(u);
}