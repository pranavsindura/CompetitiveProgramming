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

class CorrectMultiplication
{
public:
    long long getMinimum(int, int, int);
};

long long CorrectMultiplication::getMinimum(int a, int b, int c)
{
    ll ans = LLONG_MAX;
    for(int i = 1; i <= min(MAXN, c); i++)
    {
        int j = c / i;
        if(j > 0) ans = min(ans, 0LL + abs(a - i) + abs(c - i * j) + abs(b - j));
        j = (c + i - 1) / i;
        if(j > 0) ans = min(ans, 0LL + abs(a - i) + abs(c - i * j) + abs(b - j));
    }
    for(int j = 1; j <= min(MAXN, c); j++)
    {
        int i = c / j;
        if(i > 0) ans = min(ans, 0LL + abs(a - i) + abs(c - i * j) + abs(b - j));
        i = (c + j - 1) / j;
        if(i > 0) ans = min(ans, 0LL + abs(a - i) + abs(c - i * j) + abs(b - j));
    }
    return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, long long p3)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
    cout << "]" << endl;
    CorrectMultiplication *obj;
    long long answer;
    obj = new CorrectMultiplication();
    clock_t startTime = clock();
    answer = obj->getMinimum(p0, p1, p2);
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

    int p0;
    int p1;
    int p2;
    long long p3;

    {
        // ----- test 0 -----
        p0 = 19;
        p1 = 28;
        p2 = 522;
        p3 = 2ll;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 10;
        p1 = 30;
        p2 = 500;
        p3 = 11ll;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 11111;
        p1 = 11111;
        p2 = 123454321;
        p3 = 0ll;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 1000;
        p1 = 100;
        p2 = 10;
        p3 = 1089ll;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 399;
        p1 = 522;
        p2 = 199999;
        p3 = 24ll;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
