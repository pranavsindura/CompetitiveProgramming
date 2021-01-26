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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
int n, m;
ll dp[MAXN][101];
int arr[MAXN];

ll solve(int i, int last)
{
    if(i == n)
        return 1;
    if(arr[i] && abs(arr[i] - last) > 1)
        return 0;

    ll &ret = dp[i][last];
    if(~ret)
        return ret;

    ll ans = 0;

    if(arr[i])
        ans = solve(i + 1, arr[i]);
    else
    {
        if(last - 1 > 0)
            ans = (ans % mod + solve(i + 1, last - 1) % mod) % mod;
        if(last + 1 <= m)
            ans = (ans % mod + solve(i + 1, last + 1) % mod) % mod;
        ans = (ans % mod + solve(i + 1, last) % mod) % mod;
    }

    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 1)
    {
        if(arr[0])
            cout << 1;
        else
            cout << m;
        return;
    }

    clr(dp, -1);
    ll ans = 0;
    if(arr[0])
        ans = solve(1, arr[0]);
    else
        for(int j = 1; j <= m; j++)
            ans = (ans % mod + solve(1, j) % mod) % mod;
    cout << ans;
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