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

double dp[1005][1005][2];

double solve(int b, int w, int player)
{
    if(w == 0 || w + b == 0)
        return (player == 1);

    double &ret = dp[b][w][player];
    if(ret == ret)
    	return ret;

    double ans = 0;
    // Princess player 0
    if(player == 0)
    {
        ans += double(w) / double(b + w);
        if(b > 0)
            ans += double(b) / double(b + w) * (1 - solve(b - 1, w, 1));
    }
    // Dragon player 1
    else
    {
        ans += double(w) / double(b + w);
        if(b > 1)
            ans += double(b) / double(b + w) * double(b - 1) / double(b + w - 1) * (1 - solve(b - 2, w, 0));
        if(b > 0)
            ans += double(b) / double(b + w) * double(w) / double(b + w - 1) * (1 - solve(b - 1, w - 1, 0));
    }
    return ret = ans;
}

void cp()
{
    int b, w;
    cin >> w >> b;
    clr(dp, -1);
    double ans = solve(b, w, 0);
    dblout(10);
    cout << ans << endl;
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