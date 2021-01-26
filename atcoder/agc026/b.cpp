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

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void cp()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ok = d >= b && a >= b;
    if(c >= b) // ok, no change
    {}
    else // c < b
    {
        // take A mod B
        // If > C, then we cannot sustain as A mod B < B and if it is > C then we cannot have enough cans
        // If <= C, we add D and repeat
        // Is (A + kD) mod B <= C always true?
        // C < B
        // Find the largest value of -> A + kD mod B
        // If it is > C then we will lose
        // we will always do steps of S = gcd(B, D)
        // (A mod B) + k (S mod B) > C
        // Is there such k present
        // A mod B + k (S mod B) < B
        // find largest k
        ll s = gcd(b, d);
        a %= b;
        ll k = (b - a + s - 1) / s - 1;
        ll val = a + k * s;
        if(val > c)
        	ok = false;
    }
    cout << (ok ? "Yes\n" : "No\n");
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

