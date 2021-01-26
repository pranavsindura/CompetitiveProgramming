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
const ll inf = 2e18;
const int MAXN = 1e5 + 5;

/*
	Build masks
	sort based on k[i]
	bitmask + dp
	n * 2^m
	too tight?
*/

int n, m;
ll b;
vector<vector<int>> arr;
ll dp[1 << 20];

void cp()
{
    cin >> n >> m >> b;
    arr.assign(n, vector<int>(3));
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> arr[i][0] >> arr[i][1] >> k;
        int mask = 0;
        for(int j = 0, x; j < k; j++)
            cin >> x, x--, mask |= (1 << x);
        arr[i][2] = mask;
    }

    sort(all(arr), [&](vector<int> x, vector<int> y)
    {
        return x[1] < y[1];
    });

    for(int i = 0; i < 1 << m; i++)
        dp[i] = inf;

    dp[0] = 0;
    
    for(int i = n - 1; i >= 0; i--)
        for(int mask = 0; mask < 1 << m; mask++)
            if(mask & arr[i][2])
            {
                int nmask = mask & ~(arr[i][2]);
                ll val = arr[i][0];
                if(nmask == 0)
                    val += arr[i][1] * b;
                dp[mask] = min(dp[mask], val + dp[nmask]);
            }

    ll ans = dp[(1 << m) - 1];
    if(ans == inf) ans = -1;
    cout << ans << endl;
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

