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

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point get_point_on_line(point A, point B, double D)
{
    double ratio = D / length(A, B);
    return point(A.x + ratio * (B.x - A.x), A.y + ratio * (B.y - A.y));
}

void cp()
{
    int n, t;
    cin >> n >> t;
    vector<point> arr(n), plant;
    for(point &p : arr)
        cin >> p.x >> p.y;

    double total = 0;
    for(int i = 1; i < n; i++)
        total += length(arr[i - 1], arr[i]);

    double d = total / double(t - 1);
    int mul = 0;

    double path = 0;
    for(int i = 1; i < n; i++)
    {
        double seg = length(arr[i - 1], arr[i]);
        while(mul < t && dcmp(mul * d, path + seg) <= 0)
        {
            point p = get_point_on_line(arr[i - 1], arr[i], mul * d - path);
            plant.push_back(p);
            mul++;
        }
        path += seg;
    }

    fix(2);
    for(point p : plant)
        cout << p.x << " " << p.y << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Road #" << i << ":" << endl;
        cp();
        cout << endl;
    }
    return 0;
}

