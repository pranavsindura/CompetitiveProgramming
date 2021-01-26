#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
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
const ll inf = 1LL << 30;
const int MAXN = 2e5 + 5;

int tmax[4 * MAXN], tmin[4 * MAXN], arr[MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        tmax[v] = tmin[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tmax[v] = max(tmax[v << 1], tmax[v << 1 | 1]);
        tmin[v] = min(tmin[v << 1], tmin[v << 1 | 1]);
    }
}

int rmax(int v, int tl, int tr, int l, int r)
{
    if(l > r) return -1;
    if(tl == l && tr == r)
        return tmax[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return max(rmax(v << 1, tl, tm, l, min(r, tm)), rmax(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }
}
int rmin(int v, int tl, int tr, int l, int r)
{
    if(l > r) return INT_MAX;
    if(tl == l && tr == r)
        return tmin[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return min(rmin(v << 1, tl, tm, l, min(r, tm)), rmin(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    int a, b, c;
    bool ok = false;
    int cur = -1;
    for(int i = 0; i < n && !ok; i++)
    {
        cur = max(cur, arr[i]);
        int idx = -1;
        
        int lo = i + 1, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int mn = rmin(1, 0, n - 1, i + 1, mid);
            int mx = rmax(1, 0, n - 1, mid + 1, n - 1);
            if(mx > cur)
                lo = mid + 1;
            else if(mx == cur)
            {
                if(mn > cur)
                    lo = mid + 1;
                else if(mn == cur)
                    idx = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else
                hi = mid - 1;
        }

        if(~idx)
        {
            ok = true;
            a = i + 1, b = idx - i, c = n - idx - 1;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
    if(ok)
        cout << a << " " << b << " " << c << endl;
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

