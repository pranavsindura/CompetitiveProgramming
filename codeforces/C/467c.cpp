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
const int MAXN = 5e3 + 5;
ll inf = 1e14;
ll arr[MAXN], pref[MAXN], dp[MAXN][MAXN];
int n, m, k;

ll sum(int l, int r)
{
    return (l ? pref[r] - pref[l - 1] : pref[r]);
}

ll solve(int i, int k)
{
    if(i > n)
        return -inf;
    if(i == n)
        return (k == 0 ? 0 : -inf);
    if(k == 0)
        return 0;

    ll &ret = dp[i][k];
    if(~ret)
    	return ret;

    ll choice1 = solve(i + 1, k);
    ll choice2 = -inf;
    if(i + m <= n)
        choice2 = sum(i, i + m - 1) + solve(i + m, k - 1);
    return ret = max(choice1, choice2);
}


void cp()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    pref[0]  = arr[0];
    for(int i = 1; i < n; i++)
        pref[i] += pref[i - 1] + arr[i];
    clr(dp, -1);
    ll ans = solve(0, k);
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