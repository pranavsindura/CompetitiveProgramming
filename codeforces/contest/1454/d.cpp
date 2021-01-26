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
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

void cp()
{
    ll n;
    cin >> n;
    map<ll, int> fact;
    while(n % 2 == 0)
        fact[2]++, n /= 2;
    for(ll i = 3; i * i <= n; i++)
        while(n % i == 0)
            fact[i]++, n /= i;
    if(n > 1) fact[n]++;

    vector<pair<ll, int>> arr(all(fact));
    sort(all(arr), [&](pair<ll, int> a, pair<ll, int> b)
    {
        return a.ss < b.ss;
    });

    vector<ll> ans(arr.back().ss, 1);
    for(int i = 0; i < sz(arr); i++)
    {
        ll num = arr[i].ff;
        int freq = arr[i].ss;
        for(int j = 0; j < freq; j++)
            ans[sz(ans) - j - 1] *= num;
    }

    cout << sz(ans) << endl;
    for(ll x : ans)
        cout << x << " ";
    cout << endl;
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

