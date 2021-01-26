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
int dp[505][505];
int solve(int a, int b)
{
    if(a == b)
        return 0;
    if(a > b)
        swap(a, b);

    int &ret = dp[a][b];
    if(~ret)
        return ret;

    int ans = 1e7;
    for(int i = 1; i < a; i++)
        ans = min(ans, 1 + solve(i, b) + solve(a - i, b));
    for(int i = 1; i < b; i++)
        ans = min(ans, 1 + solve(a, i) + solve(a, b - i));
    return ret = ans;
}

void cp()
{
    int a, b;
    cin >> a >> b;
    clr(dp, -1);
    cout << solve(a, b);
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