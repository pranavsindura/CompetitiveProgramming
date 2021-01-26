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
const int MAXN = 1e5 + 5;

int t[4 * MAXN], lazy[4 * MAXN];

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) / 2;
    int llen = tm - tl + 1;
    int rlen = tr - tm;

    if(lazy[v])
        t[v * 2] = llen - t[v * 2], t[v * 2 + 1] = rlen - t[v * 2 + 1];

    lazy[2 * v] ^= lazy[v];
    lazy[2 * v + 1] ^= lazy[v];
    lazy[v] = 0;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = lazy[v] = 0;
    else
    {
        int tm = (tr + tl) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        int len = tr - tl + 1;
        t[v] = len - t[v];
        lazy[v] ^= 1;
    }
    else
    {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm));
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
    {
        return t[v];
    }
    else
    {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    build(1, 0, n - 1);
    while(q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if(t)
            cout << query(1, 0, n - 1, u, v) << endl;
        else
            update(1, 0, n - 1, u, v);
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