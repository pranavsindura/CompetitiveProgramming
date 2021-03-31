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

class RandomSort
{
public:
    double getExpected(vector <int>);
};

int calc_inv(vector<int> &arr)
{
    vector<int> freq(9);
    int inv = 0;
    for(int x : arr)
    {
        for(int i = x + 1; i <= 8; i++) inv += freq[i];
        freq[x]++;
    }
    return inv;
}

map<vector<int>, int> comp;
int inv[40325];
double dp[40325][70];
double solve(vector<int> &arr, int sw)
{

    if(comp[arr] == 0) return sw;

    double &ret = dp[comp[arr]][sw];
    if(fabs(ret + 1) > eps) return ret;

    double ans = 0;
    double p = 1. / double(inv[comp[arr]]);
    for(int i = 0; i < sz(arr); i++)
        for(int j = 0; j < i; j++)
            if(arr[j] > arr[i])
            {
                swap(arr[j], arr[i]);
                ans += p * solve(arr, sw + 1);
                swap(arr[j], arr[i]);
            }
    return ret = ans;
}

double RandomSort::getExpected(vector <int> permutation)
{
    clr(inv, 0);
    clr(dp, -1);
    comp.clear();

    int n = sz(permutation);
    vector<int> perm(n);
    int ID = 0;
    iota(all(perm), 1);
    do
    {
        comp[perm] = ID;
        inv[ID] = calc_inv(perm);
        ID++;
    }
    while(next_permutation(all(perm)));
    return solve(permutation, 0);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, double p1)
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
    RandomSort *obj;
    double answer;
    obj = new RandomSort();
    clock_t startTime = clock();
    answer = obj->getExpected(p0);
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

    vector <int> p0;
    double p1;

    {
        // ----- test 0 -----
        int t0[] = {1, 3, 2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1.0;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {4, 3, 2, 1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4.066666666666666;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0.0;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {2, 5, 1, 6, 3, 4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 5.666666666666666;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }
    {
        // ----- test 3 -----
        int t0[] = {8, 7, 6, 5, 4, 3, 2, 1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 5.666666666666666;
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
