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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    ll ans = 0;
    ll lo = 0, hi = 5e14;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        // mid is the sum of the kth maxsumsubarray
        vector<ll> pref;
        ll total = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            // pref[r] - pref[l-1] <= mid
            pref.pb(sum);

            ll found = 0;
            int lo1 = 0, hi1 = sz(pref) - 1;
            while(lo1 <= hi1)
            {
                int mid1 = (lo1 + hi1) / 2;
                ll curr_sum = sum - (mid1 ? pref[mid1 - 1] : 0);
                if(curr_sum <= mid)
                    found = sz(pref) - mid1, hi1 = mid1 - 1;
                else
                    lo1 = mid1 + 1;
            }
            // subarrays with sum <= mid ending at i are found
            total += found;
        }

        if(total >= k)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans;
}

int main()
{
    FASTIO;
    // time_t t1, t2;
    // t1 = clock();
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    // t2 = clock();
    // cerr << endl << "time taken: " << (long double) (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}