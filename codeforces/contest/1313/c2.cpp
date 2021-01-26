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
const int MAXN = 5e5 + 5;

int actual[MAXN];
ll tsum[4 * MAXN];
int t[4 * MAXN], lazy[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        tsum[v] = t[v] = lazy[v] = 0;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tsum[v] = tsum[v << 1] + tsum[v << 1 | 1];
        t[v] = t[v << 1] + t[v << 1 | 1];
        lazy[v] = 0;
    }
}

void push(int v)
{
    if(lazy[v])
    {
        tsum[v << 1] = tsum[v << 1 | 1] = t[v << 1] = t[v << 1 | 1] = 0;
        lazy[v << 1] = lazy[v << 1 | 1] = 1;
    }
    lazy[v] = 0;
}

void updpt(int v, int tl, int tr, int pos, int freq)
{
    if(tl == tr)
        tsum[v] += actual[tl] * 1LL * freq, t[v] += freq;
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        if(pos <= tm)
            updpt(v << 1, tl, tm, pos, freq);
        else
            updpt(v << 1 | 1, tm + 1, tr, pos, freq);
        tsum[v] = tsum[v << 1] + tsum[v << 1 | 1];
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

void upd(int v, int tl, int tr, int l, int r)
{
    if(l > r) return;
    if(tl == l && tr == r)
    {
        tsum[v] = t[v] = 0;
        lazy[v] = 1;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        upd(v << 1, tl, tm, l, min(r, tm));
        upd(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        tsum[v] = tsum[v << 1] + tsum[v << 1 | 1];
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

ll sum(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl == l && tr == r)
        return tsum[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        return sum(v << 1, tl, tm, l, min(r, tm)) + sum(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

int sumfreq(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        return sumfreq(v << 1, tl, tm, l, min(r, tm)) + sumfreq(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    map<int, int> comp;
    int N = 0;
    for(int x : arr)
        comp[x];
    for(auto &x : comp)
        x.ss = N++;
    for(int x : arr)
        actual[comp[x]] = x;
    vector<ll> left(n), right(n);

    build(1, 0, N - 1);
    for(int i = 0; i < n; i++)
    {
        int f = sumfreq(1, 0, N - 1, comp[arr[i]] + 1, N - 1);
        upd(1, 0, N - 1, comp[arr[i]] + 1, N - 1);
        updpt(1, 0, N - 1, comp[arr[i]], f + 1);
        left[i] = sum(1, 0, N - 1, 0, N - 1) - arr[i];
    }

    build(1, 0, N - 1);
    for(int i = n - 1; i >= 0; i--)
    {
        int f = sumfreq(1, 0, N - 1, comp[arr[i]] + 1, N - 1);
        upd(1, 0, N - 1, comp[arr[i]] + 1, N - 1);
        updpt(1, 0, N - 1, comp[arr[i]], f + 1);
        right[i] = sum(1, 0, N - 1, 0, N - 1) - arr[i];
    }

    ll best = 0;
    int idx = -1;
    for(int i = 0; i < n; i++)
    {
        // max height at i
        ll me = left[i] + right[i] + arr[i];
        if(me > best)
            best = me, idx = i;
    }
    vector<ll> ans(n);
    ans[idx] = arr[idx];
    ll last = arr[idx];
    for(int j = idx + 1; j < n; j++)
        last = min(last, 1LL * arr[j]), ans[j] = last;
    last = arr[idx];
    for(int j = idx - 1; j >= 0; j--)
        last = min(last, 1LL * arr[j]), ans[j] = last;
    for(ll x : ans)
        cout << x << " ";
    cout << endl;
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

