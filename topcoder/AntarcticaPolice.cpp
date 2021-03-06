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

class AntarcticaPolice
{
public:
    double minAverageCost(vector <int>, vector <string>);
};

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
    int N = n;
    TIMER = 0;
    entry.assign(N, -1), low_link.assign(N, -1), comp.assign(N, -1);
    instack.assign(N, false);
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
vector<int> cheapest;
vector<int> other;
void topsort(int u, vector<vector<int>> &adj, vector<int> &top)
{
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            topsort(v, adj, top);
    top.pb(u);
}
void dfs2(int u, vector<vector<int>> &adj, int S, vector<int> &costs)
{
    vis[u] = 1;
    for(int i = (u == S); i < sz(scc[u]); i++)
        other.pb(costs[scc[u][i]]);
    for(int v : adj[u])
        if(!vis[v])
            dfs2(v, adj, S, costs);
}

double AntarcticaPolice::minAverageCost(vector <int> costs, vector <string> roads)
{
    int n = sz(costs);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(roads[i][j] == 'Y')
                adj[i].pb(j);

    tarjan(n, adj);
    adj = component_graph(adj);
    n = sz(scc);

    cheapest.assign(n, INT_MAX);
    for(int i = 0; i < n; i++)
    {
        sort(all(scc[i]), [&](int a, int b)
        {
            return costs[a] < costs[b];
        });
    }
    // find top sort order
    vector<int> top;
    vis.assign(n, false);
    for(int i = 0; i < n; i++)
        if(!vis[i])
            topsort(i, adj, top);

    other.clear();
    int sum = 0, nodes = 0;
    vis.assign(n, false);
    while(!top.empty())
    {
        int u = top.back();
        top.pop_back();
        if(vis[u]) continue;
        dfs2(u, adj, u, costs);
        sum += costs[scc[u].front()], nodes++;
    }
    sort(all(other));
    double avg = double(sum) / double(nodes);
    for(int i = 0; i < sz(other); i++)
    {
        if(other[i] < avg)
            sum += other[i], nodes++, avg = double(sum) / double(nodes);
    }
    return avg;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <string> p1, bool hasAnswer, double p2)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    AntarcticaPolice *obj;
    double answer;
    obj = new AntarcticaPolice();
    clock_t startTime = clock();
    answer = obj->minAverageCost(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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

    vector <int> p0;
    vector <string> p1;
    double p2;

    {
        // ----- test 0 -----
        int t0[] = {1, 2, 3, 4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"NYNN", "NNYN", "NNNY", "YNNN"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {1, 2, 3, 4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"NYNN", "NNYN", "NNNY", "NYNN"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1.0;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {5, 6, 7, 8};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"NYNN", "YNNN", "NNNY", "NNYN"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 6.0;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {10, 5};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"NY", "NN"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 7.5;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {34, 22, 25, 43, 12};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"NYNNY", "YNNYN", "NNNYY", "NNNNN", "NNNNN"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 19.666666666666668;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        int t0[] =
        {699, 814, 745, 644, 455, 765, 853, 713, 989, 932, 847, 496, 882, 860, 910, 799, 872, 481, 524, 988, 960, 999, 984, 596, 742, 797, 757, 963, 418, 976, 943, 885, 857, 628, 612, 705, 604, 906, 762, 922, 298, 590, 990, 697, 976, 503, 820, 990, 823, 854};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] =
        {"NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNYNNNNNNNNNNNNNN", "NNNNNNNNNYNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNYNNNNNNNNNNY", "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN", "NNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNYNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN", "NNNNNNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNYNN", "NNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNN", "NNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN", "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNYYNNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 576.8461538461538;
        all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
