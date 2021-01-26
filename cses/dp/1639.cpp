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

string s, t;
int dp[MAXN][MAXN];

int solve(int i, int j)
{
    if(i == sz(s) && j == sz(t))
        return 0;

    if(i == sz(s))
        return sz(t) - j;
    if(j == sz(t))
        return sz(s) - i;

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    if(s[i] == t[j])
        return ret = solve(i + 1, j + 1);
    else
        return ret = 1 + min(
    {
        solve(i + 1, j + 1),
        solve(i, j + 1),
        solve(i + 1, j)
    });
}

void cp()
{
    cin >> s >> t;
    clr(dp, -1);
    cout << solve(0, 0);
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