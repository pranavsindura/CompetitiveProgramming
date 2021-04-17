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
using pi = pair<int, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 5e4 + 5;

int n;
ll total;
vector<pi> arr;
map<ll, ll> dp;
ll solve(int i, ll pro)
{
    if(pro > total) return 0;
    assert(pro > 0);
    if(dp.count(pro))
        return dp[pro];
    if(i == n)
    {
        int me = 0;
        ll temp = pro;
        for(int j = 0; j < n; j++)
            while(temp % arr[j].ff == 0)
                me += arr[j].ff, temp /= arr[j].ff;
        return total - me == pro ? pro : 0;
    }

    ll ans = 0;
    ll p = 0;
    ll B = 1;
    while(pro <= (total + B - 1) / B && p <= arr[i].ss)
    {
        ans = max(ans, solve(i + 1, pro * B));
        p++, B *= arr[i].ff;
    }
    return dp[pro] = ans;
}

void cp()
{
    total = 0;
    cin >> n;
    arr.resize(n);
    for(auto &x : arr)
        cin >> x.ff >> x.ss, total += x.ff * x.ss;
    dp.clear();
    cout << solve(0, 1) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
