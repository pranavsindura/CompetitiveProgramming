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
const int MAXN = 1.5e6 + 5;

int arr[MAXN], t[4 * MAXN], lazy[4 * MAXN], flip[4 * MAXN];

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    int llen = (tm - tl + 1);
    int rlen = (tr - tm);

    if(lazy[v] == 1)
        t[v << 1] = llen, t[v << 1 | 1] = rlen;
    else if(lazy[v] == 2)
        t[v << 1] = 0, t[v << 1 | 1] = 0;
    if(flip[v])
        t[v << 1] = llen - t[v << 1], t[v << 1 | 1] = rlen - t[v << 1 | 1];

    if(lazy[v])
        lazy[v << 1] = lazy[v << 1 | 1] = lazy[v], flip[v << 1] = flip[v << 1 | 1] = flip[v];
    else
        flip[v << 1] ^= flip[v], flip[v << 1 | 1] ^= flip[v];

    lazy[v] = flip[v] = 0;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = arr[tl], lazy[v] = flip[v] = 0;
    else
    {
        int tm = (tr + tl) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = t[v << 1] + t[v << 1 | 1];
        lazy[v] = flip[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int t1, int t2)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        if(t1 == 1)
            t[v] = (tr - tl + 1), lazy[v] = t1, flip[v] = t2;
        else if(t1 == 2)
            t[v] = 0, lazy[v] = t1, flip[v] = t2;
        else
            t[v] = (tr - tl + 1) - t[v], flip[v] ^= t2;
    }
    else
    {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, l, min(r, tm), t1, t2);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, t1, t2);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, min(r, tm)) + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void cp()
{
    int m, t, a, b;
    char f;
    string s;
    cin >> m;
    int n = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> t >> s;
        for(int j = 0; j < t; j++)
            for(char x : s)
                arr[n++] = x - '0';
    }

    build(1, 0, n - 1);
    cin >> t;
    int q = 1;
    while(t--)
    {
        cin >> f >> a >> b;
        if(f == 'F')
            update(1, 0, n - 1, a, b, 1, 0);
        else if(f == 'E')
            update(1, 0, n - 1, a, b, 2, 0);
        else if(f == 'I')
            update(1, 0, n - 1, a, b, 0, 1);
        else
            cout << "Q" << q++ << ": " << query(1, 0, n - 1, a, b) << endl;
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