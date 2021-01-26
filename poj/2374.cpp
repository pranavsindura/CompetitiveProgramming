#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#define ll        long long int
#define ld        long double
#define pi        pair<ll,ll>
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
const ll inf = 1e16;
const int MAXN = 2e5 + 5;
const int OFF = 1e5;

int t[4 * MAXN], lazy[4 * MAXN];

void push(int v)
{
    if(!lazy[v]) return;
    t[v << 1] = lazy[v << 1] = t[v << 1 | 1] = lazy[v << 1 | 1] = lazy[v];
    lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int val)
{
    if(l > r) return;
    if(tl == l && tr == r)
    {
        t[v] = val;
        lazy[v] = val;
    }
    else
    {
        push(v);
        int tm = (tl + tr) >> 1;
        upd(v << 1, tl, tm, l, min(r, tm), val);
        upd(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

int query(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        push(v);
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            return query(v << 1, tl, tm, pos);
        else
            return query(v << 1 | 1, tm + 1, tr, pos);
    }
}

ll _abs(ll x)
{
    return (x >= 0 ? x : -x);
}

void cp()
{
    int n, s;
    cin >> n >> s;
    vector<pi> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i].ff >> arr[i].ss;
    vector< vector< ll > > dist(n + 1, vector< ll >(2, inf));
    for(int i = 1; i <= n; i++)
    {
        int l = query(1, 0, MAXN - 1, arr[i].ff + OFF);
        if(l == 0) // barn base
        {
            dist[i][0] = min(dist[i][0], _abs(arr[i].ff));
        }
        else // any other, need to travel additional to ends
        {
            dist[i][0] = min(dist[i][0],
                              min(dist[l][0] + _abs(arr[i].ff - arr[l].ff),
                              dist[l][1] + _abs(arr[i].ff - arr[l].ss)
                             ));
        }
        int r = query(1, 0, MAXN - 1, arr[i].ss + OFF);
        if(r == 0) // barn base
        {
            dist[i][1] = min(dist[i][1], _abs(arr[i].ss));
        }
        else // any other, need to travel additional to ends
        {
            dist[i][1] = min(dist[i][1],
                              min(dist[r][0] + _abs(arr[i].ss - arr[r].ff),
                              dist[r][1] + _abs(arr[i].ss - arr[r].ss)
                             ));
        }
        upd(1, 0, MAXN - 1, arr[i].ff + OFF, arr[i].ss + OFF, i);
    }
    ll ans = min(dist[n][0] + _abs(s - arr[n].ff), dist[n][1] + _abs(s - arr[n].ss));
    cout << ans << endl;
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

