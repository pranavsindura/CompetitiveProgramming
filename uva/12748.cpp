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
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y) {}
};

bool inside(point c, int r, point test)
{
    return ((c.x - test.x) * (c.x - test.x) + (c.y - test.y) * (c.y - test.y) <= r * r);
}

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<pair<point, int>> arr;
    for(int i = 0; i < n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        arr.pb({point(x, y), r});
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        bool ok = false;
        for(int i = 0; i < n; i++)
            if(inside(arr[i].ff, arr[i].ss, point(x, y)))
                ok = true;
        cout << (ok ? "Yes\n" : "No\n");
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    int test = 1;
    while(t--)
    {
        cout << "Case " << test++ << ":\n";
        cp();
    }
    return 0;
}