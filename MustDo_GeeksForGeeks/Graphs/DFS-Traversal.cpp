/*
	Print DFS Traversal of Graph
*/
/*
	Approach 1 - Basic Recursive DFS, store the DFS tour
*/
void dfs_help(int u, vector<int> g[], vector<bool> &vis, vector<int> &tour)
{
    vis[u] = true;
    tour.push_back(u);
    for(int v : g[u])
    {
        if(!vis[v])
            dfs_help(v, g, vis, tour);
    }
}
vector<int> dfs(vector<int> g[], int N)
{
    vector<bool> vis(N + 1, false);
    vector<int> tour;
    dfs_help(0, g, vis, tour);
    return tour;
}