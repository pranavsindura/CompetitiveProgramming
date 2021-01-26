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
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0, v = 0;
    for(ll &x : arr)
        cin >> x, sum += x, v ^= x;
    vector<ll> ans;

    if(sum > v * 2)
    {
        ll num = 1LL << 48;
        if(sum & 1)
            num++;
        ans.pb(num);
        sum += num;
        v ^= num;
    }

    if(sum < v * 2)
    {
        if(sum & 1)
        {
            ll num = 1LL << 49;
            if(sum & 1)
                num++;
            ans.pb(num);
            sum += num;
            v ^= num;
        }

        ll diff = 2 * v - sum;
        ans.pb(diff / 2);
        ans.pb(diff / 2);
    }

    sum = 0, v = 0;
    for(ll x : arr)
        sum += x, v ^= x;
    for(ll x : ans)
        sum += x, v ^= x;

    assert(sum == v * 2);
    for(ll x : ans)
        assert(x >= 0 && x <= 1e18);
    assert(sz(ans) <= 3);

    
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