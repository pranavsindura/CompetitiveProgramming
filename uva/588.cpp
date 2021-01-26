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

bool intersectSegments(point a, point b, point c, point d, point &intersect)
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

// POLYGON CUT
// We can see which set each point belongs to, based on the CCW test
// If the side intersects the line BA then the intersection belongs to both sets
// assumes points in P are in CCW order

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
            right.pb(cur);

        if(intersectSegments(A, B, cur, nxt, inter))
            right.pb(inter), left.pb(inter);

        if(seg.cross(v) <= 0)
            left.pb(cur);
    }

    return mp(left, right);
}

void cp()
{
    int tc = 0;
    int n;
    while(cin >> n && n)
    {
        vector<point> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        reverse(all(p));

        vector<point> sub = p;
        for(int i = 0; i < n; i++)
            sub = polygon_cut(sub, point(p[i].x, p[i].y), point(p[(i + 1) % n].x, p[(i + 1) % n].y)).second;
        bool ok = !sub.empty();
        cout << "Floor #" << ++tc << endl;
        if(ok)
            cout << "Surveillance is possible.\n";
        else
            cout << "Surveillance is impossible.\n";
        cout << endl;
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