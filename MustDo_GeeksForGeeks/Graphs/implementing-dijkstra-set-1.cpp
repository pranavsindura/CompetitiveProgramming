/*
	Implement Dijkstra
	Given adjacency matrix of weights of edges
	if G[i][j] == 0, edge does not exist
*/
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
	// Min Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    pq.push({0, src});
    while(!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();

        int u = node.second;
        int d = node.first;

        if(dist[u] < d)
            continue;

        for(int v = 0; v < V; v++)
        {
            if(u == v)
                continue;
            // Relaxing Node v
            if(dist[v] > dist[u] + g[u][v] && g[u][v])
            {
                dist[v] = dist[u] + g[u][v];
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}