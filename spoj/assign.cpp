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
bool like[21][21];

ll dp[1 << 20];
// ll dp[20][1<<20];

// ll solve(int i, int mask)
// {
//     if(i == n)
//         return 1;

//     ll &ret = dp[i][mask];
//     if(~ret)
//         return ret;

//     ll ans = 0;
//     for(int j = 0; j < n; j++)
//     {
//         if(((mask >> j) & 1) && like[i][j])
//         {
//             int nmask = mask & ~(1 << j);
//             ans += solve(i + 1, nmask);
//         }
//     }
//     return ret = ans;
// }

void cp()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> like[i][j];
    clr(dp, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 1 << n; j++)
        {
            if(__builtin_popcount(j) != i)
                continue;
            for(int mask = j; mask; mask &= (mask - 1))
            {
                int b = __builtin_ffs(mask) - 1;
                if(like[i][b + 1])
                {
                    int nmask = j & ~(1 << b);
                    dp[j] += dp[nmask];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
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