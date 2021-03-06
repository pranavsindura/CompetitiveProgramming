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

class DrawingLines
{
public:
    double countLineCrossings(int, vector <int>, vector <int>);
};

double DrawingLines::countLineCrossings(int n, vector <int> startDot, vector <int> endDot)
{
    double ans = 0;
    vector<int> top(n + 1), bot(n + 1, 1);
    bot[0] = 0;

    for(int i = 0; i < sz(startDot); i++) top[startDot[i]] = endDot[i];
    for(int x : endDot) bot[x] = 0;

    for(int i = 1; i <= n; i++)
        bot[i] += bot[i - 1];

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(top[i] && top[j])
                ans += top[j] < top[i];
            else if(top[i])
                ans += double(bot[top[i] - 1]) / double(bot[n]);
            else if(top[j])
                ans += double(bot[n] - bot[top[j]]) / double(bot[n]);
            else
                ans += 0.5;
    return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, double p3)
{
    cout << "Test " << testNum << ": [" << p0 << "," << "{";
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
    cout << "}";
    cout << "]" << endl;
    DrawingLines *obj;
    double answer;
    obj = new DrawingLines();
    clock_t startTime = clock();
    answer = obj->countLineCrossings(p0, p1, p2);
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
        res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
    vector <int> p1;
    vector <int> p2;
    double p3;

    {
        // ----- test 0 -----
        p0 = 3;
        int t1[] = {2};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {3};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 1.5;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 5;
        int t1[] = {1, 4};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {3, 1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 5.5;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 4;
        int t1[] = {4, 1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {4, 1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 0.5;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 8;
        int t1[] = {1, 4, 3, 6, 7};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1, 3, 2, 4, 5};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 7.5;
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
