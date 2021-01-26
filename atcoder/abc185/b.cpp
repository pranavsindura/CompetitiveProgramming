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
const int inf = 1e5;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<pi> arr(1, {INT_MIN, 0});
    for(int i = 0; i < m; i++)
        arr.pb({0, 0}), cin >> arr.back().ff >> arr.back().ss;
    arr.pb({t, INT_MAX});
    bool ok = true;
    int battery = n;
    for(int i = 1; i < sz(arr); i++)
    {
        int dec = arr[i].ff - arr[i - 1].ss; // decreases
        battery -= dec;
        ok &= battery > 0;
        int inc = arr[i].ss - arr[i].ff; // increases
        battery += inc;
        battery = min(battery, n);
    }
    cout << (ok ? "Yes\n" : "No\n");
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

