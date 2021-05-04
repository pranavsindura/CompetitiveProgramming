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

class HeightRound
{
public:
    vector <int> getBestRound(vector <int>);
};

vector <int> HeightRound::getBestRound(vector <int> heights)
{
    sort(all(heights));
    int n = sz(heights);

    for(int D = 0; D <= 1000; D++) // can also BS
    {
        vector<int> L, R;
        vector<int> taken(n);
        int idx = 0;
        bool ok = true;
        while(idx + 1 < n && ok)
        {
            int A = heights[idx];
            int p = idx + 1, q = -1;
            while(p < n && heights[p] <= A + D)
                q = p, p++;
            if(~q)
            {
                taken[q] = 1;
                R.push_back(heights[q]);
            }
            else
                ok = false;
            idx = q;
        }
        for(int i = 0; i < n; i++) if(!taken[i]) L.push_back(heights[i]);
        while(!R.empty()) L.push_back(R.back()), R.pop_back();
        for(int i = 0; i < n; i++)
            ok &= abs(L[i] - L[(i + 1) % n]) <= D;
        if(ok) return L;
    }
    return {-1};
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, vector <int> p1)
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
    cout << "}";
    cout << "]" << endl;
    HeightRound *obj;
    vector <int> answer;
    obj = new HeightRound();
    clock_t startTime = clock();
    answer = obj->getBestRound(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p1.size()) > i; ++i)
        {
            if (i > 0)
            {
                cout << ",";
            }
            cout << p1[i];
        }
        cout << "}" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(answer.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "}" << endl;
    if (hasAnswer)
    {
        if (answer.size() != p1.size())
        {
            res = false;
        }
        else
        {
            for (int i = 0; int(answer.size()) > i; ++i)
            {
                if (answer[i] != p1[i])
                {
                    res = false;
                }
            }
        }
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

    {
        // ----- test 0 -----
        int t0[] = {1, 2, 3, 4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 2, 4, 3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {1000, 500, 1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 500, 1000};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {1, 3, 4, 5, 7};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 3, 5, 7, 4};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1, 2, 4, 6, 8, 10, 9, 7, 5, 3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
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