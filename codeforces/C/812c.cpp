#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

ll f(ll k)
{
    return k * k * (k + 1) / 2;
}

void cp()
{
    int n;
    ll S;
    cin >> n >> S;
    vector<pi> arr(n);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = {x, i + 1};
    }

    int lo = 1, hi = n;
    int ans = 0;
    ll ans_cost = 0;

    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;

        sort(all(arr), [&](pi a, pi b)
        {
            return a.ff * 1LL + a.ss * 1LL * mid < b.ff * 1LL + b.ss * 1LL * mid;
        });

        ll cost = 0;
        for(int i = 0; i < mid; i++)
        {
            cost += arr[i].ff * 1LL + arr[i].ss * 1LL * mid;
            if(cost > S)
                break;
        }

        if(cost <= S)
        {
            //ok
            ans = mid;
            ans_cost = cost;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << " " << ans_cost;
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