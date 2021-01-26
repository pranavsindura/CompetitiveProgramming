#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

class TwoRobots
{
public:
    int move(vector <string>);
};

struct state
{
    int a, b, p, q, steps;
    state(): a(0), b(0), p(0), q(0), steps(0) {};
    state(int a, int b, int p, int q, int steps): a(a), b(b), p(p), q(q), steps(steps) {};
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[45][45][45][45];

int TwoRobots::move(vector <string> arr)
{
    clr(vis, 0);
    int n = sz(arr), m = sz(arr[0]);
    queue<state> Q;
    state st;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'A')
                st.a = i, st.b = j;
            else if(arr[i][j] == 'B')
                st.p = i, st.q = j;

    auto valid = [&](int a, int b)
    {
        return (a >= 0 && a < n && b >= 0 && b < m && arr[a][b] != '#');
    };

    Q.push(st);
    while(!Q.empty())
    {
        state u = Q.front();
        Q.pop();
        int a = u.a, b = u.b, p = u.p, q = u.q, steps = u.steps;
        vis[a][b][p][q] = 1;

        if(arr[a][b] == 'a' && arr[p][q] == 'b')
	        return steps;

        for(int i = 0; i < 4; i++)
        {
            int na = a + dx[i], nb = b + dy[i];
            if(!valid(na, nb)) continue;
            for(int j = 0; j < 4; j++)
            {
                int np = p + dx[j], nq = q + dy[j];
                if(!valid(np, nq)) continue;
                // Move A first, then B
                bool can = true;
                if(na == p && nb == q) can = false;
                if(np == na && nq == nb) can = false;
                if(vis[na][nb][np][nq]) can = false;
                if(can)
                {
                    vis[na][nb][np][nq] = 1;
                    Q.push(state(na, nb, np, nq, steps + 1));
                }

                // Move B first, then A
                can = true;
                if(np == a && nq == b) can = false;
                if(np == na && nq == nb) can = false;
                if(vis[na][nb][np][nq]) can = false;
                if(can)
                {
                    vis[na][nb][np][nq] = 1;
                    Q.push(state(na, nb, np, nq, steps + 1));
                }
            }
        }
    }

    return -1;
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
    TwoRobots *obj;
    int answer;
    obj = new TwoRobots();
    clock_t startTime = clock();
    answer = obj->move(p0);
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
        string t0[] = {"Ab.a", "...B"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"#a#", "A.b", "#B#"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = -1;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"#b#", "A.a", "#B#", "#.#"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = -1;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"...", "#a#", "A.b", "#B#", "#.#"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"AB......ab"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        string t0[] = {"bA......Ba"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = -1;
        all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 6 -----
        string t0[] = {"bA.......Ba"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = -1;
        all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 7 -----
        string t0[] = {"AB.........", "...........", "...........", "........b.a"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = -1;
        all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 8 -----
        string t0[] = {"...A...", ".#####.", ".#####b", "B#####.", ".#####.", ".#####.", "..a...."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 13;
        all_right = KawigiEdit_RunTest(8, p0, true, p1) && all_right;
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
