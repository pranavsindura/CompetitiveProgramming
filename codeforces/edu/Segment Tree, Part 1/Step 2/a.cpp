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

/*
Segment Tree, w/o Lazy updates

It is a data structure for Monoid
1. Associativity
2. Existence of Identity Element

How to use:
1. Keep all arrays global
2. Set identity Element
3. Fill combine() function
4. If you use updatept, fix the operation
*/

struct ftype
{
    ll sum, pref, suff, best;
    ftype(): sum(0), pref(0), suff(0), best(0) {}
    ftype(ll val): sum(val), pref(max(0LL, val)), suff(pref), best(pref) {}
};

ftype t[4 * MAXN];
ftype e = ftype(0); // Identity Element

ftype combine(ftype L, ftype R)
{
    ftype res;
    res.sum = L.sum + R.sum;
    res.best = max({L.best, R.best, L.suff + R.pref});
    res.pref = max(L.pref, L.sum + R.pref);
    res.suff = max(R.suff, L.suff + R.sum);
    return res;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = e;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void build(int v, int tl, int tr, vector<ftype> &arr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void setpt(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            setpt(v << 1, tl, tm, pos, val);
        else
            setpt(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

ftype query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return e;

    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        ftype L = query(v << 1, tl, tm, l, min(r, tm));
        ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(L, R);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<ftype> arr(n);
    for(int i = 0, x; i < n; i++)
        cin >> x, arr[i] = ftype(x);

    build(1, 0, n - 1, arr);
    cout << query(1, 0, n - 1, 0, n - 1).best << endl;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        setpt(1, 0, n - 1, x, ftype(y));
        cout << query(1, 0, n - 1, 0, n - 1).best << endl;
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

