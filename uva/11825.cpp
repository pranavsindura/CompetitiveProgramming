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
int dp[1 << 16], good[1 << 16];

int solve(int mask)
{
    if(!mask)
        return 0;
    int &ret = dp[mask];
    if(~ret)
        return ret;
    int ans = 0;
    for(int nmask = mask; nmask; nmask = (nmask - 1)&mask)
        if(good[nmask])
            ans = max(ans, 1 + solve(mask & (~nmask)));
    return ret = ans;
}

void cp()
{
    int n;
    int test = 0;
    while(cin >> n && n)
    {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            adj[i] = vector<int>(m);
            for(int &x : adj[i])
                cin >> x;
        }
        clr(good, 0);
        for(int msk = 0; msk < 1 << n; msk++)
        {
            set<int> g;
            for(int i = 0; i < n; i++)
            {
                if((msk >> i) & 1)
                {
                    g.insert(i);
                    for(int x : adj[i])
                        g.insert(x);
                }
            }
            if(sz(g) == n)
                good[msk] = 1;
        }
        clr(dp, -1);
        cout << "Case " << ++test << ": " << solve((1 << n) - 1) << endl;
    }
}

int main()
{
    FASTIO;
    // time_t t1, t2;
    // t1 = clock();
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    // t2 = clock();
    // cerr << endl << "time taken: " << (long double) (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}