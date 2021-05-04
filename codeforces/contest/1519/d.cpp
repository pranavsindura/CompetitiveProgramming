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
const int MAXN = 5e3 + 5;

ll dp[MAXN][MAXN];

void cp()
{
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    for(ll &x : A)
        cin >> x;
    for(ll &x : B)
        cin >> x;

    vector<ll> pref(n), suff(n);
    pref[0] = A[0] * B[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + A[i] * B[i];
    suff[n - 1] = A[n - 1] * B[n - 1];
    for(int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + A[i] * B[i];

    for(int i = 0; i < n; i++)
        dp[i][i] = A[i] * B[i];

    for(int i = 0; i < n - 1; i++)
        dp[i][i + 1] = A[i] * B[i + 1] + A[i + 1] * B[i];

    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 2; j < n; j++)
            dp[i][j] = dp[i + 1][j - 1] + A[i] * B[j] + A[j] * B[i];

    ll best = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            ll me = dp[i][j];
            me += i ? pref[i - 1] : 0;
            me += j + 1 < n ? suff[j + 1] : 0;
            best = max(best, me);
        }
    cout << best << endl;
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
