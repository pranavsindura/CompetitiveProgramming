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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

int sum(int p, int q, int r, int s, vector<vector<int>> &grid)
{
    int ans = grid[r][s];
    if(q > 0)
        ans -= grid[r][q - 1];
    if(p > 0)
        ans -= grid[p - 1][s];
    if(p > 0 && q > 0)
        ans += grid[p - 1][q - 1];
    return ans;
}

void cp()
{
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            grid[i][j] = (x == '#');
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            grid[i][j] += grid[i][j - 1];
        }
    }
    for(int j = 0; j < m; j++)
    {
        for(int i = 1; i < n; i++)
        {
            grid[i][j] += grid[i - 1][j];
        }
    }
    bool ok = false;
    ll mn = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int lo = 0, hi = n * m;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                int d = mid;
                int p = i - d, q = j - d, r = i + d, s = j + d;
                p = max(0, p);
                q = max(0, q);
                r = min(r, n - 1);
                s = min(s, m - 1);
                int cur = sum(p, q, r, s, grid);
                if(cur >= k)
                {
                    mn = min(mn, 1LL * c * (mid + 1));
                    hi = mid - 1;
                    ok = true;
                }
                else
                    lo = mid + 1;
            }
        }
    }
    if(ok)
        cout << mn << endl;
    else
        cout << -1 << endl;
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