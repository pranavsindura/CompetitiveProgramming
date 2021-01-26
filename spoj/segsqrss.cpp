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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll inf = 10000;

int arr[MAXN];
ll tsq[4 * MAXN], t[4 * MAXN], inc[4 * MAXN], ass[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v] = arr[tl];
        tsq[v] = t[v] * t[v];
        inc[v] = 0;
        ass[v] = -inf;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = t[v << 1] + t[v << 1 | 1];
        tsq[v] = tsq[v << 1] + tsq[v << 1 | 1];
        inc[v] = 0;
        ass[v] = -inf;
    }
}

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;

    // first process assignment
    if(ass[v] > -inf)
    {
        t[v << 1] = (tm - tl + 1) * ass[v];
        tsq[v << 1] = (tm - tl + 1) * ass[v] * ass[v];

        t[v << 1 | 1] = (tr - tm) * ass[v];
        tsq[v << 1 | 1] = (tr - tm) * ass[v] * ass[v];

        inc[v << 1] = inc[v << 1 | 1] = 0;
        ass[v << 1] = ass[v << 1 | 1] = ass[v];
        ass[v] = -inf;
    }

    // then process increment
    tsq[v << 1] += (tm - tl + 1) * inc[v] * inc[v] + 2 * inc[v] * t[v << 1];
    t[v << 1] += (tm - tl + 1) * inc[v];

    tsq[v << 1 | 1] += (tr - tm) * inc[v] * inc[v] + 2 * inc[v] * t[v << 1 | 1];
    t[v << 1 | 1] += (tr - tm) * inc[v];

    inc[v << 1] += inc[v];
    inc[v << 1 | 1] += inc[v];
    inc[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll val, int type)
{
    if(l > r)
        return;
    if(tl != tr)
        push(v, tl, tr);
    if(tl == l && tr == r)
    {
        if(!type) // assign
        {
            t[v] = (tr - tl + 1) * val;
            tsq[v] = (tr - tl + 1) * val * val;
            inc[v] = 0;
            ass[v] = val;
        }
        else // increment
        {
            tsq[v] += (tr - tl + 1) * val * val + 2 * val * t[v];
            t[v] += (tr - tl + 1) * val;
            inc[v] += val;
        }
    }
    else
    {
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, l, min(r, tm), val, type);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val, type);
        t[v] = t[v << 1] + t[v << 1 | 1];
        tsq[v] = tsq[v << 1] + tsq[v << 1 | 1];
    }
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl != tr)
        push(v, tl, tr);
    if(tl == l && tr == r)
        return tsq[v];
    else
    {
        int tm = (tl + tr) >> 1;
        ll left = query(v << 1, tl, tm, l, min(r, tm));
        ll right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return left + right;
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while(q--)
    {
        int t, l, r, x;
        cin >> t >> l >> r;
        if(t < 2)
            cin >> x;
        l--, r--;
        if(t < 2)
            update(1, 0, n - 1, l, r, x, t);
        else
            cout << query(1, 0, n - 1, l, r) << endl;
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
        cout << "Case " << i << ":\n";
        cp();
    }
    return 0;
}