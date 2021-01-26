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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int dp[35][205];
int pos[205];
int cost[205][205];

int solve(int k, int n)
{
    if(~dp[k][n])
        return dp[k][n];
    int &ret = dp[k][n];
    if(k == 1)
    {
        return ret = cost[1][n];
    }
    else
    {
        ret = 1e7;
        for(int j = k - 1; j <= n - 1; j++)
        {
            ret = min(ret, solve(k - 1, j) + cost[j + 1][n]);
        }
        return ret;
    }
}
vector<pi> path;
void trace(int k, int n)
{
    if(k == 1)
    {
        path.pb({1, n});
    }
    else
    {
        int ans = solve(k, n);
        for(int j = k - 1; j <= n - 1; j++)
        {
            int me = solve(k - 1, j) + cost[j + 1][n];
            if(me == ans)
            {
                path.pb({j + 1, n});
                trace(k - 1, j);
                return;
            }
        }
    }
}

void cp()
{
    int n, k;
    int chain = 1;
    while(cin >> n >> k && n + k)
    {
        // Position on Number Line
        // int pos[n+1];
        for(int i = 0; i < n; i++)
            cin >> pos[i + 1];

        // cost[i][j]
        // If i want to build a warehouse that covers all restaurants in range [i, j],
        // I should build the warehouse at their median at pos[(i+j)/2]
        // cost[i][j] is the sum of the distances of all restaurants in range [i, j] from pos[(i+j)/2]
        // int cost[n + 1][n + 1];
        clr(cost, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                for(int m = i; m <= j; m++)
                {
                    cost[i][j] += abs(pos[m] - pos[(i + j) / 2]);
                }
            }
        }

        // dp[m][i]
        // Summing up the costs
        // Making the mth warehouse such that all restaurants from 1 to i get covered
        // Transition -
        // Let us find what is the cost of making m-1 restaurants
        // There can be many as you build m-1 restaurants in all ranges from [m-1, i-1]
        // m-1 can be built consecutively covering only first m-1 restaurants
        // m-1 can be built covering first m restaurants ....
        // m-1 can be built covering first i-2 restaurants....
        // m-1 can be built covering first i-1 restaurants....
        // We thus want to pick the minimum
        // Now let's say we built m-1 restaurants upto position j => [m-1, i-1]
        // Now we will add a new restaurant at position i, What will be the cost?
        // dp[m-1][j] + cost[j+1][i]
        // cost of covering restaurants from [j+1, i] is added
        // Base Case
        // If we make only 1 warehouse covering first i restaurants
        // Its dp[1][i] = cost[1][i]
        // int dp[k + 1][n + 1];
        clr(dp, -1);
        // for(int i = 1; i <= n; i++)
        //     dp[1][i] = cost[1][i];
        // for(int m = 2; m <= k; m++)
        // {
        //     for(int i = m; i <= n; i++)
        //     {
        //         dp[m][i] = 1e7;
        //         for(int j = m - 1; j <= i - 1; j++)
        //         {
        //             dp[m][i] = min(dp[m][i], dp[m - 1][j] + cost[j + 1][i]);
        //         }
        //     }
        // }
        // cout << dp[k][n] << endl;
        int ans = solve(k, n);
        path.clear();
        trace(k, n);
        cout << "Chain " << chain++ << endl;
        reverse(all(path));
        for(int i = 0; i < sz(path); i++)
        {
            cout << "Depot " << i + 1 << " at restaurant " << (path[i].ff + path[i].ss) / 2;

            if(path[i].ff == path[i].ss)
                cout << " serves restaurant " << path[i].ff << endl;
            else
                cout << " serves restaurants " << path[i].ff << " to " << path[i].ss << endl;
        }
        cout << "Total distance sum = " << ans << endl;
        cout << endl;
    }

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