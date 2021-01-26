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
bool is_prime[MAXN];
vector<int> prime;
int arr[MAXN], t[MAXN], lazy[MAXN];
bool marked[MAXN];
int n;

void push(int v, int llen, int rlen)
{
    if(marked[v])
    {
        t[v * 2] = is_prime[lazy[v]] * llen;
        t[v * 2 + 1] = is_prime[lazy[v]] * rlen;

        marked[v * 2] = marked[v * 2 + 1] = true;
        lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
        lazy[v] = 1;
        marked[v] = false;
    }
}

void _build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = is_prime[arr[tl]], marked[v] = false;
    else
    {
        int tm = (tl + tr) / 2;
        _build(2 * v, tl, tm);
        _build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
        marked[v] = false;
    }
}

void _update(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        t[v] = is_prime[val] * (tr - tl + 1);
        marked[v] = true;
        lazy[v] = val;
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

int _query(int v, int tl, int tr, int l, int r)
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

void update(int l, int r, int val)
{
    _update(1, 0, n - 1, l, r, val);
}

int query(int l, int r)
{
    return _query(1, 0, n - 1, l, r);
}

void init()
{
    clr(is_prime, true);
    is_prime[1] = false;
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i])
            prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
}

void cp()
{
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build();
    while(q--)
    {
        int t, x, y, v;
        cin >> t;
        if(t)
        {
            cin >> x >> y;
            cout << query(x - 1, y - 1) << endl;
        }
        else
        {
            cin >> x >> y >> v;
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
    init();
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        cp();
    }
    return 0;
}