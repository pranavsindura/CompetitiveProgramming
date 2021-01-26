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
int a[205], b[205];
int dp[202][1 << 9];
int pos[205];
int solve(int i, int mask)
{
    if(i == n)
        return mask;

    int &ret = dp[i][mask];
    if(~ret)
        return ret;

    int ans = INT_MAX;
    for(int j = 0; j < m; j++)
    {
        int c = a[i] & b[j];
        int me = solve(i + 1, mask | c);
        if(me < ans)
            ans = me, pos[i] = j;
    }
    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];
    clr(dp, -1);
    cout << solve(0, 0) << endl;

    // int ans = INT_MAX;
    // // GREEDY
    // for(int mask = 0; mask < (1 << 9); mask++)
    // {
    //     int here = 0;
    //     for(int i = 0; i < n; i++)
    //     {
    //         int mn = 1 << 10;
    //         for(int j = 0; j < m; j++)
    //         {
    //             int c = a[i] & b[j];
    //             // same bits on as the mask
    //             // no different bits
    //             // 100110
    //             // 010010
    //             bool ok = true;
    //             int temp1 = mask, temp2 = c;
    //             while(temp2)
    //             {
    //                 if(temp2 & 1)
    //                 {
    //                     if(temp1 & 1)
    //                     {
    //                         //ok
    //                     }
    //                     else
    //                         ok = false;
    //                 }
    //                 temp2 /= 2, temp1 /= 2;
    //             }
    //             if(ok)
    //                 mn = min(mn, c);
    //         }
    //         here |= mn;
    //     }
    //     ans = min(ans, here);
    // }
    // cout << ans;
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