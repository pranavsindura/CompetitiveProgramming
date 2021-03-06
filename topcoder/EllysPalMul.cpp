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
const int inf = 1LL << 30;
const int MAXN = 1e5 + 5;

class EllysPalMul
{
public:
    int getMin(int);
};

int palin(int L, int R, int X)
{
    ll P = L;
    while(R)
        P = P * 10 + R % 10, R /= 10;
    if(P % X == 0 && P / X >= 1 && P / X <= 1000000000)
        return P / X;
    else
        return inf;
}

int EllysPalMul::getMin(int X)
{
    int ans = inf;
    for(int i = 1; i <= 10000000; i++)
    {
    	ans = min(ans, palin(i, i, X));
    	ans = min(ans, palin(i, i/10, X));
    }
    if(ans == inf) ans = -1;
    return ans;
}

// ll A, T;
// vector<ll> po10;
// int dp[8][MAXN];
// bool solve(int i, int rem, int n)
// {
//     if(i == (n + 1) / 2)
//         return rem == 0;

//     int &ret = dp[i][rem];
//     if(~ret)
//         return ret;

//     bool ans = false;
//     for(int d = i == 0; d <= 9; d++)
//     {
//         ll a = (po10[i] * d) % A;
//         ll b = (po10[n - i - 1] * d) % A;
//         if(i != n - i - 1)
//             ans |= solve(i + 1, (a + b + rem) % A, n);
//         else
//             ans |= solve(i + 1, (a + rem) % A, n);
//     }
//     return ret = ans;
// }

// void trace(int i, int rem, int n)
// {
//     if(i == (n + 1) / 2)
//         return;

//     for(int d = i == 0; d <= 9; d++)
//     {
//         ll a = (po10[i] * d) % A;
//         ll b = (po10[n - i - 1] * d) % A;
//         if(i != n - i - 1)
//         {
//             bool me = solve(i + 1, (a + b + rem) % A, n);
//             if(me)
//             {
//                 T += po10[i] * d;
//                 T += po10[n - i - 1] * d;
//                 trace(i + 1, (a + b + rem) % A, n);
//                 return;
//             }
//         }
//         else
//         {
//             bool me = solve(i + 1, (a + rem) % A, n);
//             if(me)
//             {
//                 T += po10[i] * d;
//                 trace(i + 1, (a + rem) % A, n);
//                 return;
//             }
//         }
//     }
// }

// int EllysPalMul::getMin(int X)
// {
//     A = X;
//     po10.resize(16);
//     po10[0] = 1;
//     for(int i = 1; i < 16; i++)
//         po10[i] = po10[i - 1] * 10;

//     vector<int> candidate;
//     for(int i = 1; i <= 16; i++)
//     {
//         clr(dp, -1);
//         bool ok = solve(0, 0, i);
//         if(ok)
//         {
//             T = 0;
//             trace(0, 0, i);
//             if(T / A >= 1 && T / A <= 1000000000)
//                 candidate.pb(T / A);
//         }
//     }

//     sort(all(candidate));
//     if(candidate.empty())
//         return -1;
//     else
//         return candidate.front();
// }

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    EllysPalMul *obj;
    int answer;
    obj = new EllysPalMul();
    clock_t startTime = clock();
    answer = obj->getMin(p0);
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
        res = answer == p1;
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

    {
        // ----- test 0 -----
        p0 = 42;
        p1 = 6;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 121;
        p1 = 1;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 1337;
        p1 = 143;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 13;
        p1 = 38;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 100;
        p1 = -1;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        p0 = 21951;
        p1 = -1;
        all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        p0 = 16542;
        p1 = 1;
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
