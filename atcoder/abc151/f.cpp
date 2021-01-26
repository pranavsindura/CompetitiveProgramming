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
const int MAXN = 1e5 + 5;

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
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
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

double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

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

pair<double, point> find_circle(point a, point b, point c)
{
    point m1 = (a + b) * 0.5, v1 = b - a, pv1 = point(v1.y, -v1.x);
    point m2 = (c + b) * 0.5, v2 = b - c, pv2 = point(v2.y, -v2.x);

    point end1 = pv1 + m1, end2 = pv2 + m2;
    point center;

    intersect_segments(m1, end1, m2, end2, center);
    double radius = length(center, a);
    return {radius, center};
}

point r[3], cen;
double rad;
int ps, rs; // ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);       rs = 0;
void MEC(vector<point> &arr)
{
    if(ps == 0 && rs == 2)
    {
        cen = (r[0] + r[1]) * 0.5;
        rad = length(r[0], cen);
    }
    else if(rs == 3)
    {
        pair<double, point> p = find_circle(r[0], r[1], r[2]);
        cen = p.second;
        rad = p.first;
    }
    else if(ps == 0)
    {
        cen = r[0]; // sometime be garbage, but will not affect
        rad = 0;
    }
    else
    {
        ps--;
        MEC(arr);

        if(length(arr[ps], cen) > rad)
        {
            r[rs++] = arr[ps];
            MEC(arr);
            rs--;
        }

        ps++;
    }
}


void cp()
{
    int n;
    cin >> n;
    vector<point> arr;
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        arr.pb(point(x, y));
    }
    ps = n, rs = 0;
    random_shuffle(all(arr));
    MEC(arr);
    cout << setprecision(15) << fixed;
    cout << rad;
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