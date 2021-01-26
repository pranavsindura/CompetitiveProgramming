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
#define watch(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

void cp()
{
    int n;
    cin >> n;
    vector<int> cost(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin >> cost[i];

    vector<string> arr(n + 1), pick(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    ll ans = 0;
    bool ok = true;
    ll dp[n + 1][2];
    //0 is normal
    //1 is reversed
    // clr(dp, -1);
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = cost[1];
    for(int i = 2; i <= n; i++)
    {
        string s = arr[i];
        string s_rev = arr[i];
        reverse(all(s_rev));


        string prev = arr[i - 1];
        string prev_rev = arr[i - 1];
        reverse(all(prev_rev));

        dp[i][0] = LLONG_MAX;
        dp[i][1] = LLONG_MAX;
        if(dp[i - 1][0] != LLONG_MAX)
        {
            if(prev <= s)
            {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            if(prev <= s_rev)
            {
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
            }
        }

        if(dp[i - 1][1] != LLONG_MAX)
        {
            if(prev_rev <= s)
            {
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }
            if(prev_rev <= s_rev)
            {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
            }
        }
        // watch(i);
        // watch(s);
        // watch(s_rev);
        // watch(prev);
        // watch(prev_rev);
        // watch(dp[i][0]);
        // watch(dp[i][1]);
        // cout << endl;
        //prev and s

        //prev and s_rev

        //prev_rev and s

        //prev_rev and s_rev
    }
    ans = min(dp[n][0], dp[n][1]);
    if(ans == LLONG_MAX)
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