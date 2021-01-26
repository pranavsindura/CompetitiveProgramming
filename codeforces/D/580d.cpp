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
const int MAXN = 1e6 + 5;

int n, m, k;
ll extra[20][20], val[20];
ll dp[1 << 18][20];
ll solve(int mask, int last)
{
    if(mask == 0)
        return 0;
    int cnt = __builtin_popcount(mask ^ ((1 << n) - 1));
    if(cnt == m)
        return 0;

    ll &ret = dp[mask][last];
    if(~ret)
        return ret;

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if((mask >> i) & 1)
        {
            ll me = (last == -1 ? 0 : extra[last][i]) + val[i];
            int nmask = mask & ~(1 << i);
            me += solve(nmask, i);
            ans = max(me, ans);
        }
    }
    return ret = ans;
}

void cp()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        extra[a][b] = c;
    }
    clr(dp, -1);
    cout << solve((1 << n) - 1, -1) << endl;
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