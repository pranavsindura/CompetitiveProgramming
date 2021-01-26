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

class BeatTheStar
{
public:
    double doesItMatter(int, int);
};
int N, G;
double dp[105][105 * 105][2];
double solve(int i, int score, bool winG)
{
    if(i > N)
    {
        int a = score, b = N * (N + 1) / 2 - score;
        bool win = a > b;
        // if i won G, then lose G
        if(winG)
            a -= G, b += G;
        // else win G
        else
            a += G, b -= G;
        bool nwin = a > b;
        return (win ^ nwin);
    }

    double &ret = dp[i][score][winG];
    if(fabs(ret + 1) > eps)
        return ret;

    double ans = 0;
    ans += 0.5 * solve(i + 1, score + i, winG || (i == G));
    ans += 0.5 * solve(i + 1, score, winG);
    return ret = ans;
}

double BeatTheStar::doesItMatter(int N, int G)
{
    ::N = N, ::G = G;
    clr(dp, -1);
    return solve(1, 0, 0);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, double p2)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1;
    cout << "]" << endl;
    BeatTheStar *obj;
    double answer;
    obj = new BeatTheStar();
    clock_t startTime = clock();
    answer = obj->doesItMatter(p0, p1);
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

    int p0;
    int p1;
    double p2;

    {
        // ----- test 0 -----
        p0 = 2;
        p1 = 1;
        p2 = 0.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 5;
        p1 = 5;
        p2 = 0.625;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 5;
        p1 = 1;
        p2 = 0.125;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 5;
        p1 = 2;
        p2 = 0.125;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 9;
        p1 = 7;
        p2 = 0.328125;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
