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

bool is_square(ll x)
{
    return x == ll(sqrt(x)) * ll(sqrt(x));
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 1; i < n; i += 2)
        cin >> arr[i];

    bool ok = true;
    ll pref = 0;
    for(int i = 0; i < n && ok; i += 2)
    {
        ll y = arr[i + 1];
        ll best = LLONG_MAX;
        bool found = false;
        for(ll d = 1; d * d <= y; d++)
        {
            if(y % d) continue;
            ll p = y / d, q = d;
            if((p + q) % 2) continue;
            ll a = (p + q) / 2;
            ll b = abs((p - q) / 2);
            if(a < b) swap(a, b);
            if(b == 0) continue;
            if(pref >= b * b) continue;

            // y = a^2 - b^2
            found = true;
            best = min(best, a);
        }
        if(!found) ok = false;
        else arr[i] = best * best - y - pref, pref = best * best;
    }


    if(ok)
    {
        pref = 0;
        for(ll x : arr)
            pref += x, assert(is_square(pref) && x <= 1e13);
        cout << "Yes\n";
        for(ll x : arr)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "No\n";
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
