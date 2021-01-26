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

// for a given dx, what is the highest y coordinate that we need to cross?
int highest_spot[MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<pi> a(n), b(m);
    for(auto &x : a)
        cin >> x.ff >> x.ss;
    for(auto &x : b)
        cin >> x.ff >> x.ss;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x = b[j].ff - a[i].ff;
            int y = b[j].ss - a[i].ss + 1;
            // if dx <= c[j] - a[i], then dy >= d[j] - b[i] + 1
            // for any dx in [0, x], we need to cross this y coord
            // if we choose this dx for all of our points, we need to cross the maximum y
            // that is, we should maximise the y for the range [0, x]
            if(x >= 0 && y >= 0)
                highest_spot[x] = max(highest_spot[x], y);
        }
    }

    for(int i = MAXN - 2; i >= 0; i--)
        highest_spot[i] = max(highest_spot[i + 1], highest_spot[i]);

    int ans = INT_MAX;
    for(int i = 0; i < MAXN; i++)
        ans = min(ans, i + highest_spot[i]);
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