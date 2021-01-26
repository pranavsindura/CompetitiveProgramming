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
const int MAXN = 18;

int n;
double prob[MAXN + 2][MAXN + 2];
double dp[1 << MAXN];

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> prob[i][j];

    dp[0] = 1;

    for(int mask = 0; mask < 1 << n; mask++)
    {
        double cnt = __builtin_popcount(mask);
        cnt = n - cnt;
        double total_match = cnt * (cnt - 1) / 2;
        for(int j = 0; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(!((mask >> j) & 1) && !((mask >> k) & 1))
                {
                    // match between j and k
                    dp[mask | (1 << j)] += dp[mask] * prob[k][j] / total_match;
                    dp[mask | (1 << k)] += dp[mask] * prob[j][k] / total_match;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << dp[((1 << n) - 1) ^ (1 << i)] << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    dblout(10);
    while(t--)
    {
        cp();
    }
    return 0;
}