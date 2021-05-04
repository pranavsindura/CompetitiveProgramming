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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

int dp[1005][2];
int solve(int i, int p, int n)
{
    if(i == n) return p;
    int &ret = dp[i][p];
    if(~ret) return ret;
    bool can = false;
    if(2 * i <= n)
        can |= solve(2 * i, p ^ 1, n) == p;
    if(i + 1 <= n)
        can |= solve(i + 1, p ^ 1, n) == p;
    return ret = (can ? p : p ^ 1);
}

void cp()
{
    int n;
    cin >> n;
    clr(dp, -1);
    int who = solve(1, 0, n);
    if(who == 0) cout << "Ivica" << endl;
    else cout << "Marica" << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
