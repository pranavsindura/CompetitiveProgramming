/*
	Detect Cycle in Undirected Graph
*/

/*
	Approach -
	DFS
	Check if child has been visited and if it is in recursion stack
	Since edges are bi-directional also need to check that child is not parent
*/

bool dfs(int u, int par, vector<bool> &vis, vector<bool> &in_stack, vector<int> g[])
{
    vis[u] = true;
    in_stack[u] = true;
    bool cycle = false;
    for(int v : g[u])
    {
        if(v == par)
            continue;
        if(!vis[v])
        {
            bool child = dfs(v, u, vis, in_stack, g);
            cycle = cycle || child;
        }
        else if(in_stack[v])
        {
            cycle = true;
        }
    }
    in_stack[u] = false;
    return cycle;
}

bool isCyclic(vector<int> g[], int V)
{
    vector<bool> vis(V, false), in_stack(V, false);
    bool cycle = false;
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            bool cycle_here = dfs(i, -1, vis, in_stack, g);
            if(cycle_here)
                cycle = true;
        }
    }
    return cycle;
}