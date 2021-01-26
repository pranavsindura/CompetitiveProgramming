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

double tri(point A, point B, point C)
{
    return fabs(0.5 * ((C.y - A.y) * (B.x - A.x) - (B.y - A.y) * (C.x - A.x)));
}

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

void cp()
{
    int n;
    while(cin >> n && n)
    {
        vector<pair<char, point>> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].ff >> p[i].ss.x >> p[i].ss.y;
        double best = -DBL_MAX;
        string ans = "###";
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    bool ok = true;
                    double Area = tri(p[i].ss, p[j].ss, p[k].ss);
                    for(int l = 0; l < n; l++)
                    {
                        if(l != i && l != j && l != k)
                        {
                            double A = tri(p[i].ss, p[j].ss, p[l].ss);
                            double B = tri(p[i].ss, p[k].ss, p[l].ss);
                            double C = tri(p[k].ss, p[j].ss, p[l].ss);
                            ok &= (dcmp(A + B + C, Area) != 0);
                        }
                    }
                    if(ok && Area > best)
                        best = Area, ans = string(1, p[i].ff) + string(1, p[j].ff) + string(1, p[k].ff);
                }
            }
        sort(all(ans));
        cout << ans << endl;
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