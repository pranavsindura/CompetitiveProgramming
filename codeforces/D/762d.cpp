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
const ll inf = 1e15;
const int MAXN = 1e5 + 5;

int n;
int arr[3][MAXN];
ll dp[3][MAXN][2];
bool vis[3][MAXN][2];

ll solve(int i, int j, int st)
{
    if(j == n) return i == 2 && !st ? 0 : -inf;

    ll &ret = dp[i][j][st];
    if(vis[i][j][st]) return ret;
    vis[i][j][st] = true;
    ret = -inf;

    ll ans = -inf;
    if(st == 0)
    {
        ll sum = 0;
        for(int k = i; k >= 0; k--)
        {
            sum += arr[k][j];
            ans = max(ans, sum + solve(k, j + 1, 0));
        }
        sum = 0;
        for(int k = i; k < 3; k++)
        {
            sum += arr[k][j];
            ans = max(ans, sum + solve(k, j + 1, 0));
        }

        sum = arr[0][j] + arr[1][j] + 0LL + arr[2][j];
        if(i == 0 || i == 2)
            ans = max({ans, sum + solve(0, j + 1, 1), sum + solve(2, j + 1, 1)});
    }
    else
    {
        ll sum = arr[0][j] + arr[1][j] + 0LL + arr[2][j];
        ans = max(ans, sum + solve(0, j + 1, 1));
        ans = max(ans, sum + solve(2, j + 1, 1));
        ans = max(ans, sum + solve(0, j + 1, 0));
        ans = max(ans, sum + solve(2, j + 1, 0));
    }
    return ret = ans;
}

void cp()
{
    cin >> n;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    clr(vis, false);
    cout << solve(0, 0, 0) << endl;
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
