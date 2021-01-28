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

/*
Segment Tree, w/o Lazy updates

It is a data structure for Monoid
1. Associativity
2. Existence of Identity Element

How to use:
1. Set identity Element
2. Fill combine() function
3. If you use updatept, set the update required
*/

using ftype = int;

ftype t[4 * MAXN];
ftype e = -1; // Identity Element

ftype combine(ftype L, ftype R)
{
    return max(L, R);
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

void build(int v, int tl, int tr, vector<ftype> &arr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void setpt(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            setpt(v << 1, tl, tm, pos, val);
        else
            setpt(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

int kth_one(int v, int tl, int tr, int k) // Index of kth one
{
    if(k > t[v])
        return -1; // Does not exist
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= k)
            return kth_one(v << 1, tl, tm, k);
        else
            return kth_one(v << 1 | 1, tm + 1, tr, k);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    build(1, 0, n - 1, arr);

    while(q--)
    {
        int t, x, y;
        cin >> t >> x;
        if(t == 1)
        {
            cin >> y;
            setpt(1, 0, n - 1, x, y);
        }
        else
        {
            int ans = kth_one(1, 0, n - 1, x);
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

