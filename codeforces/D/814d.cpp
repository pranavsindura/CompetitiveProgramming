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

typedef double ftype;

struct point
{
    ftype x, y;
    point() {}
    point(ftype x, ftype y): x(x), y(y) {}
    point operator+(const point &p)
    {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p)
    {
        return point(x - p.x, y - p.y);
    }
    point operator*(const ftype &s)
    {
        return point(x * s, y * s);
    }
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
    ftype cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    ftype cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
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

bool check_inside(point c1, double r1, point c2, double r2)
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
            return true;
        else
            return false;
    }
    return false;
}

double dp[1005][2][2];
vector<pair<point, double>> circles;

double dfs(int u, int depth0, int depth1, vector<vector<int>> &adj)
{
    double &ret = dp[u][depth0][depth1];
    if(!isnan(ret))
        return ret;

    double val = PI * circles[u].ss * circles[u].ss;

    // Place in group 0
    double c1 = (depth0 ? -1 : 1) * val;
    for(int v : adj[u])
        c1 += dfs(v, depth0 ^ 1, depth1, adj);

    // Place in group 1
    double c2 = (depth1 ? -1 : 1) * val;
    for(int v : adj[u])
        c2 += dfs(v, depth0, depth1 ^ 1, adj);

    return ret = max(c1, c2);
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;
        circles.pb({point(x, y), r});
    }

    sort(all(circles), [&](pair<point, double> a, pair<point, double> b)
    {
        return a.ss > b.ss;
    });

    vector<vector<int>> adj(n);
    vector<int> roots;
    for(int i = 0; i < n; i++)
    {
        bool placed = false;

        for(int j = i - 1; j >= 0 && !placed; j--)
            if(check_inside(circles[i].ff, circles[i].ss, circles[j].ff, circles[j].ss))
                adj[j].pb(i), placed = true;

        if(!placed)
            roots.pb(i);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = nan("");

    for(int x : roots)
        dfs(x, 0, 0, adj);

    double ans = 0;
    for(int x : roots)
        ans += dp[x][0][0];

    cout << setprecision(15) << fixed << ans;
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