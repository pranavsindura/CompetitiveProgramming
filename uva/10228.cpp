#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const ld eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

// POINT
typedef ld ftype;
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
        return point(x / s, y / s); // be careful, zero division error
    }
    bool operator<(const point &p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
    // For integers
    // bool operator<(const point &p) const
    // {
    //     return x < p.x || (x == p.x && y < p.y);
    // }
    bool operator==(const point &p) const
    {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }
    // For integers
    // bool operator==(const point &p) const
    // {
    //     return x == p.x && y == p.y;
    // }
    ftype cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    ftype cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
};

ld length(point a, point b)
{
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

void cp()
{
    int n;
    cin >> n;
    vector<point> p(n);
    for(point &c : p)
        cin >> c.x >> c.y;

    auto sum = [&](point x)
    {
        double val = 0 ;
        for(auto c : p)
            val += length(c, x);
        return val;
    };

    // SIMULATED ANNEALING
    ld ans = LDBL_MAX;
    for(int t = 0; t < 10; t++)
    {
        point C(rand(0, 10000), rand(0, 10000));
        ld alpha = 1e4;
        while(alpha > eps)
        {
            point B = C;
            ld step_cost = LDBL_MAX;
            for(int i = 0; i < 4; i++)
            {
                point T;
                T.x = C.x + dx[i] * alpha;
                T.y = C.y + dy[i] * alpha;
                if(sum(T) < step_cost)
                    step_cost = sum(T), B = T;
            }
            alpha *= 0.9;
            C = B;
        }
        ld me = sum(C);
        ans = min(ans, me);
    }
    fix(0);
    cout << ans << endl;
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
        if(t) cout << endl;
    }
    return 0;
}
