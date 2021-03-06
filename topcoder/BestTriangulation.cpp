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

// POINT
typedef double ftype;
// const ftype eps = 1e-9; // 0 for integer points.
struct point
{
    ftype x, y;
    point() {}
    point(ftype x, ftype y): x(x), y(y) {}
    point operator+(const point &p)
    {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p)
    {
        return point(x - p.x, y - p.y);
    }
    point operator*(const ftype &s)
    {
        return point(x * s, y * s);
    }
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
    ftype cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    ftype cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
};

class BestTriangulation
{
public:
    double maxArea(vector <string>);
};

double area(point a, point b, point c)
{
    point p = b - a, q = c - a;
    return fabs(p.cross(q) / 2.0);
}

double BestTriangulation::maxArea(vector <string> vertices)
{
    int n = sz(vertices);
    vector<point> p(n);
    for(int i = 0; i < n; i++)
    {
        stringstream ss(vertices[i]);
        ss >> p[i].x >> p[i].y;
    }
    p.pb(p[0]), p.pb(p[1]);

    double ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                ans = max(ans, area(p[i], p[j], p[k]));
    return ans;
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
    BestTriangulation *obj;
    double answer;
    obj = new BestTriangulation();
    clock_t startTime = clock();
    answer = obj->maxArea(p0);
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
        string t0[] = {"1 1", "2 3", "3 2"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1.5;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"1 1", "1 2", "3 3", "2 1"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1.5;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"1 2", "1 3", "2 4", "3 4", "4 3", "4 2", "3 1", "2 1"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3.0;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"6 2", "2 1", "1 2", "1 4", "2 6", "5 6", "6 5"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 10.0;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"10000 3469", "9963 712", "9957 634", "9834 271", "9700 165", "9516 46", "8836 4", "1332 57", "229 628", "171 749", "52 1269", "30 1412", "7 4937", "35 8676", "121 9917", "2247 9960", "3581 9986", "6759 9995", "9486 9998", "9888 9890", "9914 9318", "9957 8206", "9998 6402"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4.8292483E7;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
