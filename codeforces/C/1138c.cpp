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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

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
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<int>> row(n), col(m);
    for(int i = 0; i < n; i++)
    {
        set<int> st;
        for(int j = 0; j < m; j++)
            st.insert(grid[i][j]);
        row[i] = vector<int>(all(st));
    }

    for(int j = 0; j < m; j++)
    {
        set<int> st;
        for(int i = 0; i < n; i++)
            st.insert(grid[i][j]);
        col[j] = vector<int>(all(st));
    }

    for(int i = 0; i < n; i++, cout << endl)
        for(int j = 0; j < m; j++)
        {
            int row_wise = lower_bound(all(row[i]), grid[i][j]) - begin(row[i]);
            int col_wise = lower_bound(all(col[j]), grid[i][j]) - begin(col[j]);

            auto col_up = upper_bound(all(col[j]), grid[i][j]) - begin(col[j]);
            int col_more = sz(col[j]) - col_up;

            auto row_up = upper_bound(all(row[i]), grid[i][j]) - begin(row[i]);
            int row_more = sz(row[i]) - row_up;

            cout << max({row_wise + col_more + 1, col_wise + row_more + 1, sz(row[i]), sz(col[j])}) << " ";
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
