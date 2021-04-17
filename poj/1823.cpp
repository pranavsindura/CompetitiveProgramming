#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <assert.h>
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

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

// using ll = long long int;
// using ld = long double;
// using pi = pair<int, int>;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 16000 + 5;

struct ftype
{
    int pref, suff, ans, len;
    ftype(): pref(0), suff(0), ans(0), len(0) {}
    void clear()
    {
        pref = suff = ans = len;
    }
    void fill()
    {
        pref = suff = ans = 0;
    }
};

ftype t[4 * MAXN];
int lazy[4 * MAXN];
ftype e; // Identity Element

ftype combine(ftype L, ftype R)
{
    ftype res;
    res.pref = L.ans == L.len ? L.ans + R.pref : L.pref;
    res.suff = R.ans == R.len ? R.ans + L.suff : R.suff;
    res.ans = max(max(L.ans, R.ans), L.suff + R.pref);
    res.len = L.len + R.len;
    return res;
}

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    if(lazy[v] == -1) return;
    if(lazy[v] == 0) // vacate [tl, tr]
    {
        t[v << 1].clear();
        t[v << 1 | 1].clear();
        lazy[v << 1] = lazy[v << 1 | 1] = 0;
    }
    else
    {
        t[v << 1].fill();
        t[v << 1 | 1].fill();
        lazy[v << 1] = lazy[v << 1 | 1] = 1;
    }
    lazy[v] = -1;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v].len = 1, t[v].clear(), lazy[v] = -1;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
        lazy[v] = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r) return;
    if(tl == l && tr == r)
    {
        if(val == 0) t[v].clear();
        else t[v].fill();
        lazy[v] = val;
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

void cp()
{
    int n, q;
    scanf("%d %d", &n, &q);
    build(1, 0, n - 1);
    while(q--)
    {
        int t, x, k;
        scanf("%d", &t);
        if(t < 3) scanf("%d %d", &x, &k), x--;
        if(t == 1) update(1, 0, n - 1, x, x + k - 1, 1);
        else if(t == 2) update(1, 0, n - 1, x, x + k - 1, 0);
        else printf("%d\n", ::t[1].ans);
    }
}

int main()
{
    // FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
