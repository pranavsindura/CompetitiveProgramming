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

void cp()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    vector<ll> mul(n);

    vector<vector<ll>> dp1(2, vector<ll>(n));
    vector<vector<ll>> dp2(2, vector<ll>(n));

    for(int i = 0; i < n; i++)
        dp1[0][i] = 1;

    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
        {
            if(j - 1 >= 0)
                dp1[i][j] += dp1[i - 1][j - 1], dp1[i][j] %= mod;
            if(j + 1 < n)
                dp1[i][j] += dp1[i - 1][j + 1], dp1[i][j] %= mod;
        }


    for(int i = 0; i < n; i++)
        dp2[k][i] = 1;

    for(int i = k - 1; i >= 0; i--)
        for(int j = 0; j < n; j++)
        {
            if(j - 1 >= 0)
                dp2[i][j] += dp2[i + 1][j - 1], dp2[i][j] %= mod;
            if(j + 1 < n)
                dp2[i][j] += dp2[i + 1][j + 1], dp2[i][j] %= mod;
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            mul[i] += (dp1[j][i] * dp2[j][i]) % mod, mul[i] %= mod;

    ll ans = 0;

    for(int i = 0; i < n; i++)
        ans += (mul[i] * arr[i]) % mod, ans %= mod;

    while(q--)
    {
        int idx, num;
        cin >> idx >> num;
        idx--;
        ans = (ans - (mul[idx] * arr[idx]) % mod + mod) % mod;
        arr[idx] = num;
        ans = (ans + (mul[idx] * arr[idx]) % mod) % mod;
        cout << ans << endl;
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

