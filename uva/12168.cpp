#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

/*
we are given (keep, remove) pairs
If some person has a pair (A, B)
We should connect it to all the people who want to remove A or keep B

We can use the property of the maximum independent cover which aims to find the maximum number of vertices
such that no two are adjacent in the set
By connecting the two people we can only keep one or the other, satisfying our needs

Is graph bipartite?
Due to the nature of having 1 cat(dog) and 1 dog(cat)
We can never form cycles of odd length
Giving us a bipartite graph!

Now, maximum independent set is minimum edge cover for bipartite graphs
Which is max bipartite match + not matched = N - total matched
*/

vector<int> mt;
vector<bool> vis;

bool kuhn(int u, vector<vector<int>> &adj)
{
    if(vis[u]) return false;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(mt[v] == -1 || kuhn(mt[v], adj))
        {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void cp()
{
    int C, D, N;
    cin >> C >> D >> N;
    vector<pair<string, string>> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i].ff >> arr[i].ss;
    vector<vector<int>> adj(N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(i != j)
                if(arr[i].ff == arr[j].ss || arr[i].ss == arr[j].ff)
                    adj[i].pb(j);

	// Remember how we used chess coloring to differentiate the nodes
	// here we can only connect cats to dogs
    int ans = 0;
    mt.assign(N, -1);
    for(int i = 0; i < N; i++)
    {
        if(arr[i].ff[0] == 'D') continue;
        vis.assign(N, false);
        ans += kuhn(i, adj); // true if flow is found
    }
    ans = N - ans;
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

