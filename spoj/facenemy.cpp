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
const ld eps = 1e-15;
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

int dcmp(ld a, ld b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

ld fix_angle(ld val)
{
    // fix value between -1 and 1
    return ((val > 1) ? 1 : (val < -1) ? -1 : val);
}

// Dot product
ld dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

ld mag(point a)
{
    return sqrt(dp(a, a));
}

ld angle(point a, point b)
{
    ld val = dp(a, b);
    val /= mag(a);
    val /= mag(b);
    val = fix_angle(val);
    // acos return NaN is value is > 1 or < -1, need to fix

    // use acosl for long doubles
    return acosl(val);
}

void cp()
{
	// Use long double for better precision, even smaller epsilon
    ld x1, y1, u1, v1, x2, y2, u2, v2;
    cin >> x1 >> y1 >> u1 >> v1 >> x2 >> y2 >> u2 >> v2;

    point hero_foot = point(x1, y1);
    point hero_dir = point(u1, v1);
    point heroine_foot = point(x2, y2);
    point heroine_dir = point(u2, v2);

    point base = heroine_foot - hero_foot;
    point hero = hero_dir - hero_foot;
    point heroine = heroine_dir - heroine_foot;

    // alpha is angle between base vector and hero
    ld alpha = angle(base, hero);
    // beta is angle between base vector and heroine
    ld beta = PI - angle(base, heroine);

    int cmp = dcmp(alpha, beta);
    if(cmp == -1)
        cout << "Hero\n";
    else if(cmp == 0)
        cout << "0\n";
    else
        cout << "Heroine\n";
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