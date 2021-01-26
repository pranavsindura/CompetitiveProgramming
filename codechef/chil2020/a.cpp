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
struct line
{
    double a, b, c;

    line() {}
    line(point p, point q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > eps)
            a /= z, b /= z, c /= z;
    }

    double dist(point p) const
    {
        return a * p.x + b * p.y + c;
    }
};
int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

void cp()
{
    int n, m, c;
    cin >> n >> m >> c;
    // y = mx+c
    // mx - y + c = 0
    line l;
    l.a = m, l.b = -1, l.c = c;
    l.norm();
    ll left = 0, right = 0;
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        double dist = l.dist(point(x, y));
        int sg = dcmp(dist, 0);
        if(sg == 0)
            continue;
        else if(sg == 1)
            right++;
        else
            left++;
    }
    cout << left * right << endl;
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