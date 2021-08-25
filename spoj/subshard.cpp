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
const int MAXN = 1e3 + 5;

// sum r * nCr = n * 2^(n - 1)
/*
111

1 1 1 = 3
11 11 11 = 33
111 = 111

147 % 9

sum d[i] * 11^i * 2^(n - i - 1)

1 -> 1 * 4

*/

ll p11[MAXN], p2[MAXN];
void init(ll m)
{
    p11[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p11[i] = (p11[i - 1] * 11) % m;
    // for(int i = 1; i < MAXN; i++)
    //     p11[i] = (p11[i - 1] + p11[i]) % m;
    p2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p2[i] = (p2[i - 1] * 2) % m;
}

void cp()
{
    string s;
    ll m;
    cin >> s >> m;
    reverse(all(s));
    init(m);

    ll ans = 0;
    for(int i = 0; i < ln(s); i++)
    {
        ll a = ((s[i] - '0') * p11[i]) % m;
        a = (a * p2[ln(s) - i - 1]) % m;
        ans = (ans + a) % m;
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
