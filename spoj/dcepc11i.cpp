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

using ftype = ll;

ftype t[4 * MAXN], lazy[4 * MAXN], st[4 * MAXN];
ftype e = 0; // Identity Element

ftype combine(ftype L, ftype R)
{
    return L + R;
}

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    t[v << 1] += lazy[v] * (tm - tl + 1);
    t[v << 1 | 1] += lazy[v] * (tr - tm);

    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;

    t[v << 1] += st[v] * (tm - tl + 1) * (tm - tl + 2) / 2;
    t[v << 1 | 1] += st[v] * (tr - tm) * (tr - tm + 1) / 2;
    t[v << 1 | 1] += st[v] * (tm - tl + 1) * (tr - tm);
    lazy[v << 1 | 1] += st[v] * (tm - tl + 1);
    st[v << 1] += st[v];
    st[v << 1 | 1] += st[v];
    st[v] = 0;
}

// Range update
void update(int v, int tl, int tr, int l, int r, ftype val)
{
    if(l > r) return;

    if(tl == l && tr == r)
    {
        t[v] += val * (tr - tl + 1);
        t[v] += (tr - tl + 1) * 1LL * (tr - tl + 2) / 2;
        lazy[v] += val;
        st[v]++;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        update(v << 1, tl, tm, l, min(r, tm), val);
        // [tl, tm]
        // [l, r]
        int inter = max(0, min(r, tm) - max(tl, l) + 1);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val + inter);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

// Range query
ftype query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return e;

    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        ftype L = query(v << 1, tl, tm, l, min(r, tm));
        ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(L, R);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    while(q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        if(t == 0) update(1, 0, n - 1, x, y, 0);
        else cout << query(1, 0, n - 1, x, y) << endl;
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
