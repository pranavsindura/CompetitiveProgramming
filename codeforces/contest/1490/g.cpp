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
const int MAXN = 2e5 + 5;

using ftype = ll;

ftype t[4 * MAXN];
ftype e = LLONG_MIN; // Identity Element

ftype combine(ftype L, ftype R)
{
    return max(L, R);
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

int first_above(int v, int tl, int tr, ll k) // Index of first element >= k
{
    if(k > t[v])
        return -1; // Does not exist
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= k)
            return first_above(v << 1, tl, tm, k);
        else
            return first_above(v << 1 | 1, tm + 1, tr, k);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    vector<ll> pref(n);
    partial_sum(all(arr), pref.begin());

    build(1, 0, n - 1, pref);

    ll total = pref.back();

    while(q--)
    {
        ll K;
        cin >> K;

        ll p = -1;
        ll lo = 0, hi = 1e18 / abs(total);
        while(lo <= hi)
        {
            ll mid = (lo + hi) >> 1;
            ll sum = total * mid;
            ll need = K - sum;

            int idx = first_above(1, 0, n - 1, need);
            if(~idx)
            {
                p = n * 1LL * mid + idx;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        int idx = first_above(1, 0, n - 1, K);
        if(~idx) p = idx;

        cout << p << " ";
    }
    cout << endl;
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
