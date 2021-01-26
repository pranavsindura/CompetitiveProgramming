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

/*
4
10 4 3
1000 11 2
998244353 897581057 595591169
10000 6 14
*/

ll G, x, y;
void ex_gcd(ll a, ll b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        G = a;
        return;
    }
    else
    {
        ex_gcd(b, a % b);
        ll temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}


void cp()
{
    int n, s, k;
    cin >> n >> s >> k;
    int pos = n - s;
    int g = __gcd(k, n);
    if(pos % g != 0)
    {
        cout << -1 << endl;
        return;
    }
    int A = k / g, N = n / g, B = pos / g;
    // AX mod N = B
    ex_gcd(A, N);
    ll inv = (x % N + N) % N;
    ll ans = (inv % N * B % N) % N;
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

