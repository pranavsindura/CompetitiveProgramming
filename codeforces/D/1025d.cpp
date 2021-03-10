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
const int MAXN = 700 + 5;

int n;
array<int, MAXN> arr;

int dp[MAXN][MAXN][2];

bool solve(int l, int r, bool p)
{
    if(l > r) return true;

    int &ret = dp[l][r][p];
    if(~ret) return ret;

    int x = p ? arr[r + 1] : arr[l - 1];

    bool ok = false;
    for(int i = l; i <= r; i++)
        if(__gcd(arr[i], x) > 1)
            ok |= solve(l, i - 1, 1) & solve(i + 1, r, 0);
    return ret = ok;
}

void cp()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            if(i > j)
                dp[i][j] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            for(int p = 0; p <= 1; p++)
                for(int k = i; k <= j; k++)
                {
                    int x = p ? arr[j + 1] : arr[i - 1];
                    if(__gcd(x, arr[k]) > 1)
                        dp[i][j][p] |= dp[i][k - 1][1] & dp[k + 1][j][0];
                }

    bool ok = false;
    for(int i = 1; i <= n; i++)
        ok |= dp[0][i - 1][1] & dp[i + 1][n][0];

    cout << (ok ? "Yes\n" : "No\n");
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
