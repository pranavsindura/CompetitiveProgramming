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

class DiceGames
{
public:
    vector<vector<ll>> dp;
    ll solve(int i, int lim, vector<int> &arr)
    {
        if(i == sz(arr))
            return 1;

        if(~dp[i][lim])
            return dp[i][lim];

        ll ans = 0;

        for(int j = 1; j <= arr[i] && j <= lim; j++)
            ans += solve(i + 1, j, arr);
        
        return dp[i][lim] = ans;
    }
    ll countFormations(vector<int> arr)
    {
        sort(arr.rbegin(), arr.rend());
        dp = vector<vector<ll>>(35, vector<ll>(35, -1));
        ll ans = solve(0, arr.front(), arr);
        return ans;
    }
};