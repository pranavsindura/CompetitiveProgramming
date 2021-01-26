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
const int inf = 100000;
const int MAXN = 1e5 + 5;

int n;
int arr[505];
int dp[505][505][505];
int solve(int i, int prev, int change)
{
    if(i == n)
        return 0;

    int &ret = dp[i][prev][change];
    if(~ret) return ret;

    int ans = inf;
    if(arr[i] >= prev)
        ans = min(ans, solve(i + 1, arr[i], change));
    if(arr[i] > change && change >= prev)
        ans = min(ans, 1 + solve(i + 1, change, arr[i]));
    return ret = ans;
}

void cp()
{
    int x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 500; j++)
            for(int k = 0; k <= 500; k++)
                dp[i][j][k] = -1;
    int ans = solve(0, 0, x);
    if(ans >= inf) ans = -1;
    cout << ans << endl;
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

