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

class FavouriteDigits
{
public:
    long long findNext(long long, int, int, int, int);
};

vector<int> num;
int d1, d2, c1, c2;
int dp[16][17][17][2][2];
bool solve(int i, int count1, int count2, int tight, int nz)
{
    if(i == 16) return count1 >= c1 && count2 >= c2;
    int &ret = dp[i][count1][count2][tight][nz];
    if(~ret) return ret;
    bool ans = false;
    if(tight) // prev all digits were same as N
    {
        int ncount1 = count1, ncount2 = count2, nnz = nz;
        if(num[i] == d1 && (d1 > 0 || nz)) ncount1++;
        if(num[i] == d2 && (d2 > 0 || nz)) ncount2++;
        nnz |= num[i] > 0;
        // also make same
        ans |= solve(i + 1, ncount1, ncount2, 1, nnz);
        // increase
        for(int d = num[i] + 1; d < 10; d++)
        {
            ncount1 = count1, ncount2 = count2, nnz = nz;
            if(d == d1 && (d1 > 0 || nz)) ncount1++;
            if(d == d2 && (d2 > 0 || nz)) ncount2++;
            nnz |= d > 0;
            ans |= solve(i + 1, ncount1, ncount2, 0, nnz);
        }
    }
    else // already have >
    {
        // can place anything
        for(int d = 0; d < 10; d++)
        {
            int ncount1 = count1, ncount2 = count2, nnz = nz;
            if(d == d1 && (d1 > 0 || nz)) ncount1++;
            if(d == d2 && (d2 > 0 || nz)) ncount2++;
            nnz |= d > 0;
            ans |= solve(i + 1, ncount1, ncount2, 0, nnz);
        }
    }
    return ret = ans;
}

ll ANS;
void trace(int i, int count1, int count2, int tight, int nz)
{
    if(i == 16) return;
    if(tight) // prev all digits were same as N
    {
        int ncount1 = count1, ncount2 = count2, nnz = nz;
        if(num[i] == d1 && (d1 > 0 || nz)) ncount1++;
        if(num[i] == d2 && (d2 > 0 || nz)) ncount2++;
        nnz |= num[i] > 0;
        // also make same
        if(solve(i + 1, ncount1, ncount2, 1, nnz))
        {
            ANS = ANS * 10 + num[i];
            trace(i + 1, ncount1, ncount2, 1, nnz);
            return;
        }
        // increase
        for(int d = num[i] + 1; d < 10; d++)
        {
            ncount1 = count1, ncount2 = count2, nnz = nz;
            if(d == d1 && (d1 > 0 || nz)) ncount1++;
            if(d == d2 && (d2 > 0 || nz)) ncount2++;
            nnz |= d > 0;

            if(solve(i + 1, ncount1, ncount2, 0, nnz))
            {
                ANS = ANS * 10 + d;
                trace(i + 1, ncount1, ncount2, 0, nnz);
                return;
            }
        }

    }
    else // already have >
    {
        // can place anything
        for(int d = 0; d < 10; d++)
        {
            int ncount1 = count1, ncount2 = count2, nnz = nz;
            if(d == d1 && (d1 > 0 || nz)) ncount1++;
            if(d == d2 && (d2 > 0 || nz)) ncount2++;
            nnz |= d > 0;

            if(solve(i + 1, ncount1, ncount2, 0, nnz))
            {
                ANS = ANS * 10 + d;
                trace(i + 1, ncount1, ncount2, 0, nnz);
                return;
            }
        }
    }
}

long long FavouriteDigits::findNext(long long N, int digit1, int count1, int digit2, int count2)
{
    ::d1 = digit1, ::d2 = digit2;
    ::c1 = count1, ::c2 = count2;
    num.clear();
    while(N) num.push_back(N % 10), N /= 10;
    while(sz(num) < 16) num.push_back(0);
    reverse(all(num));
    clr(dp, -1);
    solve(0, 0, 0, 1, 0);
    ANS = 0;
    trace(0, 0, 0, 1, 0);
    return ANS;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
    cout << "]" << endl;
    FavouriteDigits *obj;
    long long answer;
    obj = new FavouriteDigits();
    clock_t startTime = clock();
    answer = obj->findNext(p0, p1, p2, p3, p4);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p5 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p5;
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

    long long p0;
    int p1;
    int p2;
    int p3;
    int p4;
    long long p5;

    {
        // ----- test 0 -----
        p0 = 47ll;
        p1 = 1;
        p2 = 0;
        p3 = 2;
        p4 = 0;
        p5 = 47ll;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 47ll;
        p1 = 5;
        p2 = 0;
        p3 = 9;
        p4 = 1;
        p5 = 49ll;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 47ll;
        p1 = 5;
        p2 = 0;
        p3 = 3;
        p4 = 1;
        p5 = 53ll;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 47ll;
        p1 = 2;
        p2 = 1;
        p3 = 0;
        p4 = 2;
        p5 = 200ll;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 123456789012345ll;
        p1 = 1;
        p2 = 2;
        p3 = 2;
        p4 = 4;
        p5 = 123456789012422ll;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        p0 = 92ll;
        p1 = 1;
        p2 = 1;
        p3 = 0;
        p4 = 0;
        p5 = 100ll;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }
    {
        // ----- test 5 -----
        // {547, 0, 2, 5, 1}
        p0 = 547LL;
        p1 = 0;
        p2 = 2;
        p3 = 5;
        p4 = 1;
        p5 = 1005ll;
        all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, true, p5) && all_right;
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