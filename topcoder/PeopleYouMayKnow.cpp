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
const int MAXN = 1e2 + 5;

class PeopleYouMayKnow
{
public:
    int maximalScore(vector <string>, int, int);
};


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

int PeopleYouMayKnow::maximalScore(vector <string> friends, int A, int B)
{
    int n = sz(friends);
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = friends[i][j] == 'Y';

    clr(flow, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 3 length path
            if(adj[A][i] && adj[i][j] && adj[j][B])
            {
                flow[out(A)][in(i)] = flow[out(i)][in(A)] = inf;
                flow[out(i)][in(j)] = flow[out(j)][in(i)] = inf;
                flow[out(j)][in(B)] = flow[out(B)][in(j)] = inf;
            }
        }
        // 2 length path
        if(adj[A][i] && adj[i][B])
        {
            flow[out(A)][in(i)] = flow[out(i)][in(A)] = inf;
            flow[out(i)][in(B)] = flow[out(B)][in(i)] = inf;
        }
    }

    for(int i = 0; i < n; i++)
        flow[in(i)][out(i)] = 1;

    N = 2 * n;
    int F = max_flow(out(A), in(B));
    return F;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, bool hasAnswer, int p3)
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
    cout << "}" << "," << p1 << "," << p2;
    cout << "]" << endl;
    PeopleYouMayKnow *obj;
    int answer;
    obj = new PeopleYouMayKnow();
    clock_t startTime = clock();
    answer = obj->maximalScore(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p3;
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
    int p2;
    int p3;

    {
        // ----- test 0 -----
        string t0[] = {"NN", "NN"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0;
        p2 = 1;
        p3 = 0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0;
        p2 = 3;
        p3 = 1;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"NYNYYYN", "YNYNNYY", "NYNNNNY", "YNNNNNN", "YNNNNYN", "YYNNYNY", "NYYNNYN"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        p2 = 3;
        p3 = 1;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"NYYYYNNNN", "YNNNNYYYN", "YNNNNNNYN", "YNNNNNNYN", "YNNNNNNNY", "NYNNNNNNY", "NYNNNNNNY", "NYYYNNNNY", "NNNNYYYYN"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        p2 = 0;
        p3 = 3;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 3 -----
        string t0[] = {"NNNYYNNNNYNNNYNNYNYNNNYN", "NNNNNYNNNNNNNNNYYNNNYNNN", "NNNNNNNYNNNNYYNNYNNYNNNY", "YNNNNYNNNNNNNNNNNYYYNNNN", "YNNNNNNNNNNNNNYYYNNNNNYY", "NYNYNNYYNNNNYNYNNNNNNNYN", "NNNNNYNNNYYNYYNNYYNNNNNY", "NNYNNYNNYNNNNNNNNNNYNNNY", "NNNNNNNYNNYNYNYNNNNYNNYN", "YNNNNNYNNNNNYYNNNNYNYNNN", "NNNNNNYNYNNNNYNNYNNNNNYN", "NNNNNNNNNNNNNNNYNNNYNYNN", "NNYNNYYNYYNNNYNYYNYNYNNN", "YNYNNNYNNYYNYNNNNNNNNYNN", "NNNNYYNNYNNNNNNNYNNNNNNY", "NYNNYNNNNNNYYNNNYYNYNNNN", "YYYNYNYNNNYNYNYYNYNNYNNN", "NNNYNNYNNNNNNNNYYNNNYNNY", "YNNYNNNNNYNNYNNNNNNNNNNY", "NNYYNNNYYNNYNNNYNNNNNYNN", "NYNNNNNNNYNNYNNNYYNNNNYN", "NNNNNNNNNNNYNYNNNNNYNNYY", "YNNNYYNNYNYNNNNNNNNNYYNN", "NNYNYNYYNNNNNNYNNYYNNYNN"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        p2 = 15;
        p3 = 4;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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