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

// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int ccw(point a, point b, point c)
{
    point v1(b - a), v2(c - a);
    double t = v1.cross(v2);

    if (t > +eps)
        return +1;
    if (t < -eps)
        return -1;
    if (v1.x * v2.x < -eps || v1.y * v2.y < -eps)
        return -1;
    if (length(v1, point(0, 0)) < length(v2, point(0, 0)) - eps)
        return +1;
    return 0;
}

bool is_convex(vector<point> &p)
{
    int n = sz(p);
    p.push_back(p[0]), p.push_back(p[1]);
    int sign = ccw(p[0], p[1], p[2]);
    bool ok = true;
    for(int i = 0; i < n && ok; i++)
        if(ccw(p[i], p[i + 1], p[i + 2]) != sign)
            ok = false;
    p.pop_back(), p.pop_back();
    return ok;
}

void cp()
{
    int n;
    while(cin >> n && n)
    {
        vector<point> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        // Convex -> No
        bool ok = !is_convex(p);
        cout << (ok ? "Yes\n" : "No\n");
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