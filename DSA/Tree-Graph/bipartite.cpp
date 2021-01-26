/*
	BIPARTITENESS

	A graph is called bipartite if we can break the graph nodes into 2 disjoint sets
	such that if there is an edge from u -> v, then u and v belong to different sets

	CHECK BIPARTITENESS

	Colour vertices red and blue alternately
	Start from root, colour it red
	Colour all its children blue
	Then their children red and so on
	If some node is already visited, then its colour must be different from the current colour
	If you can find such a colouring that satisfies this, then the graph is bipartite

	A TREE is Bipartite
	A KNIGHT MOVEMENT GRAPH is Bipartite - If you stand on black you can only go to white squares
	DAGs can be represented as collections of Bipartite graphs
	A King's movement graph or 4-Connection Grid is Bipartite

	MAXIMUM BIPARTITE MATCHING
		Refer UVA 10080
		The graph might not be bipartite, that is HARD
		We consider graph to be bipartite here,
		We can choose some edges and create a matching such that if the edge u -> v is picked then
		u and v are in different set (a bipartite matching)
		All the nodes (in the set) and edges are considered matched
		A maximum matching is one that matches the maximum edges

		For example, consider assigning tasks to people
		Each person can do some of the given tasks
		we want maximum tasks to be completed
		this calls for a maximum matching

		A matching is called a perfect matching if all nodes are matched

		How to find?
			1. 	CONSIDER AS MAX FLOW PROBLEM
				Flow of each edge is 1
				Add a super source, connect to all sources(process/people)
				Add a super sink, connect to all sinks(resources/tasks)
				Flow from super source/sink is oo, if some restriction we can handle that

				Now find the maximum flow in this network

			2. 	KUHN'S ALGORITHM 
				In case of standard bipartite matching we can add optimizations (memory and a little speed)
				considering the nature of the problem
				https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html

				Here we try all nodes in the left half and try to one by one find a matching with
				them if possible at the end we will end up with a maximum matching
				We can add heuristics to speed things up

				O(N * M)
				Worst case O(N^3) but not exactly
				O(N1^2 * N2) N1 nodes in left half, N2 nodes in right half
				Swap N1 and N2 if N1 > N2, improves running time


		Matching on Grid
			4-Way connections
			Think in terms of Chess Coloring
			Connect Super source to black nodes
			Connect Super sink to white nodes
			and join black nodes with one way to white nodes

			Rows and Cols are also two groups we can break into

			Cell(i, j) can be considered as an edge between Row i and Col j

	KONIG's THEOREM
	FOR BIPARTITE GRAPHS
	Minimum vertex cover = Maximum matching
	Maximum indepedent set = Minimum edge cover
*/

// KUHN's ALGORITHM

vector<int> mt;
vector<bool> vis, picked;

bool kuhn(int u, vector<vector<int>> &adj)
{
    if(vis[u]) return false;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(mt[v] == -1 || kuhn(mt[v], adj)) // can find an augmenting path?
        {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void cp()
{
    // Build graph
    // Left half has n nodes, right half has m nodes

    mt.assign(m, -1); // which node in left half is the i-th right half node matched to?
    picked.assign(n, false); // greedy picking

    // Simple heuristic to speed things up, find any greedy matching
    for(int u = 0; u < n; u++)
    {
        for(int x : adj[u])
        {
            if(mt[x] == -1) // match it
            {
                mt[x] = u;
                picked[u] = 1;
                break;
            }
        }
    }
    // Find augmenting path for each node
    for(int u = 0; u < n; u++)
    {
        if(picked[u]) continue;
        vis.assign(n, false);
        kuhn(u, adj);
    }
    // for all v such that mt[v] != -1, mt[v] and v belong to the maximum matching
    int matched = 0;
    for(int i = 0; i < m; i++)
        if(mt[i] != -1)
            matched++;
}