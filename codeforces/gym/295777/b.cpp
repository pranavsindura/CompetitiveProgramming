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
// probably overkill
int t[4 * MAXN], lazy[4 * MAXN];

void push(int v)
{
    int left = v << 1, right = v << 1 | 1;
    t[left] = max(t[left], lazy[v]);
    t[right] = max(t[right], lazy[v]);
    lazy[left] = max(lazy[left], lazy[v]);
    lazy[right] = max(lazy[right], lazy[v]);
    lazy[v] = 0;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void updatept(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        if(pos <= tm)
            updatept(v << 1, tl, tm, pos, val);
        else
            updatept(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        t[v] = max(t[v], val);
        lazy[v] = max(lazy[v], val);
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        update(v << 1, tl, tm, l, min(r, tm), val);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return -1;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v);
        int left = query(v << 1, tl, tm, l, min(r, tm));
        int right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return max(left, right);
    }
}

void cp()
{
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    cin >> q;
    while(q--)
    {
        int t, p, x;
        cin >> t;
        if(t == 1)
        {
            cin >> p >> x;
            p--;
            updatept(1, 0, n - 1, p, x);
        }
        else
        {
            cin >> x;
            update(1, 0, n - 1, 0, n - 1, x);
        }
    }
    for(int i = 0; i < n; i++)
        cout << query(1, 0, n - 1, i, i) << " ";
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