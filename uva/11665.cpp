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

double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

bool is_inside_polygon(vector<point> &p, point p0)
{
    int wn = 0;
    for(int i = 0; i < sz(p); i++)
    {
        point cur = p[i], nxt = p[(i + 1) % sz(p)];
        if(is_point_on_segment(cur, nxt, p0))
            return true;
        if(cur.y <= p0.y) // Edge going up
        {
            if(nxt.y > p0.y && (nxt - cur).cross(p0 - cur) > eps)
                wn++;
        }
        else // Edge going Down
        {
            if(nxt.y <= p0.y && (nxt - cur).cross(p0 - cur) < -eps)
                wn--;
        }
    }
    return wn != 0;
}

int ccw(point a, point b, point c)
{
    point v1(b - a), v2(c - a);
    double t = v1.cross(v2);

    if (t > +eps)
        return +1;
    if (t < -eps)
        return -1;
    if (v1.x * v2.x < -eps || v1.y * v2.y < -eps)
        return -1;
    if (length(v1, point(0, 0)) < length(v2, point(0, 0)) - eps)
        return +1;
    return 0;
}

bool intersect_segments(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3 == p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}


void cp()
{
    int n;
    while(cin >> n && n)
    {
        vector<vector<int>> adj(n, vector<int> (n));
        vector<vector<point>> poly(n);
        cin.ignore();
        for(int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            double x, y;
            while(ss >> x >> y)
                poly[i].pb(point(x, y));
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                // see if polygon i intersects with polygon j
                // by checking each vertex
                bool intersect = false;
                for(int k = 0; k < sz(poly[i]); k++)
                    intersect |= is_inside_polygon(poly[j], poly[i][k]);
                for(int k = 0; k < sz(poly[i]); k++)
                    for(int l = 0; l < sz(poly[j]); l++)
                        intersect |= intersect_segments(poly[i][k], poly[i][(k + 1) % sz(poly[i])], poly[j][l], poly[j][(l + 1) % sz(poly[j])]);
                // by checking each edge intersection
                adj[i][j] |= intersect;
                adj[j][i] |= intersect;
            }
        }
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int u)
        {
            vis[u] = 1;
            for(int i = 0; i < n; i++)
                if(adj[u][i] && !vis[i])
                    dfs(i);
        };
        int comp = 0;
        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs(i), comp++;
        cout << comp << endl;
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

