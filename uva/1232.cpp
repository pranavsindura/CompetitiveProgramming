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

int tmax[4 * MAXN], tmin[4 * MAXN], lazy[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        tmax[v] = lazy[v] = 0;
        tmin[v] = 0;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tmax[v] = max(tmax[v << 1], tmax[v << 1 | 1]);
        tmin[v] = min(tmin[v << 1], tmin[v << 1 | 1]);
        lazy[v] = 0;
    }
}

void push(int v)
{
    if(lazy[v])
    {
        tmax[v << 1] = tmin[v << 1] = lazy[v << 1] = lazy[v];
        tmax[v << 1 | 1] = tmin[v << 1 | 1] = lazy[v << 1 | 1] = lazy[v];
    }
    lazy[v] = 0;
}

int ans = 0;
void update(int v, int tl, int tr, int l, int r, int val)
{
    if(tl > r || tr < l)
        return;

    if(tl != tr)
        push(v);

    if(tmin[v] > val)
        return;

    if(l <= tl && tr <= r)
    {
        if(tmax[v] <= val)
        {
            ans += (tr - tl + 1);
            tmax[v] = tmin[v] = lazy[v] = val;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, r, val);
    update(v << 1 | 1, tm + 1, tr, l, r, val);
    tmax[v] = max(tmax[v << 1], tmax[v << 1 | 1]);
    tmin[v] = min(tmin[v << 1], tmin[v << 1 | 1]);
}

void cp()
{
    int n;
    cin >> n;
    ans = 0;
    build(1, 0, MAXN - 1);
    for(int i = 0; i < n; i++)
    {
        int l, r, h;
        cin >> l >> r >> h;
        update(1, 0, MAXN - 1, l, r - 1, h);
    }
    cout << ans << endl;
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