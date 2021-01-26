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
int n, m;
string s, t;
int dp[2005][2005][3];
int solve(int i, int j, int status)
{
    if(j == m)
        return 0;
    if(i == n)
        return m - j;

    int &ret = dp[i][j][status];
    if(~ret)
        return ret;

    int c1 = 1e7, c2 = 1e7;
    if(status == 0) // did not start yet
    {
        // not started yet
        c1 = solve(i + 1, j, 0);
        // choose to start
        // choose to fix or dont fix
        c2 = min(
        {
            (s[i] != t[j]) + solve(i + 1, j + 1, 1),
            1 + solve(i, j + 1, 2),
            1 + solve(i + 1, j, 2)
        });
    }
    else if(status == 1) // started and fixed
    {
        // continue fixing
        c1 = (s[i] != t[j]) + solve(i + 1, j + 1, 1);
        // choose to end
        c2 = m - j;
    }
    else if(status == 2) // started but did not fix
    {
        // choose to fix or dont fix
        c1 = min(
        {
            (s[i] != t[j]) + solve(i + 1, j + 1, 1),
            1 + solve(i, j + 1, 2),
            1 + solve(i + 1, j, 2)
        });
        // choose to end
        c2 = m - j;
    }
    return ret = min(c1, c2);
}

void cp()
{
    cin >> s >> t;
    n = ln(s), m = ln(t);
    clr(dp, -1);
    cout << solve(0, 0, 0) << endl;
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