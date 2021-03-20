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
const int MAXN = 5e6 + 5;

// Smallest Prime Factor
int lp[MAXN];
vector<int> prime;
void sieve()
{
    lp[0] = lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i]) lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

ll F[MAXN];
void cp()
{
    int t, l, r;
    cin >> t >> l >> r;

    sieve();
    F[1] = 0;
    for(int i = 2; i < MAXN; i++)
        F[i] = i * 1LL * (lp[i] - 1) / 2 + F[i / lp[i]], F[i] %= mod;

    ll ans = 0;
    ll p = 1;
    for(int i = l; i <= r; i++)
        ans = (ans + (p * F[i]) % mod) % mod, p = (p * t) % mod;
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
