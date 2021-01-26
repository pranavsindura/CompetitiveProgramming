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
const double eps = 1e-7;
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

// Dot product
double dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}


bool same(point a, point b)
{
    return (dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0);
}

double fix_angle(double val)
{
    // fix value between -1 and 1
    return ((val > 1) ? 1 : (val < -1) ? -1 : val);
}

double get_angle_C_ABC(double a, double b, double c)
{
    // c^2 = a^2 + b^2 - 2*a*b*cos(C)
    double val = a * a + b * b - c * c;
    val /= (2.0 * a * b);
    val = fix_angle(val);
    double ang = acos(val);
    return ang;
}

// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double angle(point a)
{
    // Angle with X axis
    return atan2(a.y, a.x);
}

point polar(double r, double ang)
{
    return point(r * cos(ang), r * sin(ang));
}

vector<point> circle_intersection(point c1, double r1, point c2, double r2)
{
    // Check for same first
    if(same(c1, c2) && dcmp(r1, r2) == 0 && r1 > eps)
        return vector<point>(3, c1);

    // Get alpha and beta
    double alpha = get_angle_C_ABC(r1, length(c1, c2), r2);
    double beta = angle(c2 - c1);
    // fix NaN
    if(isnan(alpha))
        alpha = 0;
    point p1 = polar(r1, alpha + beta) + c1;

    vector<point> ans;
    // Check if p1 is on circle
    if(dcmp(dp(p1 - c1, p1 - c1), r1 * r1) != 0 || dcmp(dp(p1 - c2, p1 - c2), r2 * r2) != 0)
        return ans;
    ans.pb(p1);

    point p2 = polar(r1, - alpha + beta) + c1;
    ans.pb(p2);
    // Check if they are same
    if(same(ans[0], ans[1]))
        ans.pop_back();
    return ans;
}

vector<point> intersectLineCircle(point p0, point p1, point C, double r)
{
    // dp -> dot product
    double a = dp(p1 - p0, p1 - p0), b = 2 * dp(p1 - p0, p0 - C),
           c = dp(p0 - C, p0 - C) - r * r;
    double f = b * b - 4 * a * c;

    vector<point> v;
    if( dcmp(f, 0) >= 0)
    {
        if( dcmp(f, 0) == 0)    f = 0;
        double t1 = (-b + sqrt(f)) / (2 * a);
        double t2 = (-b - sqrt(f)) / (2 * a);
        v.push_back( p0 + (p1 - p0) * t1);
        if( dcmp(f, 0) != 0)    v.push_back( p0 + (p1 - p0) * t2 );
    }
    return v;
}

bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

void cp()
{
    double x1, y1, x2, y2, rad;
    cin >> x1 >> y1 >> x2 >> y2 >> rad;
    point L(x1, y1);
    point R(x2, y2);
    point O(0, 0);

    pair<point, double> C = {point(0, 0), rad};
    pair<point, double> CL = {L / 2, length(L, O) / 2};
    pair<point, double> CR = {R / 2, length(R, O) / 2};

    double ans = DBL_MAX;
    bool out = true;
    vector<point> inter = intersectLineCircle(L, R, C.ff, C.ss);
    // check if the intersection points lie on the segment if > 1
    if(sz(inter) >= 2)
    {
        for(point p : inter)
            out &= !is_point_on_segment(L, R, p);
    }
    if(out)
        ans = min(ans, length(L, R));
    
    vector<point> left = circle_intersection(C.ff, C.ss, CL.ff, CL.ss);
    vector<point> right = circle_intersection(C.ff, C.ss, CR.ff, CR.ss);

    fix(3);
    for(point a : left)
    {
        for(point b : right)
        {
            double d = length(L, a) + length(b, R);
            double cosang = dp(a, b) / length(O, a) / length(O, b);
            cosang = fix_angle(cosang);
            double ang = acos(cosang);
            while(ang < 0)
                ang += PI;
            while(ang > PI)
                ang -= PI;
            d += ang * rad;
            ans = min(ans, d);
        }
    }
    cout << ans << endl;
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

