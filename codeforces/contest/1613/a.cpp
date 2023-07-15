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

int dig(int n)
{
    int cnt = 0;
    while(n) cnt++, n /= 10;
    return cnt;
}

void cp()
{
    int A, P, B, Q;
    cin >> A >> P >> B >> Q;

    if(dig(A) + P != dig(B) + Q)
    {
        cout << (dig(A) + P > dig(B) + Q ? ">" : "<") << endl;
    }
    else
    {
        string X = to_string(A);
        string Y = to_string(B);
        while(ln(X) < ln(Y) && P > 0) X += '0', P--;
        while(ln(Y) < ln(X) && Q > 0) Y += '0', Q--;
        assert(ln(X) == ln(Y));

        if(X != Y) cout << (X > Y ? ">" : "<") << endl;
        else cout << "=" << endl;
    }
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
