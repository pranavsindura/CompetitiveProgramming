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

ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % m * x % m) % m;
        x = (x % m * x % m) % m;
        y >>= 1;
    }
    return res;
}

void cp()
{
    ll p;
    int n;
    while(cin >> p >> n && p + n)
    {
        vector<ll> num(n);
        for(ll &x : num)
            cin >> x;

        vector<ll> pf;
        ll N = p - 1; // phi(p)
        if(N % 2 == 0)
        {
            pf.push_back(2);
            while(N % 2 == 0) N /= 2;
        }
        for(int i = 3; i <= sqrt(N); i += 2)
        {
            if(N % i == 0)
            {
                pf.push_back(i);
                while(N % i == 0) N /= i;
            }
        }
        if(N > 1) pf.push_back(N);

        for(ll x : num)
        {
            bool ok = true;
            for(ll f : pf)
                ok &= fpow(x, (p - 1) / f, p) != 1;
            ok &= fpow(x, p - 1, p) == 1;
            cout << (ok ? "YES\n" : "NO\n");
        }
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

