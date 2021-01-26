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

const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n), pref(n);
    for(ll &x : arr)
        cin >> x;
    for(int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    pref[0] = max(0LL, arr[0]);
    for(int i = 1; i < n; i++)
        pref[i] = max(pref[i - 1], arr[i]);
    ll ans = 0;
    ll pos = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, pos + pref[i]);
        pos += arr[i];
    }

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