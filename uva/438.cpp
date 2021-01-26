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
    point operator+(const point &p)
    {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p)
    {
        return point(x - p.x, y - p.y);
    }
    point operator*(const double &s)
    {
        return point(x * s, y * s);
    }
};

struct line
{
    double a, b, c;
    line() {}
    line(point p, point q)
    {
        // (y2-y1) x + (x1-x2) y - x2 * (y2 - y1) - y2 * (x1 - x2) = 0;
        // a       x + b       y - x2 * a         - y2 * b
        // a       x + b       y + c
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }
    void norm()
    {
        double z = sqrt(a * a + b * b);
        if(abs(z) > eps)
            a /= z,  b /= z, c /= z;
    }
};

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

void intersect_segments(point a, point b, point c, point d, point &inter)
{
    // Line segments will not be collinear, will always intersect
    line m(a, b);
    line n(c, d);

    double Delta = det(m.a, m.b, n.a, n.b);
    double Delta_x = det(m.c, m.b, n.c, n.b);
    double Delta_y = det(m.a, m.c, n.a, n.c);
    inter = point(-Delta_x / Delta, -Delta_y / Delta);
}

double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void cp()
{
    double x1, y1, x2, y2, x3, y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        cout << setprecision(2) << fixed;
        point a = point(x1, y1);
        point b = point(x2, y2);
        point c = point(x3, y3);

        point m1 = (a + b) * 0.5, v1 = b - a, pv1 = point(v1.y, -v1.x);
        point m2 = (c + b) * 0.5, v2 = b - c, pv2 = point(v2.y, -v2.x);

        point end1 = pv1 + m1, end2 = pv2 + m2;
        point center;

        intersect_segments(m1, end1, m2, end2, center);
        double radius = length(center, a);

        double circumference = 2.0 * PI * radius;
        cout << circumference << endl;
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