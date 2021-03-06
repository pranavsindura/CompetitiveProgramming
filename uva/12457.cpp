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
int n;
double p;
double dp[50][30];
double solve(int i, int win)
{
    if(i == 2 * n - 1)
        return win == n;
    if(win == n)
        return 1;

    double &ret = dp[i][win];
    if(fabs(ret + 1) > eps)
        return ret;

    double ans = 0;
    ans += p * solve(i + 1, win + 1);
    ans += (1 - p) * solve(i + 1, win);
    return ret = ans;
}

void cp()
{
    cin >> n >> p;
    clr(dp, -1);
    cout << solve(0, 0) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    cout << setprecision(2) << fixed;
    while(t--)
    {
        cp();
    }
    return 0;
}