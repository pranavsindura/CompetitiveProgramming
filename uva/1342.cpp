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
const double eps = 1e-7;
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
bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

bool get(point a, point b, point c, point d, point &intersect)
{
    return intersect_segments(a, b, c, d, intersect) && is_point_on_segment(a, b, intersect) && is_point_on_segment(c, d, intersect);
}

void cp()
{
    int n, tc = 1;
    while(cin >> n && n)
    {
        vector<point> arr(n);
        for(point &p : arr)
            cin >> p.x >> p.y;
        int E = 0;
        set<point> V;
        for(int i = 0; i < n - 1; i++)
        {
            set<point> on_me;
            on_me.insert(arr[i]);
            on_me.insert(arr[i + 1]);
            for(int j = 0; j < n - 1; j++)
            {
                if(i == j) continue;
                point inter;
                if(get(arr[i], arr[i + 1], arr[j], arr[j + 1], inter))
                    on_me.insert(inter);
            }
            for(point p : on_me)
                V.insert(p);
            assert(sz(on_me) >= 2);
            E += sz(on_me) - 1;
        }

        cout << "Case " << tc++ << ": There are " << 2 - sz(V) + E << " pieces.\n";
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

