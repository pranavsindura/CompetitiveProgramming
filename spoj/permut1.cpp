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
const int MAXN = 12;
int n, k;
int dp[MAXN][1 << MAXN][100];
int solve(int i, int mask, int inv)
{
    if(i == n)
        return inv == k;

    int &ret = dp[i][mask][inv];
    if(~ret)
        return ret;

    int ans = 0;
    for(int j = 0; j < n; j++)
    {
        if((mask >> j) & 1)
        {
            int g = mask ^ ((1 << n) - 1);
            g &= ~((1 << j) - 1);
            int cnt = __builtin_popcount(g);
            int nmask = mask & ~(1 << j);
            ans += solve(i + 1, nmask, inv + cnt);
        }
    }
    return ret = ans;
}

void cp()
{
    cin >> n >> k;
    clr(dp, -1);
    cout << solve(0, ((1 << n) - 1), 0) << endl;
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