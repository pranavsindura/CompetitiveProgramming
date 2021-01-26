/*
	Find Total edge weight of MST for the given graph
*/
/*
	Approach 1 - Kruskal MST using DSU
*/
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
struct edge
{
    int u, v, cost;
    edge() {}
    edge(int u, int v, int cost): u(u), v(v), cost(cost) {}
    bool operator<(const edge &e)
    {
        return cost < e.cost;
    }
};

int parent[1005];
void make_set()
{
    iota(parent, parent + 1005, 0);
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(a != b)
    {
        parent[b] = a;
        return true;
    }
    else
        return false;
}

int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    vector<edge> edges;
    make_set();
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(graph[i][j] != INT_MAX)
                edges.push_back(edge(i, j, graph[i][j]));

    sort(begin(edges), end(edges));

    int total = 0;
    for(int i = 0; i < (int)edges.size(); i++)
    {
        if(union_set(edges[i].u, edges[i].v))
            total += edges[i].cost;
    }
    return total;
}
