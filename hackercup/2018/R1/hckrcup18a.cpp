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
const int MAXN = 1e3 + 5;
int n;
vector<string> arr(3);
ll dp[MAXN][3];
ll solve(int j, int i)
{
    if(j == n)
        return i == 2;

    ll &ret = dp[j][i];
    if(~ret)
        return ret;

    ll ans = 0;
    if((j + 1) & 1)
    {
        // I must be at some border 0/2
        // I need to go to middle
        if(i == 0)
        {
            // I am at top
            if(arr[i][j] == '.' && arr[i + 1][j] == '.')
                ans = solve(j + 1, 1);
        }
        else
        {
            // I am at bottom
            if(arr[i][j] == '.' && arr[i - 1][j] == '.')
                ans = solve(j + 1, 1);
        }
    }
    else
    {
        // I am in middle, i can go up or down
        if(arr[i][j] == '.' && arr[i + 1][j] == '.')
            ans += solve(j + 1, 2);
        if(arr[i][j] == '.' && arr[i - 1][j] == '.')
            ans += solve(j + 1, 0);
    }
    ans %= mod;
    return ret = ans;
}

void cp()
{
    cin >> n;
    cin >> arr[0] >> arr[1] >> arr[2];
    clr(dp, -1);
    cout << solve(0, 0) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}