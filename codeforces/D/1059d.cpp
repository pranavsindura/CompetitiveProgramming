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

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const ld eps = 1e-7;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;
/*
    x position be ternary searched, rad decreases, then increases as x increases - assumption
    fix x
    find radius with binary search - assumption
    fix rad
    centre - (x, rad)
    smallest rad s.t. all points within it

    crap precision, need something better, assumptions seem okay
    radius cannot be found mathematically should be BS
    what about x?

    how about drawing circles around each point of a fixed radius R
    then checking if they all intersect

    Their intersection will form a region where our circle's center can be
    But that center must be of the form (h, R)
    So we need to intersect the line y = R with the circles

*/

// POINT
typedef ld ftype;
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
        return x < p.x - eps || (fabs(x - p.x) < eps && y < p.y - eps);
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

ld length(point a, point b)
{
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int dcmp(ld a, ld b)
{
    return  (fabsl(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

ld dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}


void cp()
{
    int n;
    cin >> n;
    vector<point> p(n);
    bool ok = true;
    bool above = false, below = false;
    int on = 0;
    for(point &c : p)
    {
        int x, y;
        cin >> x >> y;
        above |= (y > 0);
        below |= (y < 0);
        on += y == 0;
        c = point(x, y);
    }
    if((above and below) or on > 1) ok = false;
    for(point &c : p) c.y = fabs(c.y); // make all be above x axis

    if(!ok)
    {
        cout << -1 << endl;
        return;
    }

    ld lo = 0, hi = 1e14, ans = 1e14;
    for(int itr = 0; itr < 100; itr++)
    {
        ld mid = lo + (hi - lo) / 2;
        point p0(-1, mid), p1(1, mid);
        bool can = true;
        ld L = -1e8, R = 1e8;
        for(int i = 0; i < n && can; i++)
        {
            point C = p[i];
            ld r = mid;
            ld a = dp(p1 - p0, p1 - p0), b = 2 * dp(p1 - p0, p0 - C),
               c = dp(p0 - C, p0 - C) - r * r;
            ld f = b * b - 4 * a * c;

            if( dcmp(f, 0) >= 0)
            {
                if( dcmp(f, 0) == 0)    f = 0;
                ld t1 = (-b + sqrtl(f)) / (2 * a);
                ld t2 = (-b - sqrtl(f)) / (2 * a);
                ld X = (p0 + (p1 - p0) * t1).x;
                if( dcmp(f, 0) != 0)
                {
                    ld Y = (p0 + (p1 - p0) * t2).x;
                    if(X > Y) swap(X, Y);
                    L = max(L, X), R = min(R, Y);
                }
                else
                    L = max(L, X), R = min(R, X);
            }
            else
                can = false;

            if(dcmp(L, R) > 0) can = false;
        }
        if(dcmp(L, R) > 0) can = false;

        if(can) ans = mid, hi = mid;
        else lo = mid;
    }
    fix(10);
    cout << ans << endl;
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

