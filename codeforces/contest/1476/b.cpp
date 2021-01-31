#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    ll ans = 0;
    ll lo = 0, hi = 1e14;
    while(lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        vector<ll> me = arr;
        me[0] += mid;
        bool ok = true;
        ll pref = me[0];
        for(int i = 1; i < n; i++)
        {
            if(me[i] * 100 > k * pref)
                ok = false;
            pref += arr[i];
        }

        if(ok)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
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

