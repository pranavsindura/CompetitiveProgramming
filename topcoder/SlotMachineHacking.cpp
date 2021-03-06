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

class SlotMachineHacking
{
public:
    int win(vector <string>, vector <int>);
};

int SlotMachineHacking::win(vector <string> reels, vector <int> steps)
{
    int n = sz(reels);
    for(int i = 0; i < n; i++)
        steps[i] %= sz(reels[i]);
    int p, pp;
    bool ok;
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
        pos[i] = find(all(reels[i]), 'c') - begin(reels[i]);
    for(int i = 1; i < 1e6; i++)
    {
        ok = true;
        for(int j = 0; j < n; j++)
        {
            p = (steps[j] * i) % sz(reels[j]);
            pp = (pos[j] - p + sz(reels[j])) % sz(reels[j]);
            ok &= !pp;
        }
        if(ok) return i - 1;
    }
    return -1;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <int> p1, bool hasAnswer, int p2)
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
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    SlotMachineHacking *obj;
    int answer;
    obj = new SlotMachineHacking();
    clock_t startTime = clock();
    answer = obj->win(p0, p1);
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
        res = answer == p2;
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
    vector <int> p1;
    int p2;

    {
        // ----- test 0 -----
        string t0[] = {"abc", "acb", "cab"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {32, 31, 30};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 0;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"abc", "acb", "cab"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {30, 33, 300000006};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = -1;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"abc", "bac", "abpc"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 1, 1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 10;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"aac", "aac", "aaac"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 1, 1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 10;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"c", "c", "ababcbabab", "c"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {470, 4700, 47002, 470000};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        string t0[] = {"ca", "caba"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 2};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1;
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
