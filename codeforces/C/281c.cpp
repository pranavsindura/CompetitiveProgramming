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

bool intersect_segments(point a, point b, point c, point d, point &intersect)
{
    point origin(0, 0);
    double d1 = origin.cross(a - b, d - c), d2 = origin.cross(a - c, d - c), d3 = origin.cross(a - b, a - c);
    if(fabs(d1) < eps) return false; // Parallel || identical
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    if(t2 < -eps || t2 > 1 + eps)
        return false;
    return true;
}

pair<vector<point>, vector<point>> polygon_cut(vector<point> &p, point A, point B)
{
    vector<point> left, right;
    point inter;
    point seg = B - A;
    for(int i = 0; i < sz(p); i++)
    {
        point cur = p[i], nxt = p[(i + 1) % sz(p)];
        point v = cur - A;

        if(seg.cross(v) >= 0)
            left.pb(cur);

        if(seg.cross(v) <= 0)
            right.pb(cur);

        if(intersect_segments(A, B, cur, nxt, inter))
            right.pb(inter), left.pb(inter);

    }
    return mp(left, right);
}

double polygon_area(vector<point> &p)
{
    if(sz(p) < 3) return 0;
    point origin(0, 0);
    int n = sz(p);
    p.push_back(p[0]);
    double area = 0;
    for(int i = 0; i < n; i++)
        area += origin.cross(p[i], p[i + 1]);
    p.pop_back();
    return fabs(area / 2.0);
}

point rot(point p, double a)
{
    return point(p.x * cos(a) + p.y * sin(a), p.y * cos(a) - p.x * sin(a));
}

void cp()
{
    double w, h, a;
    cin >> w >> h >> a;
    a = a * PI / 180;
    vector<point> p = {point(w / 2, h / 2), point(-w / 2, h / 2), point(-w / 2, -h / 2), point(w / 2, -h / 2)};
    vector<point> q;
    for(point c : p)
        q.pb(rot(c, a));
    for(int i = 0; i < 4; i++)
        q = polygon_cut(q, p[i], p[(i + 1) % 4]).ff;
    double area = polygon_area(q);
    fix(15);
    cout << area << endl;
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

