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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;

void cp()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> arr(1, n);
    ll p = 1;
    for(int i = 0; i <= 18; i++)
    {
        ll num = n / p;
        num *= p;
        num += p;
        p *= 10;
        arr.pb(num);
    }
    ll ans = LLONG_MAX;

    for(ll x : arr)
    {
        ll temp = x;
        ll sum = 0;
        while(temp)
            sum += temp % 10, temp /= 10;
        // cout << x << " " << sum << endl;
        if(sum <= s)
            ans = min(ans, x - n);
    }
    cout << ans << endl;
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