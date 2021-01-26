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
// const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

// POINT
typedef ll ftype;
const ftype eps = 1e-9;
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
    ftype cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    ftype cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
};

double polygon_area(vector<point> &p)
{
    point origin(0, 0);
    int n = sz(p);
    p.push_back(p[0]);
    double area = 0;
    for(int i = 0; i < n; i++)
        area += origin.cross(p[i], p[i + 1]);
    p.pop_back();
    return fabs(area / 2.0);
}


void cp()
{
    int n;
    while(cin >> n && n)
    {
        vector<point> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i].x >> arr[i].y;
        // Pick's Theorem
        // Area = Internal_points + Boundary_points/2 - 1
        double area = polygon_area(arr);
        double boundary = 0;
        for(int i = 0; i < n; i++)
        {
            point v = arr[(i + 1) % n] - arr[i];
            boundary += __gcd(abs(v.x), abs(v.y));
        }

        ll internal = area + 1 - boundary / 2;
        internal = max(internal, 0LL);
        cout << internal << endl;
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