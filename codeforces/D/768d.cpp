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
const double eps = 1e-7;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e3 + 5;

ld dp[MAXN];
int ans[MAXN];
void cp()
{
    int k, q;
    cin >> k >> q;
    dp[0] = 1;
    int p = 1;
    for(int i = 1; p <= 1000; i++)
    {
        for(int j = k; j >= 1; j--)
        {
            dp[j] = dp[j - 1] * ld(k - j + 1) / ld(k) +
                    dp[j] * ld(j) / ld(k);
        }
        while(p <= 1000 && dp[k] * 2000 >= (p - eps))
            ans[p] = i, p++;
        dp[0] = 0;
    }
    while(q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
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
