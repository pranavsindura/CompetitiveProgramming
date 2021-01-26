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
int a[15], b[15], c[15], d[15];
int m;

int dp[11][1001][101];

int solve(int i, int dough_left, int stuff_left)
{
    if(i > m || dough_left <= 0)
        return 0;

    int &ret = dp[i][dough_left][stuff_left];
    if(~ret)
        return ret;

    int choice1 = 0, choice2 = 0;
    // continue making
    if(dough_left >= c[i] && stuff_left >= b[i])
        choice1 = d[i] + solve(i, dough_left - c[i], stuff_left - b[i]);
    // switch to next
    choice2 = solve(i + 1, dough_left, a[i + 1]);
    return ret = max(choice1, choice2);
}

void cp()
{
    int n, c0, d0;
    cin >> n >> m >> c0 >> d0;
    a[0] = 10, b[0] = 0, c[0] = c0, d[0] = d0;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    clr(dp, -1);
    int ans = solve(0, n, a[0]);
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