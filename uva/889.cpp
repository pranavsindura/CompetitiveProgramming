#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

// POINT
typedef double ftype;
// const ftype eps = 1e-9;
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
    point operator/(const ftype &s)
    {
        return point(x / s, y / s);
    }
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
    bool operator==(const point &p) const
    {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
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

double dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Simplified for integers
bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

// SHORTEST DISTANCE BETWEEN 2 POLYGONS
// O(n^2)
// Polygons intersect => 0
// Minimum of
// Shortest distance between two vertices
// Shortest distance between one vertex and one edge
// Project the vertex onto the edge and check if it lies on edge, then find distance
// https://www.hackerrank.com/contests/booking-womenintech/challenges/distance-between-two-polygons/submissions/code/1328360096
double polygon_shortest_distance(vector<point> &a, vector<point> &b)
{
    int n = sz(a), m = sz(b);
    // if(polygon_intersection(a, b)) return 0;
    a.pb(a.front()), b.pb(b.front());

    double ans = DBL_MAX;
    point C;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // point a[i] with point b[j]
            C = a[i];
            ans = min(ans, length(a[i], b[j]));
            // point a[i] with edge b[j] ---- b[j + 1]
            point A = b[j], B = b[j + 1];
            point AD = (B - A) * dp(B - A, C - A) / dp(B - A, B - A);
            point D = AD + A;
            if(is_point_on_segment(A, B, D))
                ans = min(ans, length(C, D));
            // point b[j] with edge a[i] ---- a[i + 1]
            C = b[j];
            A = a[i], B = a[(i + 1)];
            AD = (B - A) * dp(B - A, C - A) / dp(B - A, B - A);
            D = AD + A;
            if(is_point_on_segment(A, B, D))
                ans = min(ans, length(C, D));
        }
    }
    a.pop_back(), b.pop_back();
    return ans;
}

int parent[105], sz[105];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<point>> poly(n);
    for(int i = 0; i < n; i++)
    {
        int m, x, y;
        cin >> m;
        for(int j = 0; j < m; j++)
            cin >> x >> y, poly[i].pb(point(x, y));
    }
    vector<pair<double, pi>> edges;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                edges.pb({ polygon_shortest_distance(poly[i], poly[j]), {i, j}});
    sort(all(edges));
    make_set(n);
    double ans = 0;
    for(int i = 0; i < sz(edges); i++)
    {
        int u = edges[i].ss.ff, v = edges[i].ss.ss;
        if(union_set(u, v))
            ans += edges[i].ff;
    }
    fix(3);
    cout << "The minimal interconnect consists of " << n - 1 << " bridges with a total length of " << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

