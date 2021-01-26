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
    cin >> n;
    ll total = 0;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x, total += x;
    if(abs(total) % 3 != 0)
    {
        cout << "0";
        return;
    }
    total = total / 3;
    vector<int> pref, suff;
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == total)
            pref.pb(i);
    }
    sum = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        sum += arr[i];
        if(sum == total)
            suff.pb(i);
    }
    ll ways = 0;
    for(int pos : suff)
    {
        // find the largest i in pref s.t i < pos-1
        int lo = 0, hi = sz(pref) - 1;
        int num = 0;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(pref[mid] < pos - 1)
            {
                num = mid + 1;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        ways += num;
    }
    cout << ways;
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