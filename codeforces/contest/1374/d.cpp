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
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    map<ll, int> freq;
    bool any = false;

    for(ll x : arr)
    {
        if(x % k == 0)
            continue;
        any = true;
        ll div = x / k;
        div++;
        div *= k;
        freq[div - x]++;
    }

    ll mx = 0;
    for(auto x : freq)
    {
        ll num = x.ff + (x.ss - 1) * k;
        mx = max(mx, num);
    }
    
    if(any)
        cout << mx + 1 << endl;
    else
        cout << 0 << endl;
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