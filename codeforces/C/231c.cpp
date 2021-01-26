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
    sort(allr(arr));

    // Making prefix
    vector<ll> pref;
    pref.pb(arr[0]);
    for(int i = 1; i < n; i++)
        pref.pb(pref.back() + arr[i]);

    // Times is max number of occurances
    // mn is the number who's occurances we count
    int times = 0, mn = 0;

    for(int i = 0; i < n; i++)
    {
        // Find max number of occurances you can get if you try to make all numbers smaller than
        // arr[i] equal to arr[i]
        int lo = i, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            ll sum = (i ? pref[mid] - pref[i - 1] : pref[mid]);
            ll len = mid - i + 1;

            if(len * arr[i] - sum <= k)
            {
                // can make len occurances of arr[i]
                // watch out for >= because smaller arr[i] with same length are also to be considered
                if(len >= times)
                    times = len, mn = arr[i];
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
    }
    cout << times << " " << mn;
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