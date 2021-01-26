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

double dp[105][105][105];

int A, B, C;
double solve(int a, int b, int c)
{
    if(a == 100 || b == 100 || c == 100)
        return (a + b + c) - (A + B + C);

    double &ret = dp[a][b][c];
    if(fabs(ret + 1) > eps)
        return ret;

    double ans = 0;
    if(a > 0)
        ans += double(a) / double(a + b + c) * solve(a + 1, b, c);
    if(b > 0)
        ans += double(b) / double(a + b + c) * solve(a, b + 1, c);
    if(c > 0)
        ans += double(c) / double(a + b + c) * solve(a, b, c + 1);
    return ret = ans;
}

void cp()
{
    cin >> A >> B >> C;
    fix(9);
    clr(dp, -1);
    cout << solve(A, B, C) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}