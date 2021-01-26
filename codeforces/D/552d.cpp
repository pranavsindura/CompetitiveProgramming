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

int sg(int x)
{
    return (x >= 0 ? 1 : -1);
}

pi get_slope(int dy, int dx)
{
    if(dy && dx)
    {
        int sgy = sg(dy), sgx = sg(dx);
        dy = abs(dy), dx = abs(dx);

        int g = __gcd(dy, dx);
        dy /= g, dx /= g;

        if(sgy != sgx)
            dy = -dy;
        return {dy, dx};
    }
    else if(dy)
        return {1, 0};
    else if(dx)
        return {0, 1};
    else
        return {0, 0};
}

void cp()
{
    int n;
    cin >> n;
    vector<pi> arr(n);
    for(pi &x : arr)
        cin >> x.ff >> x.ss;

    sort(all(arr));

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        map<pi, int> cnt;
        for(int j = i + 1; j < n; j++)
        {
            int dy = arr[j].ss - arr[i].ss;
            int dx = arr[j].ff - arr[i].ff;
            pi slope = get_slope(dy, dx);
            cnt[slope]++;
        }
        // Pick A = arr[i] as one vertex
        // we can pick 2 vertices B and C such that
        // AB and AC have different slopes
        // Count the number of points in each slope
        // suppose 5 points make a slope s1 with A
        // and 6 points make a slope s2 with A
        // s1 != s2
        // then we can pick one point from each and make a triangle
        // we have to make pairs
        // only freq of each slope matters
        // if my freq = {a,b,c,d}
        // total = ab+ac+ad+bc+bd+cd
        //       = a(b+c+d) + b(c+d) + d(0)
        // used prefix sum for this
        ll me = 0;

        vector<int> freq;
        for(auto &slope : cnt)
            freq.pb(slope.ss);
        int m = sz(freq);
        if(freq.empty())
            continue;

        vector<int> pref;
        pref.pb(freq.front());
        for(int j = 1; j < m; j++)
            pref.pb(pref.back() + freq[j]);

        for(int j = 0; j < m; j++)
            me += freq[j] * 1LL * (pref[m - 1] - pref[j]);
        ans += me;
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