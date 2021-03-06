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

class TopView
{
public:
    string findOrder(vector <string>);
};
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
int vis[55][55];
int n, m;
vector<string> arr;
map<char, set<int>> adj;
map<char, int> l, r, u, d;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    char c = arr[x][y];
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= u[c] && nx <= d[c] && ny >= l[c] && ny <= r[c])
        {
            if(!vis[nx][ny])
                dfs(nx, ny);
            if(arr[nx][ny] != c) // join edge
                adj[arr[nx][ny]].insert(c);
        }
    }
}

bool cycle;
int vis2[256], instack[256];
void topsort(char c, string &top)
{
    vis2[int(c)] = 1;
    instack[int(c)] = 1;

    for(char v : adj[c])
        if(!vis2[int(v)])
            topsort(v, top);
        else if(instack[int(v)])
            cycle = true;
    top += c;
    instack[int(c)] = 0;
}

string TopView::findOrder(vector <string> grid)
{
    n = sz(grid) + 2, m = sz(grid[0]) + 2;
    arr.clear();
    arr.pb(string(m, '.'));
    adj.clear();
    l.clear(), r.clear(), u.clear(), d.clear();
    for(string x : grid)
        arr.pb("." + x + ".");
    arr.pb(string(m, '.'));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(!l.count(arr[i][j])) l[arr[i][j]] = j;
            else l[arr[i][j]] = min(l[arr[i][j]], j);
            if(!r.count(arr[i][j])) r[arr[i][j]] = j;
            else r[arr[i][j]] = max(r[arr[i][j]], j);
            if(!u.count(arr[i][j])) u[arr[i][j]] = i;
            else u[arr[i][j]] = min(u[arr[i][j]], i);
            if(!d.count(arr[i][j])) d[arr[i][j]] = i;
            else d[arr[i][j]] = max(d[arr[i][j]], i);
        }

    clr(vis, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j])
                dfs(i, j);
    adj['.'];
    // for(auto x : adj)
    // {
    //     cout << x.ff << "-> ";
    //     for(char y : x.ss)
    //         cout << y << " ";
    //     cout << endl;
    // }

    clr(vis2, 0), clr(instack, 0);
    string s;
    cycle = false;
    for(auto x : adj)
        if(!vis2[int(x.ff)])
            topsort(x.ff, s);
    reverse(all(s));
    if(!s.empty()) s.pop_back();
    reverse(all(s));
    return (cycle ? "ERROR!" : s);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1)
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
    TopView *obj;
    string answer;
    obj = new TopView();
    clock_t startTime = clock();
    answer = obj->findOrder(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
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
    string p1;

    {
        // ----- test 0 -----
        string t0[] = {"..AA..", ".CAAC.", ".CAAC."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "CA";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"..47..", "..74.."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "ERROR!";
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"bbb666", ".655X5", "a65AA5", "a65AA5", "a65555"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "65AXab";
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"aabbaaaaaaaaaaaaaaaaaa", "aabbccccccccccccccaaaa", "aab11111ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ddddddddddaaaa", "aab13331DDDDDDDDDDaaaa", "aab13331DDDDDDDDDDaaaa", "aa.11111DDDDDDDDDDaaaa", "aaaaaaaaaaaaaaaaaaaaaa"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "ERROR!";
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
