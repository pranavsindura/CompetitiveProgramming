#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define mt make_tuple
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

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<tuple<int, int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = mt(a, b, c);
    }
    sort(all(arr), [&](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<0>(a) < get<0>(b);
    });
    vector<ll> dp(n);
    ll best = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int lo = i + 1, hi = n - 1;
        int pos = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(get<0>(arr[mid]) > get<1>(arr[i]))
                pos = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        ll me = get<2>(arr[i]) + (~pos ? dp[pos] : 0);
        if(i + 1 < n)
            me = max(me, dp[i + 1]);
        dp[i] = me;
        best = max(me, best);
    }
    cout << best << endl;
    return 0;
}