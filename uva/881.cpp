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

// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Point inside Polygon
// Check using Winding Number Algorithm
// O(n)
// There exists O(logn) for convex polygons, precomputation is involved, Preparata Algorithm
// Is point P on segment AB
bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

bool is_inside_polygon(vector<point> &p, point p0)
{
    int wn = 0;
    for(int i = 0; i < sz(p); i++)
    {
        point cur = p[i], nxt = p[(i + 1) % sz(p)];
        if(is_point_on_segment(cur, nxt, p0))
            return true;
        if(cur.y <= p0.y) // Edge going up
        {
            if(nxt.y > p0.y && (nxt - cur).cross(p0 - cur) > eps)
                wn++;
        }
        else // Edge going Down
        {
            if(nxt.y <= p0.y && (nxt - cur).cross(p0 - cur) < -eps)
                wn--;
        }
    }
    return wn != 0;
}

// POLYGON AREA
// Points should be ordered CW/CCW
// Works for tricky inputs, duplicate points, collinear points
// Final summation > 0 -> CCW, < 0 -> CW
double polygon_area(vector<point> &p)
{
    point origin(0, 0);
    int n = sz(p);
    p.push_back(p[0]);
    double area = 0;
    for(int i = 0; i < n; i++)
        area += origin.cross(p[i], p[i + 1]);
    p.pop_back();
    return fabs(area / 2.0);
}

void cp()
{
    int n, m;
    cin >> n;
    cin.ignore();
    vector<int> pname(n + 1);
    vector<vector<point>> polygons(n + 1);
    vector<double> area(n + 1);
    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int k;
        ss >> k;
        pname[i] = k;
        double x, y;
        while(!ss.eof())
            ss >> x >> y, polygons[i].pb(point(x, y));
        area[i] = polygon_area(polygons[i]);
    }

    cin >> m;
    vector<pi> ans(m);
    for(int i = 0; i < m; i++)
    {
        int k;
        double x, y;
        cin >> k >> x >> y;
        int idx = 0;
        double best = DBL_MAX;
        for(int j = 1; j <= n; j++)
            if(is_inside_polygon(polygons[j], point(x, y)) && area[j] < best)
                idx = j, best = area[j];
        ans[i] = {k, pname[idx]};
    }
    sort(all(ans));
    for(auto x : ans)
        cout << x.ff << " " << x.ss << endl;
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
        if(t) cout << endl;
    }
    return 0;
}

