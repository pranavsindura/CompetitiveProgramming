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
const int inf = 1e6;
const int MAXN = 1e3 + 5;
int n, m;
int A[MAXN], B[MAXN];
int dp[MAXN][MAXN];
int solve(int i, int j)
{
    if(i == n || j == m)
        return n - i + m - j;

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    int ans = inf;
    // pick
    if(A[i] == B[j])
        ans = min(ans, solve(i + 1, j + 1));
    else
        ans = min(ans, 1 + solve(i + 1, j + 1));
    // skip
    ans = min(ans, 1 + solve(i + 1, j));
    ans = min(ans, 1 + solve(i, j + 1));
    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < m; i++)
        cin >> B[i];
    clr(dp, -1);
    cout << solve(0, 0) << endl;
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

