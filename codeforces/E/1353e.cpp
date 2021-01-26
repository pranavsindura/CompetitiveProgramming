#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
int pref_sum(int l, int r, vector<int> &pref)
{
    if(l > r)
        return 0;
    return (l ? pref[r] - pref[l - 1] : pref[r]);
}
int calc(int n, string s, int k)
{
    vector<int> pref;
    vector<int> dp(n + 1, INT_MAX);

    pref.pb(s[0] == '1');
    for(int i = 1; i < n; i++)
        pref.pb(pref.back() + (s[i] == '1'));
    for(int i = 0; i < n; i++)
    {
        // garland ending at i
        // two choices

        // connect to previous garland
        // make current number 1
        // make all numbers in range [i-k+1, i-1] := 0
        if(i - k >= 0)
        {
            int cost = (s[i] == '0') + pref_sum(i - k + 1, i - 1, pref);
            dp[i] = min(dp[i], dp[i - k] + cost);
        }
        // start new from here
        // make current number 1
        // make all numbers in range [0, i-1] := 0
        int cost = (s[i] == '0') + pref_sum(0, i - 1, pref);
        dp[i] = min(dp[i], cost);
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        // end garland at position i
        // make all numbers in range [i+1, n-1] := 0
        ans = min(ans, dp[i] + pref_sum(i + 1, n - 1, pref));
    }
    // Also turning off all lamps is a solution
    // Try that too
    return min(ans, pref_sum(0, n - 1, pref));
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << calc(n, s, k) << endl;
    }
    return 0;
}