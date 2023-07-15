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

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

ll val(int x, int y, int n, int m, int r)
{
    int a = min(r, n - r + 1);
    int b = min(r, m - r + 1);
    int dx = min({x + 1, n - x, a});
    int dy = min({y + 1, m - y, b});
    return dx * 1LL * dy;
}

void cp()
{
    int n, m, r, k;
    cin >> n >> m >> r >> k;

    priority_queue<vector<ll>> pq;
    map<pi, bool> vis;

    pq.push({ val(n / 2, m / 2, n, m, r), n / 2, m / 2 });
    vis[ {n / 2, m / 2}] = true;

    double ans = 0;
    while(k-- > 0 && !pq.empty())
    {
        vector<ll> nd = pq.top();
        pq.pop();
        ans += double(nd[0]) / ((n - r + 1) * 1.0 * (m - r + 1));
        int x = nd[1], y = nd[2];

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis.count({nx, ny})) continue;
            pq.push({ val(nx, ny, n, m, r), nx, ny });
            vis[ {nx, ny}] = true;
        }
    }

    fix(10);
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
