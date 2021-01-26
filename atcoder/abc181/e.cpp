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
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n), w(m);
    for(ll &x : arr)
        cin >> x;
    for(ll &x : w)
        cin >> x;
    
    sort(all(arr));
    vector<ll> odd(n), even(n);
    for(int i = 0; i < n; i++)
    {
        if(i & 1)
            odd[i] += arr[i];
        else
            even[i] += arr[i];
        odd[i] += (i ? odd[i - 1] : 0);
        even[i] += (i ? even[i - 1] : 0);
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i < m; i++)
    {
        int lo = 0, hi = n - 1;
        int pos = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(arr[mid] <= w[i])
                pos = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        ll o = (~pos ? odd[pos] : 0);
        ll e = (~pos ? even[pos] : 0);
        pos++;
        if(pos < n)
            o += even[n - 1] - (pos ? even[pos - 1] : 0);
        if(pos < n)
            e += odd[n - 1] - (pos ? odd[pos - 1] : 0);
        if(pos & 1)
            o += w[i];
        else
            e += w[i];
        ans = min(ans, o - e);
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