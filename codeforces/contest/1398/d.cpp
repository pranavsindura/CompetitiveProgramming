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
int R, G, B;
ll r[205], g[205], b[205];
ll dp[205][205][205];
ll solve(int i, int j, int k)
{
    if(i == R && j == G && k == B)
        return 0;

    ll &ret = dp[i][j][k];
    if(~ret)
        return ret;
    ll ans = 0;
    if(i < R && j < G)
        ans = max(ans, r[i] * g[j] + solve(i + 1, j + 1, k));
    if(j < G && k < B)
        ans = max(ans, g[j] * b[k] + solve(i, j + 1, k + 1));
    if(i < R && k < B)
        ans = max(ans, r[i] * b[k] + solve(i + 1, j, k + 1));

    if(i < R)
        ans = max(ans, solve(i + 1, j, k));
    if(j < G)
        ans = max(ans, solve(i, j + 1, k));
    if(k < B)
        ans = max(ans, solve(i, j, k + 1));

    if(i < R && j < G)
        ans = max(ans, solve(i + 1, j + 1, k));
    if(j < G && k < B)
        ans = max(ans, solve(i, j + 1, k + 1));
    if(i < R && k < B)
        ans = max(ans, solve(i + 1, j, k + 1));

    if(i < R && j < G && k < B)
        ans = max(ans, solve(i + 1, j + 1, k + 1));

    return ret = ans;
}

void cp()
{
    cin >> R >> G >> B;
    for(int i = 0; i < R; i++)
        cin >> r[i];
    for(int i = 0; i < G; i++)
        cin >> g[i];
    for(int i = 0; i < B; i++)
        cin >> b[i];
    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);
    clr(dp, -1);
    cout << solve(0, 0, 0);
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