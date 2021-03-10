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

int n;
int arr[505];
int dp[505][505][505];
int solve(int i, int a, int b)
{
    if(i == n) return 0;

    int &ret = dp[i][a][b];
    if(~ret) return ret;

    int ans = 0;
    // place a
    ans = max(ans, (arr[i] != a) + solve(i + 1, arr[i], b));
    // place b
    ans = max(ans, (arr[i] != b) + solve(i + 1, a, arr[i]));
    return ret = ans;
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    clr(dp, -1);
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
