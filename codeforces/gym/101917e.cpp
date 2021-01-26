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
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
    double cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    double cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
};
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


point turn(point p, int deg)
{
    double r = length(p, point(0, 0));
    double theta = angle(p);
    double alpha = (deg * 1.0) * PI / 180.0;
    theta += alpha;
    if(theta >= 360)
        theta -= 360;
    return point(r * cos(theta), r * sin(theta));
}

void cp()
{
    int A, W, H, n;
    cin >> A >> W >> H >> n;
    vector<point> arr(n);
    double mnx = DBL_MAX, mny = DBL_MAX;
    double mxx = -DBL_MAX, mxy = -DBL_MAX;
    double x, y;
    for(int i = 0; i < n; i++)
        cin >> x >> y, arr[i] = point(x, y);

    for(int i = 0; i < n; i++)
    {
        arr[i] = turn(arr[i], A);
        mnx = min(mnx, arr[i].x);
        mny = min(mny, arr[i].y);
    }

    for(int i = 0; i < n; i++)
        arr[i].x -= mnx, arr[i].y -= mny, mxx = max(mxx, arr[i].x), mxy = max(mxy, arr[i].y);

    double w = W, h = H;
    cout << setprecision(10) << fixed;
    for(int i = 0; i < n; i++)
    {
        double xdash = (arr[i].x / mxx) * w;
        double ydash = (arr[i].y / mxy) * h;
        cout << xdash << " " << ydash << endl;
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