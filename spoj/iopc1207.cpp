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

ftype t[3][4 * MAXN];
int lazy[3][4 * MAXN];
ftype e = {0, 0}; // Identity Element

ftype combine(ftype L, ftype R)
{
    return {L[0] + R[0], L[1] + R[1]};
}

void push(int v, int tl, int tr, int DIM)
{
    int tm = (tl + tr) >> 1;
    if(lazy[DIM][v])
    {
        swap(t[DIM][v << 1][0], t[DIM][v << 1][1]);
        lazy[DIM][v << 1] ^= 1;

        swap(t[DIM][v << 1 | 1][0], t[DIM][v << 1 | 1][1]);
        lazy[DIM][v << 1 | 1] ^= 1;

        lazy[DIM][v] = 0;
    }
}

void build(int v, int tl, int tr, int DIM)
{
    if(tl == tr)
        t[DIM][v] = {1, 0}, lazy[DIM][v] = 0;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, DIM);
        build(v << 1 | 1, tm + 1, tr, DIM);
        t[DIM][v] = combine(t[DIM][v << 1], t[DIM][v << 1 | 1]);
        lazy[DIM][v] = 0;
    }
}

// Range update
void update(int v, int tl, int tr, int l, int r, int DIM)
{
    if(l > r) return;

    if(tl == l && tr == r)
    {
        swap(t[DIM][v][0], t[DIM][v][1]);
        lazy[DIM][v] ^= 1;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr, DIM);
        update(v << 1, tl, tm, l, min(r, tm), DIM);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, DIM);
        t[DIM][v] = combine(t[DIM][v << 1], t[DIM][v << 1 | 1]);
    }
}

// Range query
ftype query(int v, int tl, int tr, int l, int r, int DIM)
{
    if(l > r) return e;

    if(tl == l && tr == r)
        return t[DIM][v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr, DIM);
        ftype L = query(v << 1, tl, tm, l, min(r, tm), DIM);
        ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, DIM);
        return combine(L, R);
    }
}

void cp()
{
    int Nx, Ny, Nz, Q;
    cin >> Nx >> Ny >> Nz >> Q;
    build(1, 0, Nx - 1, 0);
    build(1, 0, Ny - 1, 1);
    build(1, 0, Nz - 1, 2);
    while(Q--)
    {
        int t;
        cin >> t;
        if(t == 0)
        {
            int x, y;
            cin >> x >> y;
            update(1, 0, Nx - 1, x, y, 0);
        }
        else if(t == 1)
        {
            int x, y;
            cin >> x >> y;
            update(1, 0, Ny - 1, x, y, 1);
        }
        else if(t == 2)
        {
            int x, y;
            cin >> x >> y;
            update(1, 0, Nz - 1, x, y, 2);
        }
        else
        {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ll ans = 0;
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                    for(int k = 0; k < 2; k++)
                        if(i ^ j ^ k)
                            ans += query(1, 0, Nx - 1, x1, x2, 0)[i] * 1LL * query(1, 0, Ny - 1, y1, y2, 1)[j] * 1LL * query(1, 0, Nz - 1, z1, z2, 2)[k];
            cout << ans << endl;
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
