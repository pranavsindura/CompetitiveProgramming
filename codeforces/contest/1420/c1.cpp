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
const ll mod = 1e9 + 7;
const int MAXN = 3e5 + 5;

ll dp[MAXN][3];
ll arr[MAXN];
int n;

ll solve(int i, int type)
{
    if(i == n)
        return 0;

    ll &ret = dp[i][type];
    if(~ret)
        return ret;

    ll ans = INT_MIN;

    if(type == 0)
    {
        // did not start yet
        // choose to start with me
        ans = max(ans, arr[i] + solve(i + 1, 2));

        // choose  to ignore
        ans = max(ans, solve(i + 1, 0));
    }
    else if(type == 1)
    {
        // started and my turn to add +ve number
        // choose to add
        ans = max(ans, arr[i] + solve(i + 1, 2));
        // or skip
        ans = max(ans, solve(i + 1, 1));
    }
    else
    {
        // started and my turn to add -ve number
        // choose to add
        ans = max(ans, -arr[i] + solve(i + 1, 1));
        // or skip
        ans = max(ans, solve(i + 1, 2));
    }
    return ret = ans;
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    cout << solve(0, 0) << endl;
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