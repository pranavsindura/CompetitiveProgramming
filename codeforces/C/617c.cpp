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


struct point
{
    ll x, y;
    point() {}
    point(ll x, ll y): x(x), y(y) {}
};

ll len2(point a, point b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool inside(point c, ll rsqr, point test)
{
    return len2(c, test) <= rsqr;
}

void cp()
{
    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    point c1(x, y);
    cin >> x >> y;
    point c2(x, y);
    ll r1 = 0, r2 = 0; // both are squared
    vector<point> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        point a(x, y);
        arr.pb(a);
    }
    ll mn = LLONG_MAX;
    arr.pb(c1);
    sort(all(arr), [&](point a, point b)
    {
        return len2(a, c1) < len2(b, c1);
    });
    for(int i = 0; i <= n; i++)
    {
        ll r1 = len2(c1, arr[i]);
        ll r2 = 0;
        for(int j = i + 1; j <= n; j++)
            r2 = max(r2, len2(c2, arr[j]));
        mn = min(mn, r1 + r2);
    }
    cout << mn;
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