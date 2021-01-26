/*
	Circle of Strings

	Check if you can form a circle of strings,
	such that last character of first string and
	first character of second string are same for every
	adjacent string in the circle;
*/

/*
	Approach 1-
	Can convert it into a Graph problem by making an Adjacency List of
	What strings can be attached at the end of the current string.

	After that we need to find a Cycle of Length N in the directed Graph

	To Find a Cycle we should first find a path of length N-1 and then see if the last node can
	be connected back to the Start Node

    Kind of backtracking so mark visited before visitng children, after that mark unvisited

	Approach 2-

	===================EULERIAN CIRCUIT========================

	Eulerian Path is a path in graph that visits every edge exactly once.
	Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

	A directed graph has an eulerian cycle if following conditions are true (Source: Wiki)
		1) All vertices with nonzero degree belong to a single strongly connected component.
			Find the SCC using Kosaraju's DFS Algorithm
		2) In degree is equal to the out degree for every vertex.
	
*/

// Find cycle of length K
bool dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, int left, int start)
{
    vis[u] = true;
    bool me = false;
    if(left)
    {
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                bool child = dfs(v, vis, adj, left - 1, start);
                me = child || me;
            }
        }
    }
    else
    {
        for(int v : adj[u])
        {
            if(v == start)
            {
                // ok
                me = true;
            }
        }
    }
    vis[u] = false;
    return me;
}

void cp()
{
    int n;
    cin >> n;
    int cnt_ff[26] = {0};
    int cnt_ss[26] = {0};
    vector<string> arr;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.pb(s);
    }
    bool ok = false;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
    {
        // can j be attached at the end of i
        for(int j = 0; j < n; j++)
        {
            if(arr[j][0] == arr[i].back())
            {
                //yes
                adj[i].pb(j);
            }
        }
    }
    vector<bool> vis(n, false);
    ok = dfs(0, vis, adj, n - 1, 0);
    cout << ok << endl;
}
