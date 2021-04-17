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

int n, a, b;
int arr[15], dp[15][20][200];
vector<int> ops;
int solve(int i, int p, int q)
{
    if(i == n - 1) return 0;
    int &ret = dp[i][p][q];
    if(~ret) return ret;
    int ans = inf;
    int A = arr[i] - p * a - q * b;
    for(int x = 0; x <= 15; x++)
        for(int y = 0; y <= 15; y++)
            if(A - a * x - b * y * (i < n - 2) < 0)
                ans = min(ans, x + y + solve(i + 1, y, p + x));
    return ret = ans;
}

void trace(int i, int p, int q)
{
    if(i == n - 1) return;
    int ans = solve(i, p, q);
    int A = arr[i] - p * a - q * b;
    for(int x = 0; x <= 15; x++)
        for(int y = 0; y <= 15; y++)
            if(A - a * x - b * y * (i < n - 2) < 0)
            {
                int me = x + y + solve(i + 1, y, p + x);
                if(me == ans)
                {
                    for(int j = 0; j < x; j++) ops.push_back(i + 1);
                    for(int j = 0; j < y; j++) ops.push_back(i + 2);
                    trace(i + 1, y, p + x);
                    return;
                }
            }
}

void cp()
{
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;

    while(arr[0] >= 0)
        arr[0] -= b, arr[1] -= a, arr[2] -= b, ans++, ops.push_back(2);
    while(arr[n - 1] >= 0)
        arr[n - 1] -= b, arr[n - 2] -= a, arr[n - 3] -= b, ans++, ops.push_back(n - 1);
    clr(dp, -1);
    ans += solve(1, 0, 0);
    trace(1, 0, 0);
    cout << ans << endl;
    for(int x : ops)
        cout << x << " ";
    cout << endl;
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
