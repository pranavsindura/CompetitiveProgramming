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
        t[v << 1][0] = t[v << 1 | 1][0] = lazy[v];
        t[v << 1][1] = t[v << 1 | 1][1] = lazy[v];
        lazy[v << 1] = lazy[v << 1 | 1] = lazy[v];
        lazy[v] = -1;
    }
}

void build(int v, int tl, int tr, vector<int> &arr)
{
    if(tl == tr)
        t[v] = {arr[tl], arr[tl]}, lazy[v] = -1;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
        lazy[v] = -1;
    }
}

ftype querypt(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if(pos <= tm)
            return querypt(v << 1, tl, tm, pos);
        else
            return querypt(v << 1 | 1, tm + 1, tr, pos);
    }
}

void rmax(int v, int tl, int tr, int l, int r, int val)
{
    if(tl > r || tr < l) return;
    if(tl != tr) push(v, tl, tr);
    if(t[v][1] > val) return;
    if(l <= tl && tr <= r)
    {
        if(t[v][0] <= val)
        {
            t[v][0] = t[v][1] = lazy[v] = val;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    rmax(v << 1, tl, tm, l, r, val);
    rmax(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}
void rmin(int v, int tl, int tr, int l, int r, int val)
{
    if(tl > r || tr < l) return;
    if(tl != tr) push(v, tl, tr);
    if(t[v][0] < val) return;
    if(l <= tl && tr <= r)
    {
        if(t[v][1] >= val)
        {
            t[v][0] = t[v][1] = lazy[v] = val;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    rmin(v << 1, tl, tm, l, r, val);
    rmin(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}

void cp()
{
    int N, MAXH, M;
    cin >> N >> MAXH >> M;
    vector<int> L(M), R(M), A(M), B(M);
    for(int &x : L) cin >> x, x--;
    for(int &x : R) cin >> x, x--;
    for(int &x : A) cin >> x;
    for(int &x : B) cin >> x;

    vector<int> MX(N, MAXH);
    build(1, 0, N - 1, MX);
    for(int i = 0; i < M; i++)
        rmin(1, 0, N - 1, L[i], R[i], B[i]);
    for(int i = 0; i < N; i++)
        MX[i] = querypt(1, 0, N - 1, i)[0];

    vector<int> MN(N, 1);
    build(1, 0, N - 1, MN);
    for(int i = 0; i < M; i++)
        rmax(1, 0, N - 1, L[i], R[i], A[i]);
    for(int i = 0; i < N; i++)
        MN[i] = querypt(1, 0, N - 1, i)[1];

    ll ans = 1;
    for(int i = 0; i < N; i++)
        ans = (ans * max(0, MX[i] - MN[i] + 1)) % mod;

    cout << ans << endl;
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
