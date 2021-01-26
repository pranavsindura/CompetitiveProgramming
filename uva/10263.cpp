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
const ld eps = 1e-4;
const ld PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

struct point
{
    ld x, y;
    point() {}
    point(ld x, ld y): x(x), y(y) {}
    point operator+(const point &p)
    {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p)
    {
        return point(x - p.x, y - p.y);
    }
    point operator*(const ld &s)
    {
        return point(x * s, y * s);
    }
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
};

struct line
{
    ld a, b, c;

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
        ld z = sqrt(a * a + b * b);
        if (abs(z) > eps)
            a /= z, b /= z, c /= z;
    }

    ld dist(point p)
    {
        return a * p.x + b * p.y + c;
    }
};

int dcmp(ld a, ld b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

// Dot product
ld dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

// Euclidean Distance
ld length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<point> intersectLineCircle(point p0, point p1, point C, ld r)
{
    // dp -> dot product
    ld a = dp(p1 - p0, p1 - p0), b = 2 * dp(p1 - p0, p0 - C),
           c = dp(p0 - C, p0 - C) - r * r;
    ld f = b * b - 4 * a * c;

    vector<point> v;
    if( dcmp(f, 0) >= 0)
    {
        if( dcmp(f, 0) == 0)    f = 0;
        ld t1 = (-b + sqrt(f)) / (2 * a);
        ld t2 = (-b - sqrt(f)) / (2 * a);
        v.push_back( p0 + (p1 - p0) *t1 );
        if( dcmp(f, 0) != 0)    v.push_back( p0 + (p1 - p0)*t2 );
    }
    return v;
}

bool intersect_1D(ld a, ld b, ld c, ld d)
{
    if(dcmp(a, b) == 1)
        swap(a, b);
    if(dcmp(c, d) == 1)
        swap(c, d);
    return dcmp(max(a, c), min(b, d)) <= 0;
}

void cp()
{
    ld x, y;
    while(cin >> x >> y)
    {
        point m(x, y);
        int n;
        cin >> n;
        vector<point> arr;
        // line is arr[i] <---> arr[i+1]
        for(int i = 0; i < n + 1; i++)
        {
            cin >> x >> y;
            arr.pb(point(x, y));
        }

        ld mn_dist = DBL_MAX;
        point ans(-1, -1);
        for(int i = 0; i < n; i++)
        {
            line l(arr[i], arr[i + 1]);

            ld me = abs(l.dist(m));
            if(dcmp(me, mn_dist) == -1)
            {
                vector<point> list_points = intersectLineCircle(arr[i], arr[i + 1], m, me);
                // only 1 point, check it lies on line
                if(list_points.empty())
                    continue;
                point cand = list_points[0];
                if(intersect_1D(cand.x, cand.x, arr[i].x, arr[i + 1].x) && intersect_1D(cand.y, cand.y, arr[i].y, arr[i + 1].y))
                {
                    ans = cand;
                    mn_dist = me;
                }
            }
        }
        for(int i = 0; i < n + 1; i++)
        {
            ld me = length(m, arr[i]);
            if(dcmp(me, mn_dist) == -1)
            {
                ans = arr[i];
                mn_dist = me;
            }
        }
        cout << setprecision(4) << fixed << ans.x << endl << ans.y << endl;
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