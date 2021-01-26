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
ll C[66][66];

void init()
{
    for(int i = 0; i < 66; i++)
        C[i][0] = 1;
    for(int i = 1; i < 66; i++)
        for(int j = 1; j < 66; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}

// __builtin_popcount doesnt work on long long :|
// oh, theres __builtin_popcountll
ll cnt(ll n, int k)
{
    ll ans = __builtin_popcountll(n) == k;
    int cnt = 0;
    for(int i = 63; i >= 0; i--)
    {
        if((n >> i) & 1)
        {
            if(k >= cnt)
                ans += C[i][k - cnt];
            cnt++;
        }
    }
    return ans;
}

void cp()
{
    ll m, k;
    cin >> m >> k;

    ll ans = -1;
    ll lo = 1, hi = 1e18;
    while(lo <= hi)
    {
        ll mid = lo + 0LL + (hi - lo) / 2;

        ll c = cnt(2 * mid, k) - cnt(mid, k);
        if(c >= m)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}