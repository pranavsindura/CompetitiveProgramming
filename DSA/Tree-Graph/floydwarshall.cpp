#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
const int INF = 1e9;

============= FLOYD WARSHALL ================
/*
 * Single source Shortest path
 * All Pairs Shortest path
 */



int shortestPath(int i, int j)  // cyclic recurrence
{
    int mn = adj[i][j];

    for(int k = 0; k < n; ++k) if(k != i && k != j)
        mn = min(mn, shortestPath(i, k) + shortestPath(k, j));

    return mn;
}



int floyd(int i, int j, int k)  // Recurrence redefinition
{
    if(k == 0)
        return adj[i][j];

    return min(floyd(i, j, k-1), floyd(i, k, k-1) + floyd(k, j, k-1));
}



// This is memoized in O(n^3)

void floyd1()
{
    lp(i, n) lp(j, n)
        dp[0][i][j] = adj[i][j];

    lp(k, n) lp(i, n) lp(j, n)
        if(dp[k][i][k] < OO && dp[k][k][j] < OO)
            dp[k+1][i][j] = min(dp[k+1][i][j], dp[k][i][k]+dp[k][k][j]);

    // dp[n] is the shortest path 2d array
}




void floyd2()
{
    // 0 - Infinity MUST be larger than any path. Say we have n = 1000, and cost of edge max 5000, then min OO to = (1000-1) * 5000 + 1
    // 1- Set whole array to infinity:
    // 2- read input edges
    // 3- set diagonal to zeros: sometimes, if negative input you would like to leave them: e.g. adj[3][3] = -7 -> a self cycle

    // k: Incrementally add new node and update matrix
    lp(k, n) lp(i, n) lp(j, n)
        if(adj[i][k] < OO && adj[k][j] < OO)    // you could remove this line IFF 2*OO fit in the data type.
            adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

    // an order lp(i, n) lp(j, n) lp(k, n)      is wrong translation
}



================ DIFFERENT TYPES OF PATHS ====================

// What if we need to get the path? 2 ways

    // Define path arr, initialize it to -1, which means direct
    // If path (i, j) has intermediate node k, then path[i][j] = k; means path from i to j pass with k
    // Write a recursive function be like:
    
// UVA 186
// UVA 10448
void build_path(int src, int dest)
{
    if( path[src][dest] == -1 ) //So this is the last way
    {
        // print
        return;
    }
    build_path( src, path[src][dest]);
    build_path( path[src][dest], dest);
}
     

    // Other way is through previous of path: prev[i][j]: last node before j from i to j
    // Initialize repv[i][j] = i
    // If path (i, j) has intermediate node k, then prev[i][j] = prev[k][j];
    // Write a recursive function be like:
    
void printPath(int i, int j)
{
    if (i != j)
        printPath(i, prev[i][j]);
    printf(" %d", j);
}
    

 

void TransitiveClosure()
{
    // REFER UVA 334
    // assume matrix is 0 for disconnect, 1 is connect
    // we only care if a path exist or not, not a shortest path value

    lp(k, n) lp(i, n) lp(j, n)
        adj[i][j] |= (adj[i][k] & adj[k][j]);
}

void minimax()
{
    // REFER UVA 534
    // find path such that max value on road is minimum

    lp(k, n) lp(i, n) lp(j, n)
        adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void maximin()
{
    // find path such that min value on road is maximum

    lp(k, n) lp(i, n) lp(j, n)
        adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]) );
}

void longestPathDAG()
{
    lp(k, n) lp(i, n) lp(j, n)
        adj[i][j] = max(adj[i][j], max(adj[i][k], adj[k][j]) );
}




==================PATHS & CYCLES==================

void countPaths()
{
    lp(k, n) lp(i, n) lp(j, n)  // Floyd warshal for counting #of paths
        adj[i][j] += adj[i][k] * adj[k][j];

    // 1- assume graph is DAG
    /*
     * k = 5, i = 1, j = 2 we will use adj[ 1 ][ 5 ] with old value
     * k = 5, i = 1, j = 5 we will update adj[ 1 ] [ 5 ]
     * k = 5, i = 1, j = 7 we will use adj[ 1 ][ 5 ] with new value
     * Won't this give and incorrect result?
     *
     * NO. E.g. when k = 5, i = 1, j = 5:
     * adj[1][5] += adj[1][5] * adj[5][5];
     * adj[5][5] = 0, so no update happens. In general, when k = i or j, no updates happens, so in-placement update is fine.
     */

    /*
     * REFER UVA 125
     * What if graph is not DAG.
     * if(adj[i][i] > 0)    -> i has a cycle path on it
     *
     * Generally, for any node v that has a cycle,
     *      if i reaches v, and v reaches j, then count of (i, j) is useless as count is OO. Remain adj[][] is valid
     */

}



/*
 * . If you had a cycle in a graph, the longest path wouldn't be
well defined, because you could keep going round and round the cycle
making the path longer.
 */

bool isNegativeCycle() {
    lp(i, n)
        if(adj[i][i] < 0)
            return true;    // then node i got to i with overall cost < 0.

    return false;
}

bool anyEffectiveCycle(int src, int dest)
{
    lp(i, n)
        if(adj[i][i] < 0 && adj[src][i] < OO && adj[i][dest] < OO)
            return true;

    return false;   // there is a finite path although cycles if any
}








/*
 * Graph negative:
 *  Shortest <-> Longest
 *  Postive Cycle <-> Negative Cycle
 *  Minimax <-> Maximin
 */




===================== Graph Diameter ======================



int graphDiameter()
{   // Longest path among all shortest ones

    floyd2();

    int mx = 0;
    lp(i, n) lp(j, n) if(adj[i][j] < OO)
        mx = max(mx, adj[i][j]);

    return mx;
}





============STRONGLY CONNECTED COMPONENTS===========





vector< vector<int> > SCC()
{
    vector<int> comp(n, -1);

    int cnt = 0;
    lp(i, n) if(comp[i]==-1) {
        comp[i] = cnt++;
        lp(j, n) if(adj[i][j] < OO && adj[j][i] < OO)   // transitive clusre is enough
            comp[j] = comp[i];
    }

    vector< vector<int> > compGraph(cnt, vector<int>(cnt));

    lp(i, n) lp(j, n)   if(adj[i][j] < OO)
        compGraph[ comp[i] ][ comp[j] ] = 1;    // DAG

    return compGraph;
}



int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n][n];
        // matrix(i,j) = cost of edge i->j, directed
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {

                cin >> arr[i][j];
            }
        }
        //FLOYD WARSHALL
        //does not work for negative cycles
        //for some t, arr[t][t] < 0
        //here we assume self loops dont exist, hence arr[t][t] = 0
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i == j)
                        arr[i][j] = 0;
                    else if(i == k || j == k)
                        continue;
                    else
                    {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

==========Shortest Path with exactly/atmost K edges==========
/*
W -> Adjacency matrix

Using min, + multiplication
C = A * B
C[i][j] = min{A[i][k] + B[k][j]}

Here we pick min on the RHS, not minimise the LHS with it
So we can set it initially to INF to replicate the idea

Identity Matrix for min, +
       [0,INF,INF]
I(3) = [INF,0,INF]
       [INF,INF,0]

W^K is the matrix which represents the shortest paths with EXACTLY K edges
This can be found with matrix power
SRM795-D1-300 AtleastKDays


Here instead of comparing with INF, if we compare with the previous matrix
then it will be ATMOST K edges
Thus W^N in that sense will be same as the distance matrix with atmost N edges we achieve
with Floyd Warshall
*/

vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    int n = sz(a);
    vector<vector<ll>> c(n, vector<ll>(n, inf));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
    return c;
}

vector<vector<ll>> fpow(vector<vector<ll>> x, int y)
{
    int n = sz(x);
    vector<vector<ll>> res(n, vector<ll>(n, inf));
    for(int i = 0; i < n; i++) res[i][i] = 0;
    while(y > 0)
    {
        if(y & 1)
            res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}