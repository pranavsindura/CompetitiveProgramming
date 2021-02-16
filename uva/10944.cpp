#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m;
    while(cin >> n >> m)
    {
        vector<string> grid(n);
        for(string &x : grid)
            cin >> x;
        vector<vector<int>> nuts;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'L')
                    nuts.push_back({i, j});
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '#')
                    nuts.push_back({i, j});

        vector<vector<int>> dp(sz(nuts), vector<int>(1 << sz(nuts), -1));

        auto cost = [&](vector<int> p, vector<int> q)
        {
            int dx = abs(p[0] - q[0]), dy = abs(p[1] - q[1]);
            return max(dx, dy);
        };

        function<int(int, int)> solve = [&](int i, int mask)
        {
            if(mask == (1 << sz(nuts)) - 1) return cost(nuts[i], nuts[0]);
            int &ret = dp[i][mask];
            if(~ret) return ret;
            int ans = inf;
            for(int j = 0; j < sz(nuts); j++)
                if(!((mask >> j) & 1))
                    ans = min(ans, cost(nuts[i], nuts[j]) + solve(j, mask ^ (1 << j)));
            return ret = ans;
        };

        int ans = solve(0, 1);
        cout << ans << endl;
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

