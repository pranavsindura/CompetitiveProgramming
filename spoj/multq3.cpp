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

using ftype = array<int, 3>;

ftype t[4 * MAXN];
int lazy[4 * MAXN];
ftype e = {0, 0, 0}; // Identity Element

ftype combine(ftype L, ftype R)
{
    return {L[0] + R[0], L[1] + R[1], L[2] + R[2]};
}

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    lazy[v] %= 3;
    for(int i = 0; i < lazy[v]; i++)
        t[v << 1] = {t[v << 1][2], t[v << 1][0], t[v << 1][1]};
    for(int i = 0; i < lazy[v]; i++)
        t[v << 1 | 1] = {t[v << 1 | 1][2], t[v << 1 | 1][0], t[v << 1 | 1][1]};
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = {1, 0, 0}, lazy[v] = 0;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
        lazy[v] = 0;
    }
}

// Range update
void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r) return;

    if(tl == l && tr == r)
    {
        t[v] = {t[v][2], t[v][0], t[v][1]};
        lazy[v] += val;
        lazy[v] %= 3;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        update(v << 1, tl, tm, l, min(r, tm), val);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
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
    build(1, 0, n - 1);
    while(q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        
        if(t == 0)
            update(1, 0, n - 1, x, y, 1);
        else
            cout << query(1, 0, n - 1, x, y)[0] << endl;
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
