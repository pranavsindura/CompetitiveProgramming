/*
	MAX FLOW - MIN CUT
	Directed graph
	Maximum flow from Source node to Sink node
	maximum amount of flow that the network would allow to flow from source to sink
	minimum cost edges we need to cut so that there is no flow from source to sink
	These are equivalent problems

	Ford Fulkerson Algorithm O(E * F) where F is the max flow edge in the network
	Repeat until no more paths
	1. 	Find a path from source to sink
		The flow on this path(current flow) is the min of all edge flows
		Add it to the total flow
	2.  Remove the current flow from the edges of the path found
		Add the current flow in reverse direction

	How to find path? Anything - DFS/BFS/Dijkstra
	If you use dijkstra use the implementation that can maximise the min flow from source to sink

	Edmonds-Karp variant
	Use BFS as the path finding routine
	O(V * E^2)

	Augmentations
	Refer UVA 10330
	1. Vertex Splitting / Flow on Nodes
		We can split the node it self into 2 nodes and add a pseudo edge with the given flow
		Giving us a 2N node graph

		Easy way to implement is to keep track of IN(v) and OUT(v) for each node
		IN(v) is the node with all incoming edges to v, OUT(v) is the node with all outgoing edges from v
		IN(v) = v, OUT(v) = v + n

		Keep of track of flows from x->y separately

		Adding edge u->v will become adding edge from OUT(u) to IN(v)
		Update the flow from OUT(u) to IN(v)

		Adding capacity on node will become adding edge from IN(u) to OUT(u)
		Update the flow from IN(u) to OUT(u)

	2. Multi source and Multi sink
		Define a SUPER source and SUPER SINK
		Join SUPER source with all source with cap = oo
		Join all sinks with SUPER sink with cap = oo

		In case there are restrictions on sources/sink themselves (cap on nodes)
		we can change the cap of SUPER source -> source/sink -> SUPER sink to handle that
		instead of vertex splitting

	Applications

	1. Maximum edge disjoint paths
		Maximum number of paths from source to sink such that no edge is shared
		Consider each edge to have flow of 1
		Now this is a max flow problem

	2. Maximum independent path / Maximum vertex disjoint path
		Maximum number of path in graph from source to sink such that no vertex is shared
		except source and sink
		This is same as above with capacity of 1 on nodes as well
		Use vertex splitting

	3. Maximum Bipartite Matching on Bipartite graphs
		Can be reduced to max flow in a network

	4. Minimum edges to be removed to disconnect a graph
		Min cut with 1 edge flow each
		Pick two vertices, find max flow from u to v
		minimise the max flow
		Here slight optimisation is that we can fix one vertex and consider other vertices

	5. Minimum nodes to be removed to disconnect a graph
		Vertex splitting
		Min cut with 1 edge flow each
		Pick one vertex split into two
		minimise the max flow

	6. Minimum Path coverage in DAG / Vertex Disjoint Path Cover in DAG
		Minimum paths needed to cover all vertices V, in DAG.
		Paths cannot share edges, each vertex must belong to exactly one path
		based on KONIG's THEOREM

		First we need to reduce it to a maximum matching problem
		Split each vertex into IN and OUT, edges go from OUT(u) to IN(v)
		Consider all OUTs as the left half of a matching
		Consider all INs as the right half of a matching
		Now find the maximum bipartite matching = M
		The minimum paths = N - M

		This is because all nodes on left half which are unmatched have no outgoing edge
		thus must be the end points of a path
		N - M enumerates those end points which in turn are equal to the number of paths

	7. Minimum Edge cover
		Minimum edges to cover all vertices
		This is not same as Minimum Path coverage
		First find the maximum bipartite matching
		Then greedily extend it to cover all nodes

	8. Maximum independent set
		An independent set is a set of vertices such that no two are adjacent
		In a bipartite graph with no isolated vertices, the number of vertices in a maximum independent set
		equals the number of edges in a minimum edge covering; this is Kőnig's theorem.

	Finding the Min-cut edges

		After finding the residual graph in which no more augmenting paths are present
		All the min cut edges are those who cannot support any more flow
		But there can be many such edges
		We use the idea that the min cut edge has one vertex connected to S and other to T
		because there is no more flow through it

		So we flood fill from S, and find all nodes reachable from S having flow > 0
		All remaining vertices are reachable from T
		Then we can loop on each edge and find the edges with one vertex in S and other in T
		Those edges are the min-cut edges
*/

// Ford-Fulkerson Algorithm
// Edmonds-Karp variant
// flow can be map<int, int>[]
int N; // Total number of nodes, < MAXN
int flow[MAXN][MAXN]; // Dont forget to clear the flow in case of multiple TC
int vis[MAXN], path[MAXN];

int find_path(int S, int T)
{
    fill(vis, vis + N, 0);
    queue<pi> q;
    q.push({S, inf});
    path[S] = -1;
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff, mx = node.ss;
        vis[u] = 1;
        if(u == T) return mx;
        for(int v = 0; v < N; v++)
            if(!vis[v] && flow[u][v] > 0)
                vis[v] = 1, path[v] = u, q.push({v, min(mx, flow[u][v])});
        /*
        for(auto v : flow[u])
        if(!vis[v.ff] && v.ss > 0)
            vis[v.ff] = 1, path[v.ff] = u, q.push({v.ff, min(mx, v.ss)});
        */
    }
    return 0;
}

int max_flow(int S, int T)
{
    int ans = 0, d, u;
    while(true)
    {
        d = find_path(S, T);
        if(d == 0) break;
        ans += d;
        u = T;
        while(~path[u])
            flow[path[u]][u] -= d, flow[u][path[u]] += d, u = path[u];
    }
    return ans;
}

// Vertex Splitting - Graph Building
// N = 2 * n
#define in(v) v
#define out(v) v + n

// Node capacity? u, cap
flow[in(u)][out(u)] = cap;

// Edge capacity? u->v, cap
flow[out(u)][in(v)] = cap;

// Multi Source / Multi Sink
// N = 2*n+2
int S = 2 * n, T = 2 * n + 1;
// for all sources u
flow[S][in(u)] = cap;
// for all sinks u
flow[out(u)][T] = cap;