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
const int MAXN = 200 + 5;

class GreenWarfare
{
public:
    int minimumEnergyCost(vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, int);
};

map<pi, int> comp;
int idx(pi x)
{
    if(comp.count(x)) return comp[x];
    else return comp[x] = sz(comp) - 1;
}

int dist(pi a, pi b)
{
    return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}

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

int GreenWarfare::minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius)
{
    /*
    	S ---------> base ----> all plants --------> T
    	  min Canon       inf              min canon
    */
    comp.clear();
    clr(flow, 0);
    int S = idx(mp(-600, -600)), T = idx(mp(-600, -601));

    for(int i = 0; i < sz(baseX); i++)
    {
        pi B = {baseX[i], baseY[i]};
        flow[S][idx(B)] = inf;
        for(int j = 0; j < sz(canonX); j++)
        {
            pi C = {canonX[j], canonY[j]};
            flow[S][idx(B)] = min(flow[S][idx(B)], dist(C, B));
        }
    }

    for(int i = 0; i < sz(plantX); i++)
    {
        pi P = {plantX[i], plantY[i]};
        flow[idx(P)][T] = inf;
        for(int j = 0; j < sz(canonX); j++)
        {
            pi C = {canonX[j], canonY[j]};
            flow[idx(P)][T] = min(flow[idx(P)][T], dist(C, P));
        }
    }

    for(int j = 0; j < sz(baseX); j++)
    {
        pi B = {baseX[j], baseY[j]};
        for(int k = 0; k < sz(plantX); k++)
        {
            pi P = {plantX[k], plantY[k]};
            if(dist(B, P) <= energySupplyRadius * energySupplyRadius)
            {
                flow[idx(B)][idx(P)] = inf;
            }
        }
    }

    N = sz(comp);
    return max_flow(S, T);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, vector <int> p4, vector <int> p5, int p6, bool hasAnswer, int p7)
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
        cout << p1[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p4.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p4[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p5.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p5[i];
    }
    cout << "}" << "," << p6;
    cout << "]" << endl;
    GreenWarfare *obj;
    int answer;
    obj = new GreenWarfare();
    clock_t startTime = clock();
    answer = obj->minimumEnergyCost(p0, p1, p2, p3, p4, p5, p6);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p7 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p7;
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
    vector <int> p1;
    vector <int> p2;
    vector <int> p3;
    vector <int> p4;
    vector <int> p5;
    int p6;
    int p7;

    {
        // ----- test 0 -----
        int t0[] = {0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1, 2, 3};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {0, 0, 0};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {3};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        int t5[] = {3};
        p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
        p6 = 4;
        p7 = 14;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1, 2, 3};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {0, 0, 0};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {2};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        int t5[] = {2};
        p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
        p6 = 4;
        p7 = 8;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {3, 6};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {3, 6};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1, 2, 3, 4, 5};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {5, 4, 2, 3, 1};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {1, 2, 5};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        int t5[] = {1, 2, 5};
        p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
        p6 = 5;
        p7 = 12;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {-10, -10, 10};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {10, -10, 0};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {10, 10, -10};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        int t5[] = {10, -10, 0};
        p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
        p6 = 10;
        p7 = 200;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {3};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {3};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {1, 2, 3};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        int t5[] = {0, 0, 0};
        p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
        p6 = 4;
        p7 = 14;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
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
