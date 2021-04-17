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
const int MAXN = 2e5 + 5;

using ftype = ll;

ftype t[4 * MAXN];
ftype e = 0; // Identity Element

ftype combine(ftype L, ftype R)
{
    return (L + R) % mod;
}

void updatept(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] = (t[v] + val) % mod;
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

    updatept(1, 0, MAXN - 1, arr[0], 1);

    ll sum = 1, sub = 1;
    for(int i = 1; i < n; i++)
    {
        sub = (sub * 2) % mod;
        ll L = 1, A = 1;
        A = (A + sum) % mod;
        A = (A + sub - 1 + mod) % mod;
        A = (A + query(1, 0, MAXN - 1, 0, arr[i] - 1)) % mod;
        L = (L + sub - 1 + mod) % mod;
        L = (L + query(1, 0, MAXN - 1, 0, arr[i] - 1)) % mod;

        sum = (sum + A) % mod;

        updatept(1, 0, MAXN - 1, arr[i], L);
    }

    cout << sum << endl;
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

/*

ll sol(vector<int> &arr)
{
    int n = sz(arr);
    vector<ll> len(n), subseq(n), ans(n);
    len[0] = subseq[0] = ans[0] = 1;
    for(int i = 1; i < n; i++)
    {
        subseq[i] = (subseq[i - 1] * 2) % mod;
        len[i] = ans[i] = 1;
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
            {
                ans[i] += ans[j] + len[j] + subseq[j];
                ans[i] %= mod;
                len[i] += subseq[j] + len[j];
                len[i] %= mod;
            }
            else
            {
                ans[i] += ans[j] + subseq[j];
                ans[i] %= mod;
                len[i] += subseq[j];
                len[i] %= mod;
            }
    }
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum = (sum + ans[i]) % mod;
    return sum;
}
*/