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
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

typedef double ftype;
const double eps = 1e-9;
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

int sg(int x)
{
    if(x > 0)
        return 1;
    else if(x < 0)
        return -1;
    else
        return 0;
}

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

inline bool betw(double l, double r, double x)
{
    return min(l, r) <= x + eps && x <= max(l, r) + eps;
}

inline bool intersect_1d(double a, double b, double c, double d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + eps;
}

bool intersect(point a, point b, point c, point d, point &left, point &right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < eps)
    {
        if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else
    {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}


void cp()
{
    int n, m;
    cin >> n;
    vector<pair<point, point>> arr;
    vector<pair<pi, pi>> segs;
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)
            swap(x1, x2), swap(y1, y2);
        else if(x1 == x2 && (y1 > y2))
            swap(y1, y2);
        arr.pb(mp(point(x1, y1), point(x2, y2)));
        segs.pb({{x1, y1}, {x2, y2}});
    }
    cin >> m;
    vector<pi> query(m);
    for(pi &x : query)
        cin >> x.ff >> x.ss;
    vector<bool> hide(n);
    int dp[n];
    clr(dp, -1);
    function<int(int, int)> solve = [&](int x, int y)
    {
        int ind = -1;
        double ht = -DBL_MAX;
        for(int i = 0; i < n; i++)
        {
            point inter;
            if(!hide[i] && intersect(arr[i].ff, arr[i].ss, point(x, y), point(x, 0), inter, inter))
            {
                if(inter.y > ht)
                    ind = i, ht = inter.y;
            }
        }
        if(ind == -1)
            return x;
        int &ret = dp[ind];
        if(~ret)
            return ret;
        hide[ind] = true;
        int dy = segs[ind].ff.ss - segs[ind].ss.ss;
        int dx = segs[ind].ff.ff - segs[ind].ss.ff;
        dy = sg(dy);
        dx = sg(dx);
        if(dy == dx)// +ve slope, drop left
            return ret = solve(segs[ind].ff.ff, segs[ind].ff.ss);
        else
            return ret = solve(segs[ind].ss.ff, segs[ind].ss.ss);
    };
    for(int i = 0; i < m; i++)
    {
        int x = query[i].ff, y = query[i].ss;
        fill(all(hide), false);
        int ans = solve(x, y);
        cout << ans << endl;
    }
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
        if(t)
            cout << endl;
    }
    return 0;
}