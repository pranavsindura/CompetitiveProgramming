#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 998244353;
const int MAXN = 3e5 + 5;

ll fact[MAXN];

void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}

ll fpow(ll x, ll y)
{
    ll res  = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y = y / 2;
    }
    return res;
}

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

ll ncr(int n, int r)
{
    if(n < r)
        return 0;
    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * inv(fact[n - r]) % mod) % mod;
    ans = (ans % mod * inv(fact[r]) % mod) % mod;
    return ans;
}

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<pi> arr(n);

    for(pi &x : arr)
        cin >> x.ff >> x.ss;

    ll ans = 0;
    sort(all(arr));
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(pi &x : arr)
    {
        while(!pq.empty() && pq.top() < x.ff)
            pq.pop();
        ans = (ans + ncr(sz(pq), k - 1)) % mod;
        pq.push(x.ss);
    }

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}