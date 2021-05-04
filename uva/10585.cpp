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
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    map<pi, int> p;
    vector<ll> S = {0, 0};
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        S[0] += x, S[1] += y;
        p[ {x, y}] = 1;
    }
    bool ok = true;
    S[0] *= 2, S[1] *= 2;
    ok &= S[0] % n == 0 && S[1] % n == 0;
    S[0] /= n, S[1] /= n;
    for(auto c : p)
        ok &= p.count({S[0] - c.ff.ff, S[1] - c.ff.ss});
    cout << (ok ? "yes\n" : "no\n");
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
