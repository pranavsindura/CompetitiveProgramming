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
const int MAXN = 2e5 + 5;
int n;
int arr[MAXN];
int dp[MAXN][2];
int solve(int i, bool turn)
{
    if(i == n)
        return 0;

    int &ret = dp[i][turn];
    if(~ret)
        return ret;

    int ans;
    if(turn == 0)
    {
        // my turn
        // kill 1 boss
        ans = solve(i + 1, turn ^ 1);
        // kill 2
        if(i + 1 < n)
            ans = min(ans, solve(i + 2, turn ^ 1));
    }
    else
    {
        // friends turn
        // kill 1 boss
        ans = (arr[i] == 1) + solve(i + 1, turn ^ 1);
        // kill 2 boss
        if(i + 1 < n)
            ans = min(ans, (arr[i] == 1) + (arr[i + 1] == 1) + solve(i + 2, turn ^ 1));
    }

    return ret = ans;
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;
    cout << solve(0, 1) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}