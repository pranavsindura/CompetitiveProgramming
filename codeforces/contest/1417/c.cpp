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
const int MAXN = 3e5 + 5;

int t[4 * MAXN], lazy[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = INT_MAX, lazy[v] = INT_MAX;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
        lazy[v] = INT_MAX;
    }
}

void push(int v)
{
    t[v << 1] = min(t[v << 1], lazy[v]);
    t[v << 1 | 1] = min(t[v << 1 | 1], lazy[v]);
    lazy[v << 1] = min(lazy[v << 1], lazy[v]);
    lazy[v << 1 | 1] = min(lazy[v << 1 | 1], lazy[v]);
    lazy[v] = INT_MAX;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
        t[v] = min(t[v], val), lazy[v] = min(lazy[v], val);
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        update(v << 1, tl, tm, l, min(r, tm), val);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

int query(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        if(pos <= tm)
            return query(v << 1, tl, tm, pos);
        else
            return query(v << 1 | 1, tm + 1, tr, pos);
    }
}


void cp()
{
    int n;
    cin >> n;
    
    vector<vector<int>> pos(n);
    for(int i = 0; i < n; i++)
        pos[i].pb(0);
    for(int i = 0, x; i < n; i++)
        cin >> x, x--, pos[x].pb(i + 1);
    for(int i = 0; i < n; i++)
        pos[i].pb(n + 1);

    build(1, 1, n);
    for(int i = 0; i < n; i++)
    {
        int mx = 0;
        for(int j = 1; j < sz(pos[i]); j++)
        {
            int diff = pos[i][j] - pos[i][j - 1];
            mx = max(mx, diff);
        }
        if(mx <= n)
            update(1, 1, n, mx, n, i);
    }

    for(int i = 1; i <= n; i++)
    {
        int x = query(1, 1, n, i);
        if(x == INT_MAX)
            cout << -1 << " ";
        else
            cout << x + 1 << " ";
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