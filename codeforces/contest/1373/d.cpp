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

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    ll without = 0;
    for(int i = 0; i < n; i += 2)
    {
        without += arr[i];
    }
    ll ans = without;
    vector<ll> left;
    for(int i = 1; i < n; i += 2)
        left.pb(arr[i] - arr[i - 1]);

    if(sz(left))
    {
        ll sum = left[0];
        ll dp[n + 1];
        dp[0] = left[0];
        for(int i = 1; i < sz(left); i++)
        {
            dp[i] = max(dp[i - 1] + left[i], 1LL * left[i]);
        }
        ll off1 = *max_element(dp, dp + sz(left));
        ans = max(ans, without + off1);
    }
    vector<int> right;
    for(int i = 1; i + 1 < n; i += 2)
        right.pb(arr[i] - arr[i + 1]);

    if(sz(right))
    {
        ll sum = right[0];
        ll dp[n + 1];
        dp[0] = right[0];
        for(int i = 1; i < sz(right); i++)
        {
            dp[i] = max(dp[i - 1] + right[i], 1LL * right[i]);
        }
        ll off2 = *max_element(dp, dp + sz(right));
        ans = max(ans, without + off2);
    }
    cout << ans << endl;
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