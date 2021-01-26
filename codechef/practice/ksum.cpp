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

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    ll lo = 1, hi = 5e14;
    ll kth_sum = -1;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        //mid is the kth largest sum
        vector<ll> pref;
        ll total = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            pref.pb(sum);
            // pref[r] - pref[l-1] >= kth_sum
            // count how many such pref[l-1] for fixed r
            // using BS
            int lo1 = 0, hi1 = i;
            int found = 0;
            while(lo1 <= hi1)
            {
                int mid1 = (lo1 + hi1) / 2;
                ll me = sum - (mid1 ? pref[mid1 - 1] : 0);
                if(me < mid)
                    hi1 = mid1 - 1;
                else
                    found = mid1 + 1, lo1 = mid1 + 1;
            }
            total += found;
        }

        if(total >= k)
            kth_sum = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    vector<ll> ans;
    vector<ll> pref;
    ll sum = 0;
    ll total = 0;
    for(int i = 0; i < n && total < k; i++)
    {
        sum += arr[i];
        pref.pb(sum);
        for(int j = 0; j <= i && total < k; j++)
        {
            ll me = sum - (j ? pref[j - 1] : 0);
            if(me >= kth_sum)
                ans.pb(me), total++;
            else
                break;
        }
    }
    sort(allr(ans));
    for(ll &x : ans)
        cout << x << " ";
    cout << endl;
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