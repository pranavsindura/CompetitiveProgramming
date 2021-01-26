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

vector<array<int, 3>> arr;
int n;

ll cost(int i, int j)
{
    ll ans = 0;
    ans += abs(arr[i][0] - arr[j][0]);
    ans += abs(arr[i][1] - arr[j][1]);
    ans += max(0, arr[i][2] - arr[j][2]);
    return ans;
}

ll dp[18][1 << 17];

ll solve(int pos, int mask)
{
    if(mask == ((1 << n) - 1))
        // go to city 1
        return cost(pos, 0);

    ll &ret = dp[pos][mask];
    if(~ret)
        return ret;

    ll ans = INT_MAX;
    // go to some unvisited city
    for(int i = 0; i < n; i++)
        if(((mask >> i) & 1) == 0)
            ans = min(ans, cost(pos, i) + solve(i, mask | (1 << i)));

    return ret = ans;
}

void cp()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    clr(dp, -1);
    ll ans = solve(0, 1);
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