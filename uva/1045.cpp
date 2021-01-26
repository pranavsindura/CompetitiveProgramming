#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.endpos()
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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int inf = 1e6 + 5;
using namespace std;

int n, tc;
vector<pi> arr, endpos;
int dp[15][1 << 15];
int dist(int i, int j)
{
    return abs(arr[i].ff - endpos[j].ff) + abs(arr[i].ss - endpos[j].ss);
}

int solve(int i, int mask)
{
    if(i == n)
        return 0;

    int &ret = dp[i][mask];
    if(~ret)
        return ret;

    int ans = inf;
    for(int j = 0; j < n; j++)
    {
        if(!((mask >> j) & 1))
        {
            int me = dist(i, j) + solve(i + 1, mask | (1 << j));
            ans = min(ans, me);
        }
    }
    return ret = ans;
}

void cp()
{
    arr.resize(n);
    endpos.resize(n);
    for(pi &x : arr)
        cin >> x.ff >> x.ss, x.ff--, x.ss--;
    int ans = inf;
    // Row
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            endpos[j] = {i, j};
        clr(dp, -1);
        ans = min(ans, solve(0, 0));
    }
    // Column
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            endpos[j] = {j, i};
        clr(dp, -1);
        ans = min(ans, solve(0, 0));
    }
    // Diag 1
    for(int j = 0; j < n; j++)
        endpos[j] = {j, j};
    clr(dp, -1);
    ans = min(ans, solve(0, 0));
    // Diag 2
    for(int j = 0; j < n; j++)
        endpos[j] = {j, n - j - 1};
    clr(dp, -1);
    ans = min(ans, solve(0, 0));
    cout << "Board " << tc << ": " << ans << " moves required.\n";
}

int main()
{
    FASTIO;
    while(cin >> n && n)
    {
        tc++;
        cp();
        cout << endl;
    }
    return 0;
}