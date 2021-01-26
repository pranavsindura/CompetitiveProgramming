/*
    Dijkstra Shortest Path Algorithm O(ElogV)

    Greedy, Assumes all weights are non negative
    If the weights are 0/1, then use 0/1 BFS, easier implementation

    Take the min dist node and relax its neighbours
    While relaxing, we can also store the path

    Single Source Shortest Path

        2nd Shortest path

        Similar to 2nd MST, hold the edges of the shortest path and find other shortest paths

        Kth Shortest Path
        - Non Cyclic Graphs (DAG)
            - Yen's Algorithm
        - Cyclic Graphs
            - Eppstein's Algorithm (http://www.isi.edu/natural-language/people/epp-cs562.pdf)
            - Brute Force Enumeration with Dijkstra (UVA 10740)
                Visit each node atmost K times
                Bound using dist[vis_cnt[U]][U] < current_dist

    All Pair Shortest Path / N-Dijkstra
 
    Dijkstra can be easily extended to All pair shortest path
    Just perform Dijkstra from every node
    (CF 1433G)
    O(V * ElogV)

    => O(V^3 logV) for dense, which is worse than Floyd Warshall
*/

// Implementation Idea, Most are problem based, no template

int dijkstra(int S, int T, vector<vector<int>> &adj, int n)
{
    vector<int> dist(n, inf);
    // vector<int> prev(n, -1);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    while(!pq.empty())
    {
        pair<int, int> u_node = pq.top();
        int d = u_node.first;
        int u = u_node.second;
        pq.pop();
        if(d > dist[u]) continue; // Bounding Condition
        for(int v : adj[u])
        {
            if(dist[v] > dist[u] + cost[u -> v]) // Relaxation
            {
                dist[v] = dist[u] + cost[u -> v];
                pq.push({dist[v], v});
                // can store path of where you came frome, using prev[v] = u
                // later on reconstruct going back from T to S
            }
        }
    }
    /*
        vector<int> path;
        int u = T;
        while(~prev[u])
            path.push_back(u), u = prev[u];
        path.push_back(S);
        reverse(all(path));
    */
    return dist[T];
}