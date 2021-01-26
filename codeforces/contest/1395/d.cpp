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
    int n, d, m;
    cin >> n >> d >> m;
    vector<ll> small, big;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x > m)
            big.pb(x);
        else
            small.pb(x);
    }

    sort(all(big));
    sort(all(small));
    big.pb(0), small.pb(0);
    reverse(all(small));
    reverse(all(big));


    for(int i = 1; i < sz(small); i++)
        small[i] += small[i - 1];
    for(int i = 1; i < sz(big); i++)
        big[i] += big[i - 1];

    ll ans = LLONG_MIN;

    for(int i = 0; i < sz(small); i++)
    {
        ll sum = small[i];
        int rem = n - i;
        int can = (rem + (d + 1) - 1) / (d + 1);
        can = min(can, sz(big) - 1);
        sum += big[can];
        ans = max(ans, sum);
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