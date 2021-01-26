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

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Dot product
double dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

// CHECK IF POINT LIES ON SEGMENT
// Is point P on segment AB
// For doubles
bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

double polygon_shortest_distance(vector<point> &a, vector<point> &b)
{
    int n = sz(a), m = sz(b);
    // we know they wont intersect
    // if(polygon_intersection(a, b)) return 0;
    a.pb(a.front()), b.pb(b.front());

    double ans = DBL_MAX;
    point C;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // point a[i] with point b[j]
            C = a[i];
            ans = min(ans, length(a[i], b[j]));
            // point a[i] with edge b[j] ---- b[j + 1]
            point A = b[j], B = b[j + 1];
            point AD = (B - A) * dp(B - A, C - A) / dp(B - A, B - A);
            point D = AD + A;
            if(is_point_on_segment(A, B, D))
                ans = min(ans, length(C, D));
            // point b[j] with edge a[i] ---- a[i + 1]
            C = b[j];
            A = a[i], B = a[(i + 1)];
            AD = (B - A) * dp(B - A, C - A) / dp(B - A, B - A);
            D = AD + A;
            if(is_point_on_segment(A, B, D))
                ans = min(ans, length(C, D));
        }
    }
    a.pop_back(), b.pop_back();
    return ans;
}


/*----------------------------GEOMETRY HACKPACK--------------------------------*/

double dist[15][15];

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<point>> poly(k + 2);

    poly[0].resize(n);
    poly[k + 1].resize(m);

    for(int i = 0; i < n; i++)
        cin >> poly[0][i].x >> poly[0][i].y;
    for(int i = 0; i < m; i++)
        cin >> poly[k + 1][i].x >> poly[k + 1][i].y;

    if(poly[0][0].y > poly[k + 1][0].y)
        swap(poly[0], poly[k + 1]);
    poly[0].pb(point(0, -100000));
    poly[k + 1].pb(point(0, 100000));

    for(int i = 1; i <= k; i++)
    {
        int p;
        cin >> p;
        poly[i].resize(p);
        for(int j = 0; j < p; j++)
            cin >> poly[i][j].x >> poly[i][j].y;
    }

    clr(dist, 0);
    for(int i = 0; i < k + 2; i++)
        for(int j = 0; j < k + 2; j++)
            if(i != j)
                dist[i][j] = polygon_shortest_distance(poly[i], poly[j]);

    for(int a = 0; a < k + 2; a++)
        for(int i = 0; i < k + 2; i++)
            for(int j = 0; j < k + 2; j++)
                dist[i][j] = min(dist[i][j], dist[i][a] + dist[a][j]);
    fix(3);
    cout << dist[0][k + 1] << endl;
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

