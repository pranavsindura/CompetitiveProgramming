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

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

void cp()
{
    ll sy, A, B;
    int n, q;
    cin >> sy >> A >> B >> n;
    vector<pair<ll, ll>> arr(n);
    for(auto &x : arr)
        cin >> x.ff >> x.ss;
    vector<ll> pref;
    pref.pb(arr.front().ss - arr.front().ff);
    for(int i = 1; i < n; i++)
        pref.pb(pref.back() + arr[i].ss - arr[i].ff);
    cin >> q;
    double total_time = B - A;
    cout << setprecision(10) << fixed;
    while(q--)
    {
        ll x, y;
        cin >> x >> y;
        // join (x,y) to (A, sy)
        double a = y - sy;
        double b = A - x;
        double c = -a * x - b * y;
        double x1 = -c / a;
        // join (x,y) to (B, sy)
        b = B - x;
        c = -a * x - b * y;
        double x2 = -c / a;

        int l = n;
        int lo = 0, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(dcmp(arr[mid].ss, x1) >= 0)
                l = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        int r = -1;
        lo = 0, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(dcmp(arr[mid].ff, x2) <= 0)
                r = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }

        if(l > r)
        {
            cout << 0. << endl;
            continue;
        }
        double total = x2 - x1;
        double inshade = pref[r] - (l ? pref[l - 1] : 0);
        // remove excess
        if(dcmp(arr[l].ff, x1) <= 0)
            inshade -= x1 - arr[l].ff;
        if(dcmp(arr[r].ss, x2) >= 0)
            inshade -= arr[r].ss - x2;
        double ans = inshade * total_time / total;
        cout << ans << endl;
    }
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