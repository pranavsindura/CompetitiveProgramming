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
int n, x;
int c[105];
ll dp[MAXN];
ll solve(int val)
{
    if(val == 0)
        return 0;

    ll &ret = dp[val];
    if(~ret)
    	return ret;

    ll ans = INT_MAX;
    for(int i = 0; i < n; i++)
        if(c[i] <= val)
            ans = min(ans, 1 + solve(val - c[i]));
    return ret = ans;
}

void cp()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    clr(dp, -1);
    ll ans = solve(x);
    if(ans >= INT_MAX)
    	ans = -1;
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