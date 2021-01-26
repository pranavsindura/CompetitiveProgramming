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
const int MAXN = 1e5 + 5;

void cp()
{
    int n, x, y;
    cin >> n >> x >> y;
    if(n == 1)
    {
        cout << "1 1\n";
        return;
    }
    int l = n, r = 1;
    int lo = 1, hi = n - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        int p = mid;
        int a = (p < x ? p : p + 1);
        int c = (y == n ? n - 1 : n);
        int can = a + c;
        a = (p < y ? p : p + 1);
        c = (x == n ? n - 1 : n);
        can = min(can, a + c);
        if(can > x + y)
            l = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }

    lo = 2, hi = n;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        int p = mid;
        int a = (1 < x ? 1 : 2);
        int c = (p - 1 < x ? p - 1 : p);
        int can = a + c;
        a = (1 < y ? 1 : 2);
        c = (p - 1 < y ? p - 1 : p);
        can = min(can, a + c);
        if(can <= x + y)
            r = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << l << " " << r << endl;
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

