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
const int MAXN = 3e5 + 5;

using ftype = int;

ftype t[4 * MAXN];
ftype e = 0; // Identity Element

ftype combine(ftype L, ftype R)
{
    return L + R;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = e;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void updatept(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] += val;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    build(1, 0, n - 1);

    vector<int> small_right(n), big_right(n);
    vector<int> small_left(n), big_left(n);

    vector<ll> inv(n);
    for(int i = 0; i < n; i++)
    {
        inv[0] += query(1, 0, n - 1, arr[i] + 1, n - 1);
        big_left[i] = query(1, 0, n - 1, arr[i] + 1, n - 1);
        small_left[i] = query(1, 0, n - 1, 0, arr[i] - 1);
        updatept(1, 0, n - 1, arr[i], 1);
    }

    build(1, 0, n - 1);

    for(int i = n - 1; i >= 0; i--)
    {
        big_right[i] = query(1, 0, n - 1, arr[i] + 1, n - 1);
        small_right[i] = query(1, 0, n - 1, 0, arr[i] - 1);
        updatept(1, 0, n - 1, arr[i], 1);
    }

    for(int i = 1; i < n; i++)
    {
        inv[i] = inv[i - 1];
        inv[i] += big_right[i - 1];
        inv[i] -= small_right[i - 1];
        inv[i] -= small_left[i - 1];
        inv[i] += big_left[i - 1];
    }

    for(ll x : inv)
        cout << x << endl;
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

