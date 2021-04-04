#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
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
        return point(x / s, y / s); // be careful, zero division error
    }
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
    // For integers
    // bool operator<(const point &p) const
    // {
    //     return x < p.x || (x == p.x && y < p.y);
    // }
    bool operator==(const point &p) const
    {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }
    // For integers
    // bool operator==(const point &p) const
    // {
    //     return x == p.x && y == p.y;
    // }
    ftype cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    ftype cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
};

double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Rotate vector P by a radians
point rotate(point p, double a)
{
    return point(p.x * cos(a) + p.y * sin(a), p.y * cos(a) - p.x * sin(a));
}

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

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

pair<double, point> find_circle(point a, point b, point c)
{
    point m1 = (a + b) * 0.5, v1 = b - a, pv1 = point(v1.y, -v1.x);
    point m2 = (c + b) * 0.5, v2 = b - c, pv2 = point(v2.y, -v2.x);

    point end1 = pv1 + m1, end2 = pv2 + m2;
    point center;

    intersect_segments(m1, end1, m2, end2, center);

    return {length(center, a), center};
}

void cp()
{
    int n, tc = 0;
    while(cin >> n && n)
    {
        vector<point> tri(3);
        for(auto &c : tri)
            cin >> c.x >> c.y;

        point C = find_circle(tri[0], tri[1], tri[2]).second;
        vector<point> poly(1, tri[0]);
        for(int i = 1; i < n; i++)
        {
            // take prev point, shift to origin, rotate, shift back
            point q = poly[i - 1];
            q.x -= C.x, q.y -= C.y;
            q = rotate(q, 2 * PI / n);
            q.x += C.x, q.y += C.y;
            poly.push_back(q);
        }

        double xmx = -DBL_MAX, xmn = DBL_MAX;
        double ymx = -DBL_MAX, ymn = DBL_MAX;

        for(auto c : poly)
        {
            xmx = max(xmx, c.x), xmn = min(xmn, c.x);
            ymx = max(ymx, c.y), ymn = min(ymn, c.y);
        }

        double area = (xmx - xmn) * (ymx - ymn);

        fix(3);
        cout << "Polygon " << ++tc << ": " << area << endl;
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
