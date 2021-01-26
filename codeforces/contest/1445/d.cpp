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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 998244353;
const int MAXN = 3e5 + 5;

/*
	f(p, q) is always the same no matter what subseq we pick?
	arr = a1 a2 a3 a4, sorted
	consider split
	p = a1 a2
	q = a4 a3
	f(p,q) = a4 - a1 + a3 - a2
	consider split
	p = a1 a3
	q = a4 a2
	f(p,q) = a4 - a1 + a3 - a2, same

	arr = a1 a2 a3 a4 a5 a6, sorted
	consider split
	p = a1 a2 a5
	q = a6 a4 a3
	f(p,q) = a6 - a1 + a4 - a2 + a5 - a3
	consider split
	p = a1 a4 a6
	q = a5 a3 a2
	f(p,q) = a5 - a1 + a4 - a3 + a6 - a2 = a6 - a1 + a4 - a2 + a5 - a3, same
	Right half is always added, left half is always subtracted
	This means that the answer is this value times the number of such splits
*/


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
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    ll val = 0;
    for(int i = 0; i < n; i++)
        val -= arr[i];
    for(int i = n; i < 2 * n; i++)
        val += arr[i];
    val %= mod;
    ll ans = (val * ncr(2 * n, n)) % mod;
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}