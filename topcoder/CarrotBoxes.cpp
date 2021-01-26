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

class CarrotBoxes
{
public:
    double theProbability(vector <string>);
};

int count_y(string &s)
{
    int cnt = 0;
    for(char x : s) cnt += x == 'Y';
    return cnt;
}

double CarrotBoxes::theProbability(vector <string> info)
{
    int n = sz(info);
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b)
    {
        return count_y(info[a]) > count_y(info[b]);
    });

}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, double p1)
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
    CarrotBoxes *obj;
    double answer;
    obj = new CarrotBoxes();
    clock_t startTime = clock();
    answer = obj->theProbability(p0);
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
        res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
    double p1;

    {
        // ----- test 0 -----
        string t0[] = {"YYYYY", "NYNNN", "NNYNN", "NNNYN", "NNNNY"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0.8;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"YNNNN", "NYNNN", "NNYNN", "NNNYN", "NNNNY"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0.2;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"Y"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1.0;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"YNNNN", "YYNNN", "YNYNN", "NNNYY", "NNNYY"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0.6;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"YYYNNNYN", "NYNNNNYN", "NNYNNNNN", "NYNYNNNN", "YNNNYNNY", "NNYNNYNN", "NNNNYNYN", "NNYNNNNY"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0.875;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        string t0[] = {"YNNNNNNNNYNNNNNNNNNN", "NYNNNNNNNNNNNNNNNNNN", "NNYNNNNNNNYNNNNNYNNN", "NNNYNYNNNNNNNNYNNNNN", "NNNNYNNNNNNNNNYNNNNY", "NNNNNYNNNNNNNNNNNNNY", "NNNNYNYNYNNNNNNNNNNN", "NNNNNNNYNNNYYNNNNNNN", "NNNNNNNNYNNNNNNNNNNN", "YNNNNNNNNYNNNNNYNNNN", "NNNNNNNNNNYNNNNNNNNN", "NYNNNNNNNNNYNNNNNNNN", "NNNNNNNYNNNNYNNNNNNN", "NNNNNNNNNNNNNYNNNYNN", "NNNNNNNNNNNYNNYNNNYN", "NYNNNNNNNNNNNNNYNNNN", "NNYNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNYNYNYNN", "NNNNNNNNYNYNNNNNNNYY", "NNNYNNNNNNNNNNNNNNNY"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0.75;
        all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
