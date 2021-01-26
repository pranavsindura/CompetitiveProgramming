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
    double dist(point p)
    {
        return a * p.x + b * p.y + c;
    }
};

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double area(point A, point B, point C)
{
    double a = length(A, B);
    double b = length(B, C);
    double c = length(C, A);

    double s = (a + b + c) / 2;

    double ans = sqrt(s * (s - a) * (s - b) * (s - c));
    return ans;
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
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            line diag(arr[i], arr[j]);
            int l = 0, r = 0;
            double mx = -DBL_MAX, mn = DBL_MAX;
            for(int k = 0; k < n; k++)
            {
                if(k != i && k != j)
                {
                    double d = diag.dist(arr[k]);
                    if(d < mn)
                        mn = d, l = k;
                    if(d > mx)
                        mx = d, r = k;
                }
            }
            point left = arr[l];
            point right = arr[r];

            double area_left = area(arr[i], arr[j], left);
            double area_right = area(arr[i], arr[j], right);

            int sg_left = dcmp(diag.dist(left), 0);
            int sg_right = dcmp(diag.dist(right), 0);

            double here;
            if(sg_left == sg_right)
                here = abs(area_right - area_left);
            else
                here = area_right + area_left;
            ans = max(ans, here);
        }
    }
    cout << setprecision(12) << fixed << ans;
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