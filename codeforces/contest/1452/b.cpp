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

void cp()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x, sum += x;
    ll mx = *max_element(all(arr));

    ll rem = ((n - 1) - sum % (n - 1)) % (n - 1);
    ll lo = 0, hi = 1e9;
    ll best = 0;
    while(lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        if((sum + mid * (n - 1) + rem) / (n - 1) >= mx)
            best = mid * (n - 1) + rem, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << best << endl;
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