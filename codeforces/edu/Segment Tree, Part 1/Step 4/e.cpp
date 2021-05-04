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

using ftype = array<int, 2>;

ftype t[4 * MAXN];
int lazy[4 * MAXN];
ftype e = {INT_MIN, INT_MAX}; // Identity Element

ftype combine(ftype L, ftype R)
{
    return {max(L[0], R[0]), min(L[1], R[1])};
}

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    if(~lazy[v])
    {
        t[v << 1] = t[v << 1 | 1] = {lazy[v], lazy[v]};
        lazy[v << 1] = lazy[v << 1 | 1] = lazy[v];
    }
    lazy[v] = -1;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = {INT_MAX, INT_MAX}, lazy[v] = -1;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
        lazy[v] = -1;
    }
}

void setpt(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] = {val, val};
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if(pos <= tm)
            setpt(v << 1, tl, tm, pos, val);
        else
            setpt(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

int destroy;
void update(int v, int tl, int tr, int l, int r, int val)
{
    if(tl > r || tr < l)
        return;
    if(tl != tr) push(v, tl, tr);
    if(t[v][1] > val)
        return;
    if(l <= tl && tr <= r)
    {
        if(t[v][0] <= val)
        {
            t[v] = {INT_MAX, INT_MAX};
            lazy[v] = INT_MAX;
            destroy += tr - tl + 1;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, r, val);
    update(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}

void cp()
{
    int n, q;
    cin >> n >> q;

    build(1, 0, n - 1);

    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x, y;
            cin >> x >> y;
            setpt(1, 0, n - 1, x, y);
        }
        else
        {
            int l, r, p;
            cin >> l >> r >> p, r--;
            destroy = 0;
            update(1, 0, n - 1, l, r, p);
            cout << destroy << endl;
        }
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
