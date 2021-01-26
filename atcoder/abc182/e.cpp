#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

vector<vector<int>> row, col;

void cp()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    row = vector<vector<int>>(n + 1, vector<int>(m + 1));
    col = vector<vector<int>>(n + 1, vector<int>(m + 1));
    vector<vector<int>> block_row(n), block_col(m);
    vector<vector<int>> bulb_row(n), bulb_col(m);
    for(int i = 0, x, y; i < p; i++)
        cin >> x >> y, x--, y--, bulb_row[x].pb(y), bulb_col[y].pb(x);
    for(int i = 0, x, y; i < q; i++)
        cin >> x >> y, x--, y--, block_row[x].pb(y), block_col[y].pb(x);

    for(int i = 0; i < n; i++)
    {
        sort(all(block_row[i]));
        for(int x : bulb_row[i])
        {
            // find left block
            int left = -1;
            int lo = 0, hi = sz(block_row[i]) - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if(block_row[i][mid] < x)
                    left = block_row[i][mid], lo = mid + 1;
                else
                    hi = mid - 1;
            }
            // find right block
            int right = m;
            lo = 0, hi = sz(block_row[i]) - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if(block_row[i][mid] > x)
                    right = block_row[i][mid], hi = mid - 1;
                else
                    lo = mid + 1;
            }
            left++, right--;
            row[i][left]++;
            row[i][right + 1]--;
        }

        for(int j = 1; j < m; j++)
            row[i][j] += row[i][j - 1];
    }
    
    for(int i = 0; i < m; i++)
    {
        sort(all(block_col[i]));
        for(int x : bulb_col[i])
        {
            // find top block
            int top = -1;
            int lo = 0, hi = sz(block_col[i]) - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if(block_col[i][mid] < x)
                    top = block_col[i][mid], lo = mid + 1;
                else
                    hi = mid - 1;
            }
            // find bottom block
            int bottom = n;
            lo = 0, hi = sz(block_col[i]) - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if(block_col[i][mid] > x)
                    bottom = block_col[i][mid], hi = mid - 1;
                else
                    lo = mid + 1;
            }
            top++, bottom--;
            col[top][i]++;
            col[bottom + 1][i]--;
        }

        for(int j = 1; j < n; j++)
            col[j][i] += col[j - 1][i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans += (row[i][j] || col[i][j]);
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