
// http://www.spoj.com/problems/TREEISO/
// http://www.spoj.com/problems/TRANSL/


// tree center: max 2 centers.
// http://www.spoj.com/problems/PT07Z/


// UVA 10459

vector<int> find_center(vector<vector<int>> &adj)
{
    int n = sz(adj);
    vector<bool> vis(n + 1);
    queue<tuple<int, int, int>> q;

    int mx_d = 0, last = 1;
    q.push(make_tuple(1, 1, 0));
    while(!q.empty())
    {
        int u, par, depth;
        tie(u, par, depth) = q.front();
        q.pop();
        if(depth > mx_d)
            last = u, mx_d = depth;
        for(int v : adj[u])
            if(v != par)
                q.push(make_tuple(v, u, depth + 1));
    }

    vector<int> prev(n + 1);
    mx_d = 0;
    q.push(make_tuple(last, last, 0));
    while(!q.empty())
    {
        int u, par, depth;
        tie(u, par, depth) = q.front();
        q.pop();
        prev[u] = par;
        if(depth > mx_d)
            last = u, mx_d = depth;
        for(int v : adj[u])
            if(v != par)
                q.push(make_tuple(v, u, depth + 1));
    }

    vector<int> path;
    while(prev[last] != last)
        path.pb(last), last = prev[last];
    path.pb(last);

    int dia = sz(path);
    vector<int> best(1, path[dia / 2]);
    set<int> worst;

    if(sz(path) % 2 == 0)
        best.pb(path[dia / 2 - 1]);
    sort(all(best));
    return best;
}


































vector< vector<int> > adj;

// There are some nodes that must be part of the diameter
// Diameter either pass with me (sum of 2 highest sub-trees) or don't, then diameter pass with a children
// return pair(diameter, height)

// diameter, height pair
pi diameter(int u, vector<vector<int>> &adj, int par = -1)
{
	// Keep largest 2 heights
    int mx_height[3] = {-1, -1, -1};
    int dia = 0;
    for(int v : adj[u])
    {
    	if(v == par)
    		continue;
        pi child = diameter(v, adj, u);
        dia = max(dia, child.ff);

        mx_height[0] = child.ss + 1;
        sort(mx_height, mx_height + 3);
    }
    for(int i = 0; i < 3; i++)
        if(mx_height[i] == -1)
            mx_height[i] = 0;

    dia = max(dia, mx_height[1] + mx_height[2]);

    return {dia, mx_height[2]};
}




// If tree is weighted, same algorithm, just modify the costs
// this algorithm doesn't work for graphs, but gives good approximation















/*
 	One of popular algorithms, although no formal source for proving is 2 BFS idea:
    1- Select a random node A
    2- Run BFS on this node to find furthermost node from A. name this node as S.
    3- Now run BFS starting from S, find the furthermost node from S, name it D.
    4- Path between S and D is diameter of the tree.
 */


void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> vis(n + 1, false);


    queue<pi> q;
    q.push({1, 0}); // random node
    pi farthest = {1, 0};
    // BFS 1
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        vis[u.ff] = true;
        if(u.ss > farthest.ss)
            farthest = u;
        for(int v : adj[u.ff])
        {
            if(!vis[v])
                q.push({v, u.ss + 1}), vis[v] = true;
        }
    }

    fill(all(vis), false);
    q.push({farthest.ff, 0});
    farthest.ss = 0;
    // BFS 2
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        vis[u.ff] = true;
        if(u.ss > farthest.ss)
            farthest = u;
        for(int v : adj[u.ff])
        {
            if(!vis[v])
                q.push({v, u.ss + 1}), vis[v] = true;
        }
    }
    cout << farthest.ss;
}























/*
 * One of applications of tree diameter is finding tree centers
 * 		the nodes in the tree that minimize the length of the longest path from it to any other node.
 *
 * If diameter length is odd, then we have one tree center. If even, then we have 2 centers.
 *
 * E.g. 1-2-3-4-5	-> center is 3
 * E.g. 1-2-3-4-5-6	-> center is 3, 4
 *
 * On other side, we can get the worst nodes through the center nodes.
 * A worst node is one that is an end of a diameter, so it has the worst tree height
 */















// tree isomorphism

// Given 2 trees and roots for each one, are they isomorphic?
// dfs(tree1, tree2)

// General Method: compare(object1, object2) -> Canonical(object1) == Canonical(object2)


/*
 * Graph (1-2, 1-3) and root 1
 * 			1
 * 		2		3
 *
 * 		2 is () and 3 is ()
 * 		1 is ( () () )
 *
 *
 * Graph (1-2, 1-3, 4-1, 4-5) and root 4
 *
 *
 *
 * 		5
 * 	2		3
 * 		4		1
 *
 * 		2, 3, and 5 are ()
 * 		1 is ( () () )
 * 		4 is ( ( () () )  () )
 */













string treeCanoincalForm(int i, int par)
{
    vector<string> childern;

    rep(j, adjLst[i]) if(adjLst[i][j] != par)
        childern.push_back( treeCanoincalForm(adjLst[i][j], i) );

    string nodeRep = "(";
    sort( all(childern) );
    rep(k, childern)
    nodeRep += childern[k];
    nodeRep += ")";

    return nodeRep;
}









// What if no roots? Find roots! Tree has 1 or 2 centers maximum. so we may need maximum to 4 canonical form to compare
// Let's tree other way





















string getNodeCanoincalForm(int v, vector< vector<string> > &subCan)	// we could use hashing for a better performance
{
    string nodeRep = "(";
    sort( all(subCan[v]) );
    rep(i, subCan[v])
    nodeRep += subCan[v][i];
    nodeRep += ")";

    return nodeRep;
}

/*
 * Tree shrinking algorithm. Each time leaves shrink toward their parents.
 */
string treeCanoincalForm()	// assumes tree not forest
{
    int n = sz(adjLst);

    // Prepare level one nodes: the leaves
    queue<int> LeafNodes;
    vector<int> deg(n, -1);
    int remNodes = n;

    rep(i, adjLst)
    {
        if(sz(adjLst[i]) <= 1)
            LeafNodes.push(i);
        else
            deg[i] = sz(adjLst[i]);
    }

    vector< vector<string> > subCan(n);

    while(remNodes > 2)	// bfs-like
    {
        int sz = sz(LeafNodes);
        while(sz--)	// level by level
        {
            int v = LeafNodes.front();
            LeafNodes.pop();

            string nodeRep = getNodeCanoincalForm(v, subCan);

            rep(j, adjLst[v])
            {
                int to = adjLst[v][j];
                subCan[to].push_back(nodeRep);
                if(--deg[to] == 1)
                    LeafNodes.push(to);
            }
            --remNodes;
        }
    }

    // what remains are tree centers
    int v1 = LeafNodes.front();
    LeafNodes.pop();
    int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

    string str1 = getNodeCanoincalForm(v1, subCan);
    string str2 = v2 == -1 ? "" : getNodeCanoincalForm(v2, subCan);

    if(v2 == -1)	// only 1 node
        return str1;

    // 2 nodes. try 2nd as child of first and reverse
    subCan[v1].push_back(str2);
    subCan[v2].push_back(str1);

    return min(getNodeCanoincalForm(v1, subCan), getNodeCanoincalForm(v2, subCan));
}


























int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in", "rt", stdin);
    //freopen(".txt", "wt", stdout);
#endif

    int n;
    scanf("%d", &n);
    adjLst = vector< vector<int> > (n);

    lp(i, n - 1)
    {
        int f, t;
        scanf("%d %d", &f, &t);
        --f, --t;

        adjLst[f].push_back(t);
        adjLst[t].push_back(f);
    }

    cout << treeCanoincalForm();

    return 0;
}