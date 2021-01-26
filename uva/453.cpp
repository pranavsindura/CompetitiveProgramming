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
const double eps = 1e-4;
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
};

int dcmp(double a, double b)
{
    return	(fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
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

double dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

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
    if(same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
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

void cp()
{
    double h1, k1, r1, h2, k2, r2;
    while(cin >> h1 >> k1 >> r1 >> h2 >> k2 >> r2)
    {
        point c1(h1, k1);
        point c2(h2, k2);

        vector<point> p = circle_intersection(c1, r1, c2, r2);
        if(p.empty())
            cout << "NO INTERSECTION\n";
        else if(sz(p) == 3)
            cout << "THE CIRCLES ARE THE SAME\n";
        else
        {
            sort(all(p));
            for(int i = 0; i < sz(p); i++)
            {
                cout << setprecision(3) << fixed << "(" << p[i].x + eps << "," << p[i].y + eps << ")";
            }
            cout << endl;
        }
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