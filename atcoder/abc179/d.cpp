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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 998244353;
const int MAXN = 2e5 + 5;

ll dp[MAXN], suff[MAXN];

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<pi> arr(k);
    for(pi &x : arr)
        cin >> x.ff >> x.ss;
    dp[n] = suff[n] = 1;
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = 0; j < k; j++)
        {
            int l = i + arr[j].ff;
            int r = i + arr[j].ss;
            r = min(r, n);
            if(l <= r)
                dp[i] = (dp[i] + suff[l] - suff[r + 1] + mod) % mod;
        }
        suff[i] = (dp[i] + suff[i + 1]) % mod;
    }
    cout << dp[1] << endl;
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