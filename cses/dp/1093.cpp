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
const int MAXN = 500 * 500 + 5;
int n;
int total;
ll dp[125255];

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}
ll inv(ll a)
{
    return fpow(a, mod - 2);
}

void cp()
{
    cin >> n;
    total = n * (n + 1) / 2;
    if(total & 1)
    {
        cout << 0 << endl;
        return;
    }
    int target = total / 2;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = target; j >= 1; j--)
            if(j >= i)
                dp[j] = (dp[j] + dp[j - i]) % mod;

    ll ans = dp[target];
    ans = (ans * inv(2)) % mod;
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