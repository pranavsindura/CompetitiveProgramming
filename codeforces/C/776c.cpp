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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}

bool check(ll n, ll k)
{
	if(n == 0)
		return false;
    ll on = n, ok = k;

    if(k == 1)
        return n == 1;
    else if(k == -1)
        return abs(n) == 1;

    k = abs(k);
    n = abs(n);

    int exp = 0;
    while(n % k == 0)
        n /= k, exp++;
    if(n > 1)
        return false;
    return fpow(ok, exp) == on;
}

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    int times = 0;
    ll mx = LLONG_MAX;
    while(mx && abs(k) > 1)
        times++, mx /= abs(k);
    times--;
    
    if(k == -1)
        times = 1;
    else if(k == 1)
        times = 0;


    map<ll, int> cnt;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(check(sum, k))
            ans++;
        // we need to find sum-target in the cnt map
        for(int j = 0; j <= times; j++)
        {
            ll a = fpow(k, j);
            if(cnt.find(sum - a) != end(cnt))
                ans += cnt[sum - a];
        }
        cnt[sum]++;
    }
    cout << ans;
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