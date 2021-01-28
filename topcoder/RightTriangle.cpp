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

class RightTriangle
{
public:
    long long triangleCount(int, int, int, int, int);
};

long long RightTriangle::triangleCount(int places, int points, int a, int b, int c)
{
    if(places & 1)
        return 0;
    int n = places;
    ll m = points;

    set<int> st;
    for(int i = 0; i < n; i++)
        st.insert(i);

    vector<int> red;
    for(ll i = 0; i < m; i++)
    {
        int p = ((a * i * i) % n + (b * i) % n + c) % n;
        auto it = st.lower_bound(p);
        if(it == end(st))
            it = begin(st);
        red.pb(*it);
        st.erase(it);
    }

    sort(all(red));
    ll ans = 0;
    for(int i = 0; i < m; i++)
    {
        int y = (red[i] + n / 2) % n;
        if(binary_search(all(red), y))
            ans += max(m - 2, 0LL);
    }

    return ans / 2;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
    cout << "]" << endl;
    RightTriangle *obj;
    long long answer;
    obj = new RightTriangle();
    clock_t startTime = clock();
    answer = obj->triangleCount(p0, p1, p2, p3, p4);
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

    int p0;
    int p1;
    int p2;
    int p3;
    int p4;
    long long p5;

    {
        // ----- test 0 -----
        p0 = 9;
        p1 = 3;
        p2 = 0;
        p3 = 3;
        p4 = 0;
        p5 = 0ll;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 40;
        p1 = 3;
        p2 = 5;
        p3 = 0;
        p4 = 0;
        p5 = 1ll;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 4;
        p1 = 4;
        p2 = 16;
        p3 = 24;
        p4 = 17;
        p5 = 4ll;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 1000000;
        p1 = 47000;
        p2 = 0;
        p3 = 2;
        p4 = 5;
        p5 = 0ll;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 200000;
        p1 = 700;
        p2 = 123456;
        p3 = 789012;
        p4 = 345678;
        p5 = 6980ll;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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