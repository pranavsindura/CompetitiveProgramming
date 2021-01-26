#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll t[MAXN], lazy[MAXN];
bool marked[MAXN];
int n;

void push(int v, int llen, int rlen)
{
    if(marked[v])
    {
        t[v * 2] += lazy[v] * llen;
        t[v * 2 + 1] += lazy[v] * rlen;

        marked[v * 2] = marked[v * 2 + 1] = true;
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
        marked[v] = false;
    }
}

void _build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = 0, marked[v] = false, lazy[v] = 0;
    else
    {
        int tm = (tl + tr) / 2;
        _build(2 * v, tl, tm);
        _build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
        marked[v] = false;
        lazy[v] = 0;
    }
}

void _update(int v, int tl, int tr, int l, int r, ll val)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        t[v] += val * (tr - tl + 1);
        marked[v] = true;
        lazy[v] += val;
    }
    else
    {
        int tm = (tr + tl) / 2;
        push(v, tm - tl + 1, tr - tm);
        _update(2 * v, tl, tm, l, min(r, tm), val);
        _update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll _query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
    {
        return t[v];
    }
    else
    {
        int tm = (tr + tl) / 2;
        push(v, tm - tl + 1, tr - tm);
        return _query(2 * v, tl, tm, l, min(r, tm)) + _query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void build()
{
    _build(1, 0, n - 1);
}

void update(int l, int r, ll val)
{
    _update(1, 0, n - 1, l, r, val);
}

ll query(int l, int r)
{
    return _query(1, 0, n - 1, l, r);
}

void cp()
{
    int q;
    cin >> n >> q;
    build();
    while(q--)
    {
        int t, x, y;
        ll v;
        cin >> t >> x >> y;
        if(t)
        {
            cout << query(x - 1, y - 1) << endl;
        }
        else
        {
            cin >> v;
            update(x - 1, y - 1, v);
        }
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        // cout << "Case " << i << ":\n";
        cp();
    }
    return 0;
}