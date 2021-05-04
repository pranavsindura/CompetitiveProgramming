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

using ftype = pair<array<int, 41>, ll>;

ftype t[4 * MAXN];
ftype e; // Identity Element

ftype combine(ftype L, ftype R)
{
    ftype res;
    res.second = L.second + R.second;
    res.first = L.first;
    for(int i = 1; i <= 40; i++) res.first[i] += R.first[i];

    array<int, 41> pref = L.first;
    partial_sum(all(pref), pref.begin());
    for(int i = 1; i <= 40; i++)
        res.second += (pref[40] - pref[i]) * 1LL * R.first[i];
    return res;
}

void build(int v, int tl, int tr, vector<int> &arr)
{
    if(tl == tr)
    {
        fill(all(t[v].first), 0);
        t[v].second = 0;
        t[v].first[arr[tl]]++;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void updatept(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
    {
        fill(all(t[v].first), 0);
        t[v].second = 0;
        t[v].first[val]++;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            updatept(v << 1, tl, tm, pos, val);
        else
            updatept(v << 1 | 1, tm + 1, tr, pos, val);
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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    fill(all(e.first), 0);
    e.second = 0;

    build(1, 0, n - 1, arr);

    while(q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1)
            cout << query(1, 0, n - 1, x - 1, y - 1).second << endl;
        else
            updatept(1, 0, n - 1, x - 1, y);
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
