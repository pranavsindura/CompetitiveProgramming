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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

string a, b;

int dp[1005][1005][2][2];

int solve(int i, int j, int start, int count)
{
    if(i >= ln(a) || j >= ln(b))
        return 0;

    int &ret = dp[i][j][start][count];
    if(~ret)
        return ret;

    int ans = 0;
    if(start)
    {
        // if chars are same, i can add them to the subarray
        if(a[i] == b[j])
            ans = max(ans, 2 + solve(i + 1, j + 1, 1, count));
        // end here
        ans = max(ans, solve(i, j, 0, count));
    }
    else
    {
        // if chars are same, i can start a subarray
        if(a[i] == b[j] && count < 2)
            ans = max(ans, 2 + solve(i + 1, j + 1, 1, count + 1));
        // try combinations without starting
        ans = max(ans, solve(i + 1, j, 0, count));
        ans = max(ans, solve(i, j + 1, 0, count));
        ans = max(ans, solve(i + 1, j + 1, 0, count));
    }

    return ret = ans;
}

void cp()
{
    cin >> a >> b;
    reverse(all(b));
    clr(dp, -1);
    int ans = solve(0, 0, 0, 0);
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