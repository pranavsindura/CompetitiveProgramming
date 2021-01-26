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
const int MAXN = 2e5 + 5;

vector<ll> levels;
vector<pi> leftmost, bottommost;

ll dp[MAXN][2];

ll solve(int i, int left)
{
    if(i == sz(levels))
        return 0;

    ll &ret = dp[i][left];
    if(~ret)
        return ret;

    ll ans = LLONG_MAX;
    ll x, y;
    if(left)
        // i am at leftmost
        x = leftmost[i - 1].ff, y = leftmost[i - 1].ss;
    else
        // i am at bottommost
        x = bottommost[i - 1].ff, y = bottommost[i - 1].ss;

    ll dist = abs(leftmost[i].ff - bottommost[i].ff) + abs(leftmost[i].ss - bottommost[i].ss);
    // try going to leftmost of me
    ll nx = leftmost[i].ff, ny = leftmost[i].ss;
    ll c = abs(nx - x) + abs(ny - y) + dist;
    ans = min(ans, c + solve(i + 1, 0));

    // try going to bottommost of me
    nx = bottommost[i].ff, ny = bottommost[i].ss;
    c = abs(nx - x) + abs(ny - y) + dist;
    ans = min(ans, c + solve(i + 1, 1));

    return ret = ans;
}

void cp()
{
    int n;
    cin >> n;

    vector<pi> points(n + 1);
    points[0] = {0, 0};
    for(int i = 1; i <= n; i++)
        cin >> points[i].ff >> points[i].ss;

    map<int, vector<pi>> by_level;
    for(pi &x : points)
    {
        int lev = max(x.ff, x.ss);
        by_level[lev].pb(x);
    }

    for(auto &v : by_level)
    {
        levels.pb(v.ff);
        // Sort by X coords, if same, take highest point
        sort(all(v.ss), [&](pi a, pi b)
        {
            if(a.ff != b.ff)
                return a.ff < b.ff;
            else
                return a.ss > b.ss;
        });
        leftmost.pb(v.ss.front());

        // Sort by Y coords, if same, take rightmost point
        sort(all(v.ss), [&](pi a, pi b)
        {
            if(a.ss != b.ss)
                return a.ss < b.ss;
            else
                return a.ff > b.ff;
        });
        bottommost.pb(v.ss.front());
    }
    clr(dp, -1);
    ll ans = solve(1, 0);
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