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
const int MAXN = 3e4 + 5;

int gems_at[MAXN], collect[MAXN];

int dp[MAXN][2 * 305];

int n, d;

int solve(int i, int lastjump)
{
    if(i >= MAXN)
        return 0;
    int off = lastjump - d + 300;
    if(~dp[i][off])
        return dp[i][off];
    // dbg(i);
    int mx = gems_at[i];
    if(lastjump - 1 > 0)
        mx = max(mx, gems_at[i] + solve(i + lastjump - 1, lastjump - 1));
    mx = max(mx, gems_at[i] + solve(i + lastjump, lastjump));
    mx = max(mx, gems_at[i] + solve(i + lastjump + 1, lastjump + 1));
    return dp[i][off] = mx;
}

void cp()
{
    cin >> n >> d;
    for(int i = 0, x = 0; i < n; i++)
        cin >> x, gems_at[x]++;
    clr(dp, -1);
    cout << solve(d, d) << endl;
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