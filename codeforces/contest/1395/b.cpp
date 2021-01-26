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

void cp()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    bool vis[n][m];
    clr(vis, false);
    vector<pi> ans;

    while(x != 0)
    {
        if(!vis[x][y])
            vis[x][y] = 1, ans.pb({x, y});
        x--;
    }
    while(y != 0)
    {
        if(!vis[x][y])
            vis[x][y] = 1, ans.pb({x, y});
        y--;
    }

    for(int i = 0; i < n; i++)
    {
        if(i & 1)
        {
            for(int j = m - 1; j >= 0; j--)
                if(!vis[i][j])
                    vis[i][j] = 1, ans.pb({i, j});
        }
        else
        {
            for(int j = 0; j < m; j++)
                if(!vis[i][j])
                    vis[i][j] = 1, ans.pb({i, j});
        }
    }

    for(pi op : ans)
        cout << op.ff + 1 << " " << op.ss + 1 << endl;
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