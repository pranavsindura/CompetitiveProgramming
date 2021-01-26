/*
	Strongly connected components using Kosaraju's algorithm
	Directed graph

	For undirected it is simply DFS to find connected components
*/
/*
	Approach -

	Using DFS can find the Topological sorting order which tells us what nodes
	Appear in the subtree or are in a separate forest.

	We now know what nodes are connected to node V
	To find strongly connected components we also need to know which nodes POINT BACK TO V

	For that we can reverse the graph u -> v => u <- v

	And process the nodes in the reverse topological order,
	Because last node is connected to some before it, we need to find how many are connected back to it.
*/

void dfs(int u, vector<int> adj[], vector<bool> &vis, vector<int> &topsort)
{
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj, vis, topsort);
    topsort.push_back(u);
}

int kosaraju(int V, vector<int> adj[])
{
    int sz = 0;
    vector<int> topsort;
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            dfs(i, adj, vis, topsort);
    }
    vector<int> rev_adj[V];
    for(int i = 0; i < V; i++)
    {
        for(int x : adj[i])
            rev_adj[x].push_back(i);
    }
    fill(begin(vis), end(vis), false);
    while(!topsort.empty())
    {
        int src = topsort.back();
        topsort.pop_back();
        vector<int> scc;
        if(!vis[src])
            dfs(src, rev_adj, vis, scc), sz++;
    }
    return sz;
}