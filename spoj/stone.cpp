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

// POLYGON CENTROID
// We use polygon decomposition to find the centroid
// We break the polygon into triangles containing origin and 2 vertices of a side
// Cx = sum(Cx_i * A_i) / sum(A_i)
// after some maths
// Cx = 1/6A * sum((x_i * x_i+1) * (x_i * y_i+1 - x_i+1 * y_i))
// Cy = 1/6A * sum((y_i * y_i+1) * (x_i * y_i+1 - x_i+1 * y_i))

point polygon_centroid(vector<point> &p)
{
    point origin(0, 0);
    double x = 0, y = 0, a = 0, c;
    int n = sz(p);
    p.push_back(p[0]);
    for(int i = 0; i < n; i++)
    {
        c = origin.cross(p[i], p[i + 1]), a += c;
        x += (p[i].x + p[i + 1].x) * c;
        y += (p[i].y + p[i + 1].y) * c;
    }
    p.pop_back();

    if(dcmp(a, 0) == 0) // Line
        return (p.front() + p.back()) * 0.5;
    a /= 2, x /= 6 * a, y /= 6 * a;

    // Fix Values
    if(dcmp(x, 0) == 0) x = 0;
    if(dcmp(y, 0) == 0) y = 0;

    return point(x, y);
}


void cp()
{
    int n;
    cin >> n;
    vector<point> p(n);
    for(point &c : p)
        cin >> c.x >> c.y;
    point C = polygon_centroid(p);
    fix(2);
    cout << C.x << " " << C.y << endl;
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
