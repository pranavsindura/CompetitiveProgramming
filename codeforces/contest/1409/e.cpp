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

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<pi> arr(n);
    for(pi &x : arr)
        cin >> x.ff;
    for(pi &x : arr)
        cin >> x.ss;
    sort(all(arr), [&](pi a, pi b)
    {
        return a.ff < b.ff;
    });
    vector<int> dp(n);
    dp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        int lo = i, hi = n - 1;
        int extra = 0;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(arr[mid].ff <= arr[i].ff + k)
                extra = (mid - i + 1), lo = mid + 1;
            else
                hi = mid - 1;
        }
        dp[i] = max(dp[i], extra);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int lo = i, hi = n - 1;
        int pos = i;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(arr[mid].ff <= arr[i].ff + k)
                pos = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        int me = (pos - i + 1) + (pos + 1 < n ? dp[pos + 1] : 0);
        ans = max(ans, me);
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