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

using ftype = pair<ll, ll>;

ftype t[4 * MAXN];
ftype e = {0, 0}; // Identity Element

ftype combine(ftype L, ftype R)
{
    ftype X;
    X.first = L.first + R.first;
    X.second = max(L.second, R.second);
    return X;
}

void build(int v, int tl, int tr, vector<ll> &arr)
{
    if(tl == tr)
        t[v] = {arr[tl], arr[tl]};
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
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

void update(int v, int tl, int tr, int l, int r)
{
    if(l > r) return;
    if(tl > r || tr < l) return;
    if(t[v].second <= 1) return;

    if(tl == tr)
    {
        t[v].first = sqrt(t[v].first);
        t[v].second = t[v].first;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, l, min(r, tm));
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void cp()
{
    int n, m;
    int tc = 0;
    while(cin >> n)
    {
        vector<ll> arr(n);
        for(ll &x : arr)
            cin >> x;
        build(1, 0, n - 1, arr);
        int q;
        cin >> q;
        cout << "Case #" << ++tc << ":" << endl;
        while(q--)
        {
            int t, x, y;
            cin >> t >> x >> y;
            x--, y--;
            if(x > y) swap(x, y);
            if(t == 0) update(1, 0, n - 1, x, y);
            else cout << query(1, 0, n - 1, x, y).first << endl;
        }
        cout << endl;
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
