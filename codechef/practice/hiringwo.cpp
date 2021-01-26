#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e8;
const int MAXN = 1e5 + 5;

int k, x;
vector<int> fact;
int product[1 << 10];
int dp[15][1 << 10];

int solve(int i, int mask)
{
    if(i == k)
        return (mask ? inf : 0);

    int &ret = dp[i][mask];
    if(~ret)
        return ret;

    int ans = inf;
    for(int msk = mask; msk; msk = (msk - 1) & mask)
        ans = min(ans, product[msk] + solve(i + 1, mask ^ msk));
    return ret = ans;
}

void cp()
{
    cin >> k >> x;
    fact.clear();
    int num = 1;
    while(x % 2 == 0)
        num *= 2, x /= 2;
    if(num > 1) fact.pb(num);
    for(int i = 3; i <= sqrt(x); i += 2)
    {
        num = 1;
        while(x % i == 0)
            num *= i, x /= i;
        if(num > 1) fact.pb(num);
    }
    if(x > 1)
        fact.pb(x);

    if(sz(fact) <= k)
    {
        int sum = 0;
        for(int f : fact)
            sum += f;
        sum += k - sz(fact);
        cout << sum << endl;
        return;
    }
    // sz(fact) can be atmost 10? now
    // partition the factors into k sets
    // minimise the sum of products
    for(int mask = 0; mask < (1 << sz(fact)); mask++)
    {
        product[mask] = 1;
        for(int i = 0; i < sz(fact); i++)
        {
            if((mask >> i) & 1)
                product[mask] *= fact[i];
        }
        for(int i = 0; i <= k; i++)
            dp[i][mask] = -1;
    }
    cout << solve(0, (1 << sz(fact)) - 1) << endl;
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