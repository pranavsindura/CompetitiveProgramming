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


void cp()
{
    int n;
    cin >> n;
    vector<pi> arr(n);

    for(int i = 0, l, p; i < n; i++)
        cin >> arr[i].ff >> arr[i].ss;

    sort(all(arr), [&](pi a, pi b)
    {
        double pa = a.ss / 100.0;
        double pb = b.ss / 100.0;
        return a.ff * pa / (1 - pa) > b.ff * pb / (1 - pb);
    });
    ld pref = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        ld p = arr[i].ss / 100.0;
        ld len = arr[i].ff;
        ans += pref * (1 - p);
        ans += len;
        pref += len * p;
    }
    dblout(10);
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