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
const int MAXN = 2e5 + 5;

int t[4 * MAXN];

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, min(r, tm));
        int right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return left + right;
    }
}

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> row(n, m), col(m, n);

    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        row[x] = min(row[x], y);
        col[y] = min(col[y], x);
    }

    bool found = false;
    for(int i = 0; i < m; i++)
    {
        if(found) col[i] = 0;
        else if(col[i] == 0) found = true;
    }

    found = false;
    for(int i = 0; i < n; i++)
    {
        if(found) row[i] = 0;
        else if(row[i] == 0) found = true;
    }

    vector<vector<int>> order, pts;
    for(int i = 0; i < m; i++)
    {
        if(col[i] == n) continue;
        order.push_back({col[i], i});
    }

    for(int i = 0; i < n; i++)
    {
        if(row[i] == m) continue;
        pts.push_back({i, row[i]});
    }

    sort(all(pts), [&](vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    });

    reverse(all(pts));
    reverse(all(order));

    ll ans = 0;

    while(!order.empty())
    {
        int R = order.back()[0], C = order.back()[1];
        order.pop_back();

        while(!pts.empty() && pts.back()[1] <= C)
        {
            update(1, 0, n - 1, pts.back()[0], 1);
            pts.pop_back();
        }

        ans += query(1, 0, n - 1, R, n - 1);
    }

    ans = n * 1LL * m - ans;
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

