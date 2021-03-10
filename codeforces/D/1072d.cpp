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
const int MAXN = 2e3 + 5;

char arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, k;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

void cp()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = arr[i][j] != 'a';
            int extra = inf;
            if(i - 1 >= 0) extra = min(extra, dp[i - 1][j]);
            if(j - 1 >= 0) extra = min(extra, dp[i][j - 1]);
            if(extra == inf) extra = 0;
            dp[i][j] += extra;
        }

    int mx = -1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(dp[i][j] <= k)
                mx = max(mx, i + j);

    string ans = string(mx + 1, 'a');
    queue<vector<int>> q;

    if(~mx)
    {
        for(int x = 0; x < n; x++)
            for(int y = 0; y < n; y++)
                if(mx == x + y && dp[x][y] <= k)
                {
                    if(valid(x + 1, y) && !vis[x + 1][y])
                        q.push({0, x + 1, y}), vis[x + 1][y] = 1;
                    if(valid(x, y + 1) && !vis[x][y + 1])
                        q.push({0, x, y + 1}), vis[x][y + 1] = 1;
                }
    }
    else
        q.push({0, 0, 0}), vis[0][0] = 1;

    while(!q.empty())
    {
        int L = q.front()[0];
        vector<vector<int>> level;
        while(!q.empty() && q.front()[0] == L)
            level.pb(q.front()), q.pop();

        char mn = 'z';
        for(auto v : level)
            mn = min(mn, arr[v[1]][v[2]]);

        ans += mn;
        for(auto v : level)
        {
            int x = v[1], y = v[2];
            if(arr[x][y] != mn) continue;
            if(valid(x + 1, y) && !vis[x + 1][y])
                q.push({L + 1, x + 1, y}), vis[x + 1][y] = 1;
            if(valid(x, y + 1) && !vis[x][y + 1])
                q.push({L + 1, x, y + 1}), vis[x][y + 1] = 1;
        }
    }

    cout << ans << endl;
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
