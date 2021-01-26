#include<iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
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
double dp[1005][1005];
int n, s;
double solve(int i, int j)
{
    if(i > n || j > s)
        return 0;
    if(i == n && j == s)
        return 0;

    double &ret = dp[i][j];
    if(fabs(ret + 1) > eps)
        return ret;

    double p1 = ((n - i) * j * 1.0) / (n * s * 1.0);
    double p2 = (i * (s - j) * 1.0) / (n * s * 1.0);
    double p3 = ((n - i) * (s - j) * 1.0) / (n * s * 1.0);
    double p4 = (i * j * 1.0) / (n * s * 1.0);

    double ans = 1;
    ans += p1 * solve(i + 1, j);
    ans += p2 * solve(i, j + 1);
    ans += p3 * solve(i + 1, j + 1);
    ans /= (1 - p4);
    return ret = ans;
}

void cp()
{
    cin >> n >> s;
    clr(dp, -1);
    cout << setprecision(4) << fixed << solve(0, 0);
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