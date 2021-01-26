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

bool can(point C, int rad, point R, int Rin, int Rout)
{
    double d = length(C, R);
    bool ok = false;
    // d >= rad + Rout
    if(dcmp(d, rad + Rout) >= 0)
        ok = true;
    if(dcmp(d + Rout, rad) <= 0)
        ok = true;
    if(dcmp(d + rad, Rin) <= 0)
        ok = true;
    return ok;
}

void cp()
{
    int x, y, in, out;
    cin >> x >> y >> in >> out;
    point A(x, y);
    int Ain = in, Aout = out;

    cin >> x >> y >> in >> out;
    point B(x, y);
    int Bin = in, Bout = out;

    int cnt = 0;
    if(can(A, Ain, B, Bin, Bout))
        cnt++;
    if(can(A, Aout, B, Bin, Bout))
        cnt++;
    if(can(B, Bin, A, Ain, Aout))
        cnt++;
    if(can(B, Bout, A, Ain, Aout))
        cnt++;
    cout << cnt;
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