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
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

vector<ll> arr;
vector<ll> len[12];

int dig(ll n)
{
    int p = 0;
    while(n)
        p++, n /= 10;
    return p;
}

int cnt(int i, int need)
{
    int last = 0, first = 0;
    int lo = 0, hi = sz(len[i]) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if(len[i][mid] <= need)
            last = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }
    
    lo = 0, hi = sz(len[i]) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if(len[i][mid] < need)
            first = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }

    return last - first;
}

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    arr.resize(n);
    for(ll &x : arr)
        cin >> x, len[dig(x)].pb(x % k);

    ll po10[12];
    po10[0] = 1;

    for(int i = 1; i <= 10; i++)
        sort(all(len[i]));

    for(int i = 1; i <= 10; i++)
        po10[i] = (po10[i - 1] * 10) % k;

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll x = arr[i] % k;
        for(int j = 1; j <= 10; j++)
        {
            ll me = (x * po10[j]) % k;
            ll need = (k - me) % k;
            ans += cnt(j, need);
        }
    }
    for(int i = 0; i < n; i++)
    {
        ll x = arr[i] % k;
        int a = dig(arr[i]);
        ll me = (x * po10[a]) % k;
        ll need = (k - me) % k;
        if(x == need)
            ans--;
    }
    cout << ans << endl;
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