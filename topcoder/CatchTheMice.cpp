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
const double eps = 1e-12;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

class CatchTheMice
{
public:
    double largestCage(vector <int>, vector <int>, vector <int>, vector <int>);
};

double CatchTheMice::largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv)
{
    int n = sz(xp);
    double lo = 0, hi = 1e9;
    for(int itr = 0; itr < 200; itr++)
    {
        double mid = (lo + hi) / 2;
        double atmost = DBL_MAX, atleast = -eps;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                double down, up;
                if(xv[i] != xv[j])
                {
                    down = (mid - (xp[i] - xp[j])) / double(xv[i] - xv[j]);
                    up = (-mid - (xp[i] - xp[j])) / double(xv[i] - xv[j]);
                    if(up > down) swap(up, down);
                }
                else
                {
                    down = abs(xp[i] - xp[j]) < mid ? DBL_MAX : -DBL_MAX;
                    up = abs(xp[i] - xp[j]) < mid ? -DBL_MAX : DBL_MAX;
                }
                // cout << i << "," << j << " x " << up << " " << down << endl;
                atmost = min(down, atmost);
                atleast = max(up, atleast);

                if(yv[i] != yv[j])
                {
                    down = (mid - (yp[i] - yp[j])) / double(yv[i] - yv[j]);
                    up = (-mid - (yp[i] - yp[j])) / double(yv[i] - yv[j]);
                    if(up > down) swap(up, down);
                }
                else
                {
                    down = abs(yp[i] - yp[j]) < mid ? DBL_MAX : -DBL_MAX;
                    up = abs(yp[i] - yp[j]) < mid ? -DBL_MAX : DBL_MAX;
                }
                // cout << i << "," << j << " y " << up << " " << down << endl;
                atmost = min(down, atmost);
                atleast = max(up, atleast);
            }
        // dbg(atleast);
        // dbg(atmost);
        if(atleast < atmost) hi = mid;
        else lo = mid;
    }
    return lo;
}

/*
down = (mid - (yp[i] - yp[j])) / (yv[i] - yv[j]);
up = (-mid - (yp[i] - yp[j])) / (yv[i] - yv[j]);
atmost = min(down, atmost);
atleast = max(atleast, up);
*/
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, double p4)
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
    cout << "}";
    cout << "]" << endl;
    CatchTheMice *obj;
    double answer;
    obj = new CatchTheMice();
    clock_t startTime = clock();
    answer = obj->largestCage(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
    double p4;

    {
        // ----- test 0 -----
        int t0[] = {0, 10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0, 10};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {10, -10};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {0, 0};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 10.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {0, 10, 0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0, 0, 10};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1, -6, 4};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {4, 5, -4};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 3.0;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {50, 10, 30, 15};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {-10, 30, 20, 40};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {-5, -10, -15, -5};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {40, -10, -1, -50};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 40.526315789473685;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {0, 10, 10, 0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0, 0, 10, 10};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1, 0, -1, 0};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {0, 1, 0, -1};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 10.0;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {13, 50, 100, 40, -100};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {20, 20, -150, -40, 63};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {4, 50, 41, -41, -79};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {1, 1, 1, 3, -1};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 212.78688524590163;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        int t0[] = {0, 10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0, 0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {5, 5};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {3, 3};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 10.0;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 6 -----
        int t0[] = {-49, -463, -212, -204, -557, -67, -374, -335, -590, -4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {352, 491, 280, 355, 129, 78, 404, 597, 553, 445};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {-82, 57, -23, -32, 89, -72, 27, 17, 100, -94};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {-9, -58, 9, -14, 56, 75, -32, -98, -81, -43};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 25.467532467532468;
        all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) && all_right;
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
