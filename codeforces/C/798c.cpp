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

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    ll g = 0;
    for(ll x : arr)
        g = gcd(x, g);

    if(g > 1)
    {
        cout << "YES\n0\n";
        return;
    }

    int ops = 0;
    for(int i = 0; i < n - 1; i++)
        if(abs(arr[i]) % 2 && abs(arr[i + 1]) % 2)
            ops++, arr[i + 1] += arr[i], arr[i] = 2 * arr[i] - arr[i + 1];

    for(int i = 0; i < n - 1; i++)
        if(abs(arr[i]) % 2 && abs(arr[i + 1]) % 2)
            ops++, arr[i + 1] += arr[i], arr[i] = 2 * arr[i] - arr[i + 1];
        else if(abs(arr[i]) % 2 == 0 && abs(arr[i + 1]) % 2 == 0) {}
        else ops++, arr[i + 1] += arr[i], arr[i] = 2 * arr[i] - arr[i + 1], i--;

    g = 0;
    for(ll x : arr)
        g = gcd(abs(x), g);

    if(g > 1)
        cout << "YES\n" << ops << endl;
    else
        cout << "NO\n";
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
