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

vector<pair<ll, int>> points;

void cp()
{
    vector<ll> a(6);
    for(ll &x : a)
        cin >> x;
    int n;
    cin >> n;
    vector<ll> b(n);
    for(ll &x : b)
        cin >> x;

    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            ll fret = b[i] - a[j];
            points.pb({fret, i});
        }
    }
    sort(all(points));

    ll best = LLONG_MAX;

    map<int, int> cnt;

    int l = 0, r = 0;
    cnt[points[r].ss]++;
    while(r < sz(points))
    {
        while(sz(cnt) < n && r + 1 < sz(points))
        {
            r++;
            cnt[points[r].ss]++;
        }

        while(sz(cnt) >= n)
        {
            best = min(best, points[r].ff - points[l].ff);
            cnt[points[l].ss]--;
            if(cnt[points[l].ss] == 0)
                cnt.erase(points[l].ss);
            l++;
        }
        r++;
        if(r < sz(points))
            cnt[points[r].ss]++;
    }

    cout << best << endl;
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