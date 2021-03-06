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

class TheSocialNetwork
{
public:
    int minimumCut(int, int, vector <int>, vector <int>, vector <int>);
};

int parent[MAXN], sz[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}

int comp(int n)
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(find_set(i) == i)
            cnt++;
    return cnt;
}

ll po2[MAXN];
int TheSocialNetwork::minimumCut(int n, int m, vector <int> u, vector <int> v, vector <int> l)
{
    po2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        po2[i] = (po2[i - 1] * 2) % mod;

    vector<vector<int>> edges;
    for(int i = 0; i < m; i++)
        edges.pb({u[i], v[i], l[i]});
    sort(all(edges), [&](vector<int> a, vector<int> b)
    {
        return a[2] > b[2];
    });

    ll res = 0;
    vector<bool> ignore(m);

    make_set(n + 1);
    for(int i = 0; i < m; i++)
    {
        union_set(edges[i][0], edges[i][1]);
        int c = comp(n);
        if(c == 1) // remove this edge, critical edge
        {
            ignore[i] = 1;
            make_set(n + 1);
            for(int j = 0; j < i; j++)
                if(!ignore[j])
                    union_set(edges[j][0], edges[j][1]);
            res = (res + po2[edges[i][2]]) % mod;
        }
    }
    return res;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, vector <int> p4, bool hasAnswer, int p5)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
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
    cout << "}";
    cout << "]" << endl;
    TheSocialNetwork *obj;
    int answer;
    obj = new TheSocialNetwork();
    clock_t startTime = clock();
    answer = obj->minimumCut(p0, p1, p2, p3, p4);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p5 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p5;
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

    int p0;
    int p1;
    vector <int> p2;
    vector <int> p3;
    vector <int> p4;
    int p5;

    {
        // ----- test 0 -----
        p0 = 6;
        p1 = 6;
        int t2[] = {1, 2, 3, 4, 5, 6};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {2, 3, 4, 5, 6, 1};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {1, 7, 3, 4, 6, 12};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 10;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 5;
        p1 = 7;
        int t2[] = {1, 1, 1, 2, 2, 3, 3};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {5, 3, 2, 5, 3, 5, 4};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {1, 8, 2, 3, 4, 6, 9};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 28;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 7;
        p1 = 6;
        int t2[] = {1, 1, 2, 2, 3, 3};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {2, 3, 4, 5, 6, 7};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {7, 11, 6, 9, 20, 15};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 64;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 8;
        p1 = 11;
        int t2[] = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 7};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {2, 8, 3, 5, 4, 6, 7, 5, 6, 8, 8};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {2, 3, 1, 6, 11, 8, 9, 10, 7, 4, 5};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 12;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 13;
        p1 = 56;
        int t2[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {3, 4, 5, 7, 9, 12, 13, 3, 5, 8, 9, 10, 12, 13, 5, 6, 8, 9, 10, 11, 12, 5, 6, 7, 9, 11, 13, 7, 8, 9, 11, 12, 7, 8, 9, 10, 13, 8, 9, 10, 11, 12, 13, 9, 11, 12, 10, 11, 12, 13, 11, 12, 13, 12, 13, 13};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {82, 240, 395, 1041, 1165, 1274, 1540, 1650, 1904, 2306, 2508, 3162, 3380, 3637, 3778, 3913, 3971, 4101, 4148, 4218, 4394, 4434, 5107, 6147, 6280, 6337, 6461, 6490, 7056, 8024, 8373, 8924, 8961, 9058, 9304, 9359, 10899, 11049, 11090, 11174, 11269, 11356, 11547, 11808, 12566, 12591, 13322, 13447, 13667, 13672, 15013, 15319, 16153, 16447, 16454, 16470};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 504663883;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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
