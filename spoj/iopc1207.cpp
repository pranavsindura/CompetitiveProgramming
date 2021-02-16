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

using ftype = int;

ftype t[4 * MAXN][3], lazy[4 * MAXN][3];
ftype e = 0; // Identity Element

ftype combine(ftype L, ftype R)
{
    return L + R;
}

void push(int v, int tl, int tr, int B)
{
    if(lazy[v][B])
    {
        int tm = (tl + tr) >> 1;
        t[v << 1][B] = tm - tl + 1 - t[v << 1][B];
        t[v << 1 | 1][B] = tr - tm - t[v << 1 | 1][B];
        lazy[v << 1][B] ^= 1;
        lazy[v << 1 | 1][B] ^= 1;
        lazy[v][B] = 0;
    }
}

void build(int v, int tl, int tr, int B)
{
    if(tl == tr)
        t[v][B] = e, lazy[v][B] = e;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, B);
        build(v << 1 | 1, tm + 1, tr, B);
        t[v][B] = combine(t[v << 1][B], t[v << 1 | 1][B]);
        lazy[v][B] = e;
    }
}

// Range update
void update(int v, int tl, int tr, int l, int r, int B)
{
    if(l > r) return;
    if(tl == l && tr == r)
    {
        t[v][B] = tr - tl + 1 - t[v][B];
        lazy[v][B] ^= 1;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr, B);
        update(v << 1, tl, tm, l, min(r, tm), B);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, B);
        t[v][B] = combine(t[v << 1][B], t[v << 1 | 1][B]);
    }
}

// Range query
ftype query(int v, int tl, int tr, int l, int r, int B)
{
    if(l > r) return e;
    if(tl == l && tr == r)
        return t[v][B];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr, B);
        ftype L = query(v << 1, tl, tm, l, min(r, tm), B);
        ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, B);
        return combine(L, R);
    }
}

void cp()
{
    int N[3], Q;
    cin >> N[0] >> N[1] >> N[2] >> Q;

    for(int i = 0; i < 3; i++)
        build(1, 0, N[i] - 1, i);

    while(Q--)
    {
        int T, a, b, c, p, q, r;
        cin >> T;
        if(T <= 2) cin >> a >> b;
        else cin >> a >> b >> c >> p >> q >> r;
        if(T <= 2) update(1, 0, N[T] - 1, a, b, T);
        else
        {
            int X = query(1, 0, N[0] - 1, a, p, 0);
            ll A = X;
            int Y = query(1, 0, N[1] - 1, b, q, 1);
            ll B = A * (q - b + 1);
            B -= Y * A;
            B += Y * ((p - a + 1) - A);
            int Z = query(1, 0, N[2] - 1, c, r, 2);
            ll C = B * (r - c + 1);
            C -= Z * B;
            C += Z * ((q - b + 1) * 1LL * (p - a + 1) - B);
            cout << C << endl;
        }
    }
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
