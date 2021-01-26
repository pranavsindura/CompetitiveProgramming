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
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

// POINT
typedef ll ftype;
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
        return point(x / s, y / s);
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

// Dot product
ll dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

bool is_point_on_segment(point A, point B, point P)
{
    if(A.cross(P, B) != 0)
        return false;
    if(dp(P - A, B - A) <= dp(A - B, A - B) && dp(P - B, A - B) <= dp(A - B, A - B))
        return true;
    else
        return false;
}

bool is_inside_polygon(vector<point> &p, point p0, int &wn)
{
    wn = 0;
    for(int i = 0; i < sz(p) - 1; i++)
    {
        point cur = p[i], nxt = p[(i + 1)];
        if(is_point_on_segment(cur, nxt, p0))
            return true;
        if(cur.y <= p0.y) // Edge going up
        {
            if(nxt.y > p0.y && (nxt - cur).cross(p0 - cur) > 0)
                wn++;
        }
        else // Edge going Down
        {
            if(nxt.y <= p0.y && (nxt - cur).cross(p0 - cur) < 0)
                wn--;
        }
    }
    return false;
}

void cp()
{
    int n, m;
    cin >> n;
    vector<point> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    a.pb(a.front());

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        int wn;
        bool on_edge = is_inside_polygon(a, point(x, y), wn);
        if(on_edge)
            cout << "EDGE\n";
        else
            cout << wn << endl;
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