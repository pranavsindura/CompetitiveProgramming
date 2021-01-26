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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int n, k, d;
ll dp[105][2];

void cp()
{
    cin >> n >> k >> d;
    ll ans = 0;
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++)
    {
        // We have not picked >= d yet, all edges must be < d
        // we add j to sum, previously needs to be i-j, and j cannot be d
        for(int j = 1; j < d; j++)
        {
            if(i - j >= 0)
                dp[i][0] = (dp[i][0] % mod + dp[i - j][0] % mod) % mod;
        }
        // We have picked d before, can pick any now
        // we will add j, previously needs to i-j
        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
                dp[i][1] = (dp[i][1] % mod + dp[i - j][1] % mod);
        }
        // We have not picked >= d before and we pick now
        for(int j = d; j <= k; j++)
        {
            if(i - j >= 0)
                dp[i][1] = (dp[i][1] % mod + dp[i - j][0] % mod) % mod;
        }
    }
    cout << dp[n][1];
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