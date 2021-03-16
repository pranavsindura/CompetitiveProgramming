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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    bool ok = true;
    vector<vector<int>> ans(n, vector<int>(m));

    if(a == m && b == n) ans = vector<vector<int>>(n, vector<int>(m, 1));
    else if(a * n == b * m)
    {
        for(int i = m - a; i < m; i++)
            ans[0][i] = 1;
        int skip = -1;
        for(int i = 0; i < m; i++)
            if((i * n) % m == 0)
                skip = i;
        assert(~skip);
        for(int i = 1; i < n; i++)
        {
            for(int j = skip; j < m; j++)
                ans[i][j - skip] = ans[i - 1][j];
            for(int j = 0; j < skip; j++)
                ans[i][(m - skip) + j] = ans[i - 1][j];
        }

    }
    else
        ok = false;

    if(ok)
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++, cout << endl)
            for(int j = 0; j < m; j++)
                cout << ans[i][j];
    }
    else
        cout << "NO\n";
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
