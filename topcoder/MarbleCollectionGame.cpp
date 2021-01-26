#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

class MarbleCollectionGame
{
public:
    int collectMarble(vector <string>);
};

int n, m;
inline bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int TIMER;
vector<int> entry, low_link, val, compval, comp;
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
        compval.pb(0);
        int x = -1;
        while(x != u)
        {
            x = st.top();
            st.pop();
            instack[x] = 0;
            scc.back().pb(x);
            comp[x] = sz(scc) - 1;
            compval.back() += val[x];
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
    compval.clear();
    while(!st.empty()) st.pop();
    scc.clear();

    for(int i = 0; i < n; i++)
        if(entry[i] == -1)
            dfs(i, adj);
}

vector<vector<int>> component_graph(vector<vector<int>> &adj)
{
    // Find SCC
    vector<vector<int>> G(sz(scc));
    for(int u = 0; u < sz(adj); u++)
        for(int v : adj[u])
            if(comp[u] != comp[v])
                G[comp[u]].pb(comp[v]);
    return G;
}

vector<bool> vis;
vector<int> subtree;
int dfs2(int u, vector<vector<int>> &adj)
{
	if(vis[u]) return subtree[u];
    int ans = compval[u];
    vis[u] = 1;
    for(int v : adj[u])
        ans = max(ans, compval[u] + dfs2(v, adj));
    return subtree[u] = ans;
}

int MarbleCollectionGame::collectMarble(vector <string> board)
{
    n = sz(board), m = sz(board[0]);
    /*
    	There can be cycles
    	Find the component graph, assign sum value of nodes to its scc
    	Now we have DAG
    	We have to find the maximum weight path in the DAG
    */
    vector<vector<int>> adj(n * m);
    val.resize(n * m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == '#') continue;
            if(board[i][j] == 'U' && valid(i - 1, j)) adj[i * m + j].pb((i - 1) * m + j);
            if(board[i][j] == 'L' && valid(i, j - 1)) adj[i * m + j].pb(i * m + j - 1);
            if(valid(i + 1, j)) adj[i * m + j].pb((i + 1) * m + j);
            if(valid(i, j + 1)) adj[i * m + j].pb(i * m + j + 1);
            val[i * m + j] = isdigit(board[i][j]) ? board[i][j] - '0' : 0;
        }
    tarjan(n * m, adj);

    vector<vector<int>> C = component_graph(adj);
    vis.assign(sz(C), false);
    subtree.assign(sz(C), 0);

    return dfs2(comp[0], C);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    MarbleCollectionGame *obj;
    int answer;
    obj = new MarbleCollectionGame();
    clock_t startTime = clock();
    answer = obj->collectMarble(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p1;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    vector <string> p0;
    int p1;

    {
        // ----- test 0 -----
        string t0[] = {"7"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 7;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"0", "8"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"264", "3LL"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 15;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"8U4L9", "0183U", "U8#38", "2158#", "L65U7"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 44;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"7U8L80#5ULU076L300", "#U0687#4664773#UL8", "8U6L599U93#43984#6", "6#61193744563228L1", "L93785U62603890024", "1UU#U2#14#2L9848U9", "L58#75007L92270335", "757L#LU4772LL6115#", "03L2883L1L#8996#31", "48045U74U5U#306265", "21L427623U6LU12L22", "U750U27#713U2#56L7", "LL130U39L878UU5244", "851795075LU49U#027", "03#8L50#9#L61U5049", "24UU05L8#5U48035#0", "##354L##U96498U#8U", "07480388LU615#U498"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 55;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
