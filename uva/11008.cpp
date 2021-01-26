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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int inf = 1e6 + 5;
using namespace std;
int n, m;
int cover[16][16];
int dp[1 << 16];
vector<pi> arr;
void build()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int a = arr[i].ss - arr[j].ss;
            int b = arr[j].ff - arr[i].ff;
            int c = -a * arr[i].ff - b * arr[i].ss;
            int mask = 0;
            for(int k = 0; k < n; k++)
                if((a * arr[k].ff + b * arr[k].ss + c) == 0)
                    mask |= (1 << k);
            cover[i][j] = mask;
        }
    }
}

int solve(int mask)
{
    if(mask == 0)
        return 0;
    if(__builtin_popcount(mask ^ ((1 << n) - 1)) >= m)
        return 0;

    int &ret = dp[mask];
    if(~ret)
    	return ret;

    int ans = inf;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(((mask >> i) & 1) || ((mask >> j) & 1))
                ans = min(ans, 1 + solve(mask & ~cover[i][j]));
        }
    }
    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    arr.resize(n);
    for(pi &x : arr)
        cin >> x.ff >> x.ss;
    build();
    clr(dp, -1);
    cout << solve((1 << n) - 1) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        if(i > 1)
            cout << endl;
        cout << "Case #" << i << ":\n";
        cp();
    }
    return 0;
}