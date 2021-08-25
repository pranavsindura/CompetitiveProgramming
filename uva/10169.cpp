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
const int MAXN = 1e6 + 5;

array<double, MAXN> p;
array<int, MAXN> z;
void cp()
{
    double allred = 1, nored = 1;
    int zero = 0;
    for(int i = 1; i < MAXN; i++)
    {
        double me = double(i - 1) / double(i + 1);
        me += 1. / double(i + 1);
        me += double(i - 1) / (double(i) * double(i + 1));
        nored *= me;
        allred *= 1. / (i * 1. * (i + 1));
        while(allred < 1.)
            allred *= 10, zero++;
        allred /= 10, zero--;
        p[i] = 1. - nored;
        z[i] = zero;
    }

    int n;
    fix(6);
    while(cin >> n)
        cout << p[n] << " " << z[n] << endl;
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
