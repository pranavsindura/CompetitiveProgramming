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
vector<int> arr;
int dp[MAXN][8];
bool valid(int mask, int nmask)
{
    for(int i = 0; i < m - 1; i++)
    {
        int total = __builtin_popcount((mask >> i) & 3) + __builtin_popcount((nmask >> i) & 3);
        if(total % 2 == 0)
            return false;
    }
    return true;
}

int solve(int pos, int mask)
{
    if(pos == n)
        return 0;

    int &ret = dp[pos][mask];
    if(~ret)
        return ret;

    int res = INT_MAX;
    for(int nmask = 0; nmask < (1 << m); nmask++)
    {
        if(valid(mask, nmask))
        {
            int me = __builtin_popcount(arr[pos] ^ nmask);
            res = min(res, me + solve(pos + 1, nmask));
        }
    }
    return ret = res;
}

void cp()
{
    cin >> n >> m;
    vector<string> rows(n);
    for(string &x : rows)
        cin >> x;

    if(n >= 4 && m >= 4)
    {
        cout << -1;
        return;
    }

    if(n < m)
    {
        arr = vector<int>(m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                arr[j] |= ((rows[i][j] - '0') << i);
        swap(n, m);
    }
    else
    {
        arr = vector<int>(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                arr[i] |= ((rows[i][j] - '0') << (m - j - 1));
    }
    clr(dp, -1);
    int ans = INT_MAX;
    for(int nmask = 0; nmask < (1 << m); nmask++)
        ans = min(ans, solve(0, nmask));
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