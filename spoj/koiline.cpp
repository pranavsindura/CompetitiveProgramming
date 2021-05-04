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
        t[v] = 1;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
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
            return kth_one(v << 1 | 1, tm + 1, tr, k - t[v << 1]);
    }
}

void cp()
{
    int n;
    cin >> n;

    vector<int> H(n);
    for(int &x : H)
        cin >> x;
    sort(all(H));

    vector<int> seq(n);
    for(int &x : seq)
        cin >> x;

    build(1, 0, n - 1);
    vector<int> arr(n);
    for(int i = n - 1; i >= 0; i--)
    {
        int k = kth_one(1, 0, n - 1, seq[i] + 1);
        assert(~k);
        arr[i] = H[k];
        setpt(1, 0, n - 1, k, 0);
    }
    for(int x : arr)
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
