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
const ll mod = 1e8;
const int MAXN = 1e6 + 5;
ll dp[101][101][2][11];
int max_place[2];
ll rec(int ca, int cb, int last_placed, int count)
{
    if(ca < 0 || cb < 0)
        return 0;
    if(ca == 0 && cb == 0)
        return 1;

    ll &ret = dp[ca][cb][last_placed][count];
    if(~ret)
        return ret;

    ll ans = 0;

    if(count < max_place[last_placed])
        ans = (ans % mod + rec(ca - (last_placed == 0), cb - (last_placed == 1), last_placed, count + 1) % mod);

    ans = (ans % mod + rec(ca - (last_placed == 1), cb - (last_placed == 0), last_placed ^ 1, 1) % mod) % mod;

    return ret = ans;
}

void cp()
{
    int n, m;
    cin >> n >> m >> max_place[0] >> max_place[1];
    clr(dp, -1);
    ll ans = rec(n, m, 0, 0);
    cout << ans % mod;
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