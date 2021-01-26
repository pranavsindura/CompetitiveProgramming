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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
struct point
{
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
};

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}
// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool check_intersection(point c1, double r1, point c2, double r2)
{
    // Intersection occurs when distance between centers in <= r1+r2
    // Also check that circle does not lie inside circle
    double d = length(c1, c2);
    if(dcmp(d, r1 + r2) <= 0)
    {
        double rmin = r1;
        double rmax = r2;
        if(dcmp(rmin, rmax) > 0)
            swap(rmin, rmax);
        // if d + rmin <= rmax, smaller circle lies inside, we dont want that
        if(dcmp(d + rmin, rmax) <= 0)
            return false;
        else
            return true;
    }
    return false;
}

int n, comp;

void dfs(int u, vector<pair<point, double>> &circles, vector<bool> &vis)
{
    comp++;
    vis[u] = true;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i] && check_intersection(circles[u].ff, circles[u].ss, circles[i].ff, circles[i].ss))
            dfs(i, circles, vis);
    }
}

void cp()
{
    while(cin >> n && n >= 0)
    {
        vector<pair<point, double>> circles;
        for(int i = 0; i < n; i++)
        {
            double h, k, r;
            cin >> h >> k >> r;
            circles.pb({point(h, k), r});
        }
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                comp = 0;
                dfs(i, circles, vis);
                ans = max(ans, comp);
            }
        }
        if(ans != 1)
            cout << "The largest component contains " << ans << " rings.\n";
        else
            cout << "The largest component contains " << ans << " ring.\n";
    }
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