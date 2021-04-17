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

vector<ll> gen(ll mid, ll req, ll len)
{
    vector<ll> seq;
    ll sum = 0, p = mid;
    while(sum + p <= req) sum += p, seq.push_back(p), p += mid;
    seq.back() += req - sum;
    ll g = 0;
    for(ll x : seq) g = gcd(x, g);
    if(g == mid && sz(seq) >= len) return seq;
    return {};
}

void cp()
{
    ll n, k;
    cin >> n >> k;
    ll best = -1;
    for(ll i = 1; i * i <= n; i++)
    {
        if(n % i) continue;
        if(!gen(i, n, k).empty()) best = max(best, i);
        if(!gen(n / i, n, k).empty()) best = max(best, n / i);
    }
    if(best == -1) cout << -1 << endl;
    else
    {
        vector<ll> seq = gen(best, n, k);
        while(sz(seq) > k)
        {
            ll x = seq.back();
            seq.pop_back();
            seq.back() += x;
        }
        for(ll x : seq)
            cout << x << " ";
        cout << endl;
    }
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
