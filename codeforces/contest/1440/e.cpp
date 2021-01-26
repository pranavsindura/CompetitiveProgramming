#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 2e5 + 5;

int arr[MAXN];
int tmax[4 * MAXN], tmin[4 * MAXN], lazy[4 * MAXN];
ll tsum[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        tmax[v] = tmin[v] = tsum[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tmax[v] = max(tmax[v << 1], tmax[v << 1 | 1]);
        tmin[v] = min(tmin[v << 1], tmin[v << 1 | 1]);
        tsum[v] = tsum[v << 1] + tsum[v << 1 | 1];
    }
}

void push(int v, int tl, int tr)
{
    if(!lazy[v]) return;
    int tm = (tl + tr) >> 1;
    tmax[v << 1] = lazy[v];
    tmin[v << 1] = lazy[v];
    tsum[v << 1] = lazy[v] * 1LL * (tm - tl + 1);
    lazy[v << 1] = lazy[v];
    tmax[v << 1 | 1] = lazy[v];
    tmin[v << 1 | 1] = lazy[v];
    tsum[v << 1 | 1] = lazy[v] * 1LL * (tr - tm);
    lazy[v << 1 | 1] = lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(tl > r || tr < l) return;
    if(tl != tr) push(v, tl, tr);
    if(tmin[v] > val) return;
    // i need to further break the range, YES
    // UVA 1232 :)
    if(l <= tl && tr <= r)
    {
        if(tmax[v] <= val)
        {
            tmax[v] = val;
            tmin[v] = val;
            tsum[v] = val * 1LL * (tr - tl + 1);
            lazy[v] = val;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, r, val);
    update(v << 1 | 1, tm + 1, tr, l, r, val);
    tmax[v] = max(tmax[v << 1], tmax[v << 1 | 1]);
    tmin[v] = min(tmin[v << 1], tmin[v << 1 | 1]);
    tsum[v] = tsum[v << 1] + tsum[v << 1 | 1];
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl != tr) push(v, tl, tr);
    if(tl == l && tr == r)
        return tsum[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, min(r, tm)) + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

int bs_start(int v, int tl, int tr, int pos, ll val)
{
    if(tl != tr) push(v, tl, tr);
    if(tl == tr)
        return tmin[v] <= val ? tl : MAXN;
    else
    {
        int tm = (tl + tr) >> 1;
        if(tm < pos || tmin[v << 1] > val) // go right
            return bs_start(v << 1 | 1, tm + 1, tr, pos, val);
        else
            return bs_start(v << 1, tl, tm, pos, val);
    }
}

int bs_end(int v, int tl, int tr, ll val)
{
    if(tl != tr) push(v, tl, tr);
    if(tl == tr)
        return tsum[v] <= val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(tsum[v << 1] >= val)
            return bs_end(v << 1, tl, tm, val);
        else
            return (tm - tl + 1) + bs_end(v << 1 | 1, tm + 1, tr, val - tsum[v << 1]);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while(q--)
    {
        int t, x;
        ll y;
        cin >> t >> x >> y;
        x--;
        if(t == 1)
            update(1, 0, n - 1, 0, x, y);
        else
        {
            int ans = 0;
            int p = x;
            while(p < n)
            {
                int idx = bs_start(1, 0, n - 1, p, y);
                if(idx >= n) break;

                ll v = y + query(1, 0, n - 1, 0, idx - 1);

                int got = bs_end(1, 0, n - 1, v);
                got -= idx;
                int idx2 = idx + got - 1;
                y -= query(1, 0, n - 1, idx, idx2);
                ans += got;
                p = idx2 + 1;
            }
            cout << ans << endl;
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