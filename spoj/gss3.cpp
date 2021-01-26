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
const int MAXN = 5e4 + 5;
const ll inf = 1e10;

ll arr[MAXN];
struct node
{
    ll sum, pref, suff, ans;
    node() {}
    node(ll val): sum(val), pref(val), suff(val), ans(val) {}
};

node t[4 * MAXN];

node combine(node left, node right)
{
    node res;
    res.ans = max({right.ans, left.ans, left.suff + right.pref});
    res.pref = max(left.pref, left.sum + right.pref);
    res.suff = max(right.suff, right.sum + left.suff);
    res.sum = left.sum + right.sum;
    return res;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = node(arr[tl]);
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int tl, int tr, int pos, ll val)
{
    if(tl == tr)
        t[v] = node(val);
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

node query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return node(-inf);
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        node left =  query(v << 1, tl, tm, l, min(r, tm));
        node right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(left, right);
    }
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if(t)
            cout << query(1, 0, n - 1, x - 1, y - 1).ans << endl;
        else
            update(1, 0, n - 1, x - 1, y);
    }
}

int main()
{
    FASTIO;
    // time_t t1, t2;
    // t1 = clock();
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    // t2 = clock();
    // cerr << endl << "time taken: " << (long double) (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}