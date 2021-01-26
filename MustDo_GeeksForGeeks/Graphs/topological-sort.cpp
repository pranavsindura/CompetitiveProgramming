/*
	Topological Sort of a graph
*/
/*
	Approach - DFS
	Push node in an array after done visiting its children
*/
void dfs(int u, vector<int> &tour, vector<bool> &vis, vector<int> adj[])
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v, tour, vis, adj);
    }
    tour.push_back(u);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> vis(V, false);
    vector<int> tour;
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            dfs(i, tour, vis, adj);
    }
    reverse(begin(tour), end(tour));
    return tour;
}
