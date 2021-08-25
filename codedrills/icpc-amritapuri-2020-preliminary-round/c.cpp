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

void cp()
{
    int n, x;
    cin >> n >> x;
    bool ok = true;
    vector<int> p;
    for(int i = 1; i < 30; i++)
        if((n >> i) & 1)
        {
            if(i & 1)
                p.push_back(i);
            else
                p.push_back(i - 1), p.push_back(i - 1);

        }
    if(n & 1)
        ok &= x > 0, p.push_back(0);

    sort(all(p));

    int cnt = 0, res = 0;
    for(int i = 0; i < sz(p); i++)
        if(res + (1 << p[i]) <= x)
            cnt++, res += 1 << p[i];
            
    cout << (ok ? min(sz(p), sz(p) - cnt + 1) : -1) << endl;
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
