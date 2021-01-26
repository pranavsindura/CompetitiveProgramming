#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
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
const double PI = acos(-1.0);
int n;
int pref_sum(int l, int r, int pref[])
{
    if(l > r)
        return 0;
    if(r < 0)
        return 0;
    l = max(l, 0);
    // cout<<l<<" "<<r<<endl;
    return (l ? pref[r] - pref[l - 1] : pref[r]);
}

int suff_sum(int l, int r, int suff[])
{
    if(l > r)
        return 0;
    r = min(r, n - 1);
    l = min(l, n - 1);
    return suff[l] - suff[r + 1];
}

void cp()
{
    int k;
    string s;
    cin >> n >> k >> s;
    vector<int> arr(n);
    int ones = 0;
    for(int i = 0; i < n; i++)
        arr[i] = s[i] - '0', ones += arr[i];
    int pref[n + 1], suff[n + 1];
    pref[0] = arr[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + arr[i];
    suff[n] = 0;
    for(int i = n - 1; i >= 0; i--)
        suff[i] = suff[i + 1] + arr[i];

    int ans = ones;
    int dp_pref[n + 1], dp_suff[n + 1], dp[n + 1];
    for(int i = 0; i < n; i++)
    {
        dp[i] = ones - arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        // cout << i << ": " << pref_sum(i - k + 1, i - 1, pref) << endl;
        if(i >= k)
            dp_pref[i] = dp_pref[i - k] + pref_sum(i - k + 1, i - 1, pref) + (arr[i] != 1);
        else
            dp_pref[i] = pref_sum(i - k + 1, i - 1, pref) + (arr[i] != 1);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        // cout << i << ": " << i + 1 << " " << i + k - 1 << " " << suff_sum(i + 1, i + k - 1, suff) << endl;
        if(i + k < n)
            dp_suff[i] = dp_suff[i + k] + suff_sum(i + 1, i + k - 1, suff) + (arr[i] != 1);
        else
            dp_suff[i] = suff_sum(i + 1, i + k - 1, suff) + (arr[i] != 1);
    }
    for(int i = 0; i < n; i++)
    {
        dp[i] = min({dp[i], dp_pref[i] + suff_sum(i + 1, n - 1, suff), dp_suff[i] + pref_sum(0, i - 1, pref), dp_pref[i] + dp_suff[i] - (arr[i] != 1)});
    }
    // for(int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n; i++)
    //     cout << dp_pref[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n; i++)
    //     cout << dp_suff[i] << " ";
    // cout<<endl;
    // for(int i = 0; i < n; i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    cout << *min_element(dp, dp + n) << endl;
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