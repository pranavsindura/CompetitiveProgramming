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

int dp[205][205][205];

int n, k;
string s, t;

int solve(int i, int op, int cnt)
{
    if(i == n)
        return 0;

    int &ret = dp[i][op][cnt];
    if(~ret)
        return ret;
    
    // dont change
    int ans = solve(i + 1, op, cnt + (s[i] == t[0])) + (s[i] == t[1] ? cnt : 0);
    // change to t[0]
    if(op < k)
        ans = max(ans, solve(i + 1, op + 1, cnt + 1));
    // change to t[1]
    if(op < k)
        ans = max(ans, cnt + solve(i + 1, op + 1, cnt + (t[0] == t[1])));
    return ret = ans;
}

void cp()
{
    cin >> n >> k >> s >> t;
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