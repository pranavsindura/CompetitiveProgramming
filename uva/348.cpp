#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
using namespace std;
const double PI = acos(-1.0);
vector<pair<ll, ll>> mt(15);
vector<vector<pair<string, ll>>> dp(15, vector<pair<string, ll>>(15, {"", -1}));
int n;
pair<string, ll> solve(int i, int j)
{
    if(i == j)
    {
        return {"A" + to_string(i + 1), 0};
    }
    if(j - i + 1 == 2)
    {
        return {"(A" + to_string(i + 1) + " x A" + to_string(j + 1) + ")", mt[i].ff *mt[i].ss *mt[j].ss};
    }
    else
    {
        if(dp[i][j].ss != -1)
            return dp[i][j];
        pair<string, ll> opt;
        ll mi = LLONG_MAX;
        for(int k = i; k < j; k++)
        {
            pair<string, ll> l = solve(i, k);
            pair<string, ll> r = solve(k + 1, j);
            ll cost = l.ss + r.ss + mt[i].ff * mt[j].ss * mt[k].ss;
            if(mi > cost)
            {
                mi = cost;
                opt = {"(" + l.ff + " x " + r.ff + ")", cost};
            }
        }
        return dp[i][j] = opt;
    }
}

void cp()
{
    int t = 0;
    while(cin >> n && n)
    {
        ll a, b;
        fill(all(dp), vector<pair<string, ll>>(15, {"", -1}));
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b;
            mt[i] = pii{a, b};
        }
        pair<string, ll> ans = solve(0, n - 1);
        cout << "Case " << ++t << ": " << ans.ff << endl;
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