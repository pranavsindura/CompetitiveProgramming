/*
    STRONGLY CONNECTED COMPONENTS

    Directed Graph
    A SSC is a set of nodes such that any node is reachable from any other node
    In a SCC, all nodes are in a cycle
    Conversly a cycle is a SCC
    We can find cycle in a graph using this method

    Algorithms

    1. Brute DFS or Floyd Warshall
        DFS from each node, find the nodes we can visit
        O(V * (V+E)) => O(V^3) for dense graphs

        We can do the same as a Transitivity Closure with Floyd Warshall
        O(V^3)

    2. Kosaraju's Algorithm
        2 DFS
        First we find Topological Order of the graph G
        A -> B -> C, A is higher than B, B is higher than C
        Then we make the transpose of the graph G -> G'
        Then we DFS in G' from the nodes in the topsort order
        All the nodes reachable from each node u form a SCC

    3. Tarjan's Algorithm
        1 DFS
        Also can compute Articulation points and Bridges

        We know how to check cycles, using instack[] and vis[]
        We will extend that idea one step further

        We will keep track of the Visiting Time of a node
        And the Lowest Link number of the node
        The Lowest Link of a node = Smallest lowest link in its subtree (including it)
        It is the highest ancestor reachable from the current DFS flow

        The nodes with Visiting time == Lowest Link # are the start points of the SCC
        Other nodes have Low link # < Visiting time

        The nodes we consider for minimization must be either unvisited or must be in
        the current stack (cycle)

    CONNECTED COMPONENT GRAPH
        Graph of all the connected components
        Take initial Graph
        Take an edge u-v
        if u and v dont belong to same SCC join the edge between the
        component[u] and component[v]

        Uses?
        1. Min edges to add to graph to make it a whole cycle
            Find component graphs
            Count number of sources and sinks in the DAG
            if there is only 1 component -> 0
            else -> max(src, snk) is the answer
            If a node have 0 indegree it has to be made a sink
            If a node have 0 outdegree it has to be made a source

        2. Faster transitive closure / Optimisation
            Find the connected comp graph
            Find its closure
            Find the graph's closure

        SINKS
            U is sink if, all nodes V that are reachable from U must be able to reach V.
            This means that in the connected component graph, the components which have no outgoing
            edges are Sinks.
        SOURCES
            U is source if, all nodes V that can reach U, U can reach them. Opposite of a sink.
            This means that in the connected component graph, the components which have no incoming
            edges are Sources.
*/




// Tarjan's Algorithm
int TIMER;
vector<int> entry, low_link, comp;
vector<bool> instack, is_sink;
stack<int> st;
vector<vector<int>> scc;
void dfs(int u, vector<vector<int>> &adj)
{
    entry[u] = low_link[u] = TIMER++;
    instack[u] = 1;
    st.push(u);

    for(int v : adj[u])
        if(entry[v] == -1)
            dfs(v, adj), low_link[u] = min(low_link[u], low_link[v]);
        else if(instack[v])
            low_link[u] = min(low_link[u], entry[v]);

    if(entry[u] == low_link[u])
    {
        scc.pb(vector<int>());
        int x = -1;
        while(x != u)
        {
            x = st.top();
            st.pop();
            instack[x] = 0;
            scc.back().pb(x);
            comp[x] = sz(scc) - 1;
        }
    }
}

void tarjan(int n, vector<vector<int>> &adj)
{
    // RESET
    int N = n + 1;
    TIMER = 0;
    entry.assign(N, -1), low_link.assign(N, -1), comp.assign(N, -1);
    instack.assign(N, false);
    while(!st.empty()) st.pop();
    scc.clear();

    for(int i = 0; i < n; i++)
        if(entry[i] == -1)
            dfs(i, adj);
}




// Kosaraju's Algorithm
vector<int> comp;
vector<bool> vis;
vector<vector<int>> scc;
void topsort(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, top);
    top.pb(u);
}
void dfs(int u, vector<vector<int>> &adj)
{
    vis[u] = 1;
    scc.back().pb(u);
    comp[u] = sz(scc) - 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj);
}
void kosaraju(int n, vector<vector<int>> &adj, vector<vector<int>> &rev_adj)
{
    comp.assign(n, -1);
    vis.assign(n, false);
    scc.clear();
    vector<int> top;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            topsort(i, adj, top);
    vis.assign(n, false);
    while(!top.empty())
    {
        int u = top.back();
        top.pop_back();
        if(vis[u]) continue;
        scc.pb(vector<int>());
        dfs(u, rev_adj);
    }
}




// Connected Component graph
vector<vector<int>> component_graph(vector<vector<int>> &adj)
{
    // Find SCC
    vector<vector<int>> G(sz(scc));
    for(int u = 0; u < sz(adj); u++)
        for(int v : adj[u])
            if(comp[u] != comp[v])
                G[comp[u]].pb(comp[v]);
    /*
        is_sink[comp[u]] = false;
        is_source[comp[v]] = false;

        if(in[comp[v]] == 0) src--;
        in[comp[v]]++;

        if(out[comp[u]] == 0) snk--;
        out[comp[u]]++;
    */
    return G;
}