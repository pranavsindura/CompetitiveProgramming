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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e5 + 5;

int arr[MAXN];
vector<tuple<int, int, int>> range;

int t[4 * MAXN], lazy[4 * MAXN];

void push(int v)
{
    int left = v << 1, right = v << 1 | 1;
    t[left] |= lazy[v];
    t[right] |= lazy[v];
    lazy[left] |= lazy[v];
    lazy[right] |= lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        t[v] |= val;
        lazy[v] |= val;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        update(v << 1, tl, tm, l, min(r, tm), val);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = t[v << 1] & t[v << 1 | 1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return INT_MAX;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        int left = query(v << 1, tl, tm, l, min(r, tm));
        int right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return left & right;
    }
}


void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int l, r, q;
        cin >> l >> r >> q;
        range.pb(make_tuple(l, r, q));
    }

    for(auto &x : range)
        update(1, 0, n - 1, get<0>(x) - 1, get<1>(x) - 1, get<2>(x));

    bool ok = true;

    for(auto &x : range)
    {
        int res = query(1, 0, n - 1, get<0>(x) - 1, get<1>(x) - 1);
        if(res != get<2>(x))
            ok = false;
    }
    if(ok)
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
            cout << query(1, 0, n - 1, i, i) << " ";
        cout << endl;
    }
    else
        cout << "NO\n";
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