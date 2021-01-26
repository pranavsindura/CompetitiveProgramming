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
const int MAXN = 3e5 + 5;

int arr[MAXN];
int t[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = t[v << 1] ^ t[v << 1 | 1];
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] ^= val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = t[v << 1] ^ t[v << 1 | 1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl == l && tr == r) return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, min(r, tm)) ^ query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
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
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1)
            update(1, 0, n - 1, x - 1, y);
        else
            cout << query(1, 0, n - 1, x - 1, y - 1) << endl;
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

