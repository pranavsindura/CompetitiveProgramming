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
const ll mod = 998244353;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

bool is_square(ll x)
{
    return (ll)sqrtl(x) * (ll)sqrtl(x) == x;
}
bool is_cube(ll x)
{
    return (ll)cbrtl(x) * (ll)cbrtl(x) * (ll)cbrtl(x) == x;
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    set<ll> pf;
    map<ll, int> freq;

    vector<ll> other;
    for(ll x : arr)
    {
        ll sq = sqrtl(x);
        if(is_square(x) && is_square(sq))
            pf.insert((ll)sqrtl(sq)), freq[(ll)sqrtl(sq)] += 4;
        else if(is_square(x))
            pf.insert(sq), freq[sq] += 2;
        else if(is_cube(x))
            pf.insert((ll)cbrtl(x)), freq[(ll)cbrtl(x)] += 3;
        else
            other.push_back(x);
    }

    for(int i = 0; i < sz(other); i++)
        for(int j = 0; j < sz(other); j++)
        {
            ll g = gcd(other[i], other[j]);
            if(g < min(other[i], other[j]) && g > 1)
                pf.insert(g), pf.insert(other[i] / g), pf.insert(other[j] / g);
        }

    map<ll, int> idk;
    for(auto x : other)
    {
        bool can = false;
        for(ll p : pf)
            if(x % p == 0)
            {
                freq[p]++;
                freq[x / p]++;
                can = true;
                break;
            }
        if(!can) idk[x]++;
    }

    ll ans = 1;
    for(auto x : freq)
        ans = (ans * (x.ss + 1)) % mod;
    for(auto x : idk)
        ans = (ans * (x.ss + 1)) % mod;
    for(auto x : idk)
        ans = (ans * (x.ss + 1)) % mod;

    cout << ans << endl;
    cout.flush();
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
