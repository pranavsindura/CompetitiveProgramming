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
    vector<ll> a(n), b(n);
    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;
    vector<ll> arr;
    for(int i = 0; i < n; i++)
        arr.pb(a[i] - b[i]);
    sort(all(arr));
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int lo = 0, hi = n - 1;
        int found = 0;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(arr[mid] > -arr[i])
                found = n - mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        if(arr[i] > 0)
            found--;
        ans += found;
    }
    cout << ans / 2 << endl;
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