/*
	Detect Cycle in a Directed Graph
*/
/*
	Approach -
	DFS
	Check if child has been visited before and if it is in Recursion Stack
*/
bool dfs(int u, vector<bool> &vis, vector<bool> &in_stack, vector<int> g[])
{
    vis[u] = true;
    in_stack[u] = true;
    bool cycle = false;
    for(int v : g[u])
    {
        if(!vis[v])
        {
            bool child = dfs(v, vis, in_stack, g);
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

bool isCyclic(int V, vector<int> g[])
{
    vector<bool> vis(V, false), in_stack(V, false);
    bool cycle = false;
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            bool cycle_here = dfs(i, vis, in_stack, g);
            if(cycle_here)
                cycle = true;
        }
    }
    return cycle;
}