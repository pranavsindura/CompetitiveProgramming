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

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    ll ans = n * 1LL * (n - 1) / 2;
    vector<int> cnt(1 << 10);
    for(ll x : arr)
    {
        int mask = 0;
        while(x)
        {
            int dig = x % 10;
            mask |= 1 << dig;
            x /= 10;
        }
        cnt[mask]++;
    }
    for(int i = 0; i < 1 << 10; i++)
        for(int j = 0; j < i; j++)
            if((i & j) == 0)
                ans -= cnt[i] * 1LL * cnt[j];
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