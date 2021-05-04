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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

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
    int n;
    ll C;
    cin >> n >> C;
    vector<ll> a(n), b(n - 1);
    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;
    
    vector<ll> days(n), money(n);
    for(int i = 1; i < n; i++)
    {
        // earn enough so that money[i - 1] >= b[i - 1]
        ll diff = max(0LL, b[i - 1] - money[i - 1]);
        ll d = (diff + a[i - 1] - 1) / a[i - 1];
        money[i] = money[i - 1] + d * a[i - 1] - b[i - 1];
        days[i] = days[i - 1] + d + 1;
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        ll diff = max(0LL, C - money[i]);
        ll d = (diff + a[i] - 1) / a[i];
        ans = min(ans, days[i] + d);
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
