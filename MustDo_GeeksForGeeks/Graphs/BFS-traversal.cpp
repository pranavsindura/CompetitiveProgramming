/*
	Print BFS Traversal of Graph
*/
/*
	Approach 1 - Basic Iterative BFS, store the BFS tour
*/
vector <int> bfs(vector<int> g[], int N)
{

    vector<int> tour;
    queue<int> q;
    q.push(0);
    vector<bool> vis(N + 1, false);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        tour.push_back(u);
        for(int v : g[u])
        {
            if(!vis[v])
                q.push(v), vis[v] = true;
        }
    }
    return tour;
}