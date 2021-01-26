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
const int MAXN = 1e5 + 5;

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
    ld cross(const point &p)
    {
        return x * p.y - p.x * y;
    }
    ld cross(const point &a, const point &b)
    {
        return (*this - a).cross(*this - b);
    }
};

ld dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point arr[MAXN];
point adil, bera, dustbin;

struct cmp
{
    bool operator()(int p, int q)
    {
        return -dist(dustbin, arr[p]) + dist(adil, arr[p]) < -dist(dustbin, arr[q]) + dist(adil, arr[q]);
    };
};

void cp()
{
    cin >> adil.x >> adil.y >> bera.x >> bera.y >> dustbin.x >> dustbin.y;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;

    set<int, cmp> se;
    for(int i = 0; i < n; i++)
        se.insert(i);

    ld total = 0, mind = DBL_MAX;

    for(int i = 0; i < n; i++)
        total += dist(arr[i], dustbin) * 2.0;

    for(int i = 0; i < n; i++)
    {
        // Only Bera
        ld here = total - dist(arr[i], dustbin);
        here += dist(arr[i], bera);
        mind = min(mind, here);

        se.erase(i);
        if(!se.empty())
        {
            // Bera and Adil
            int posa = *se.begin();
            ld benefit = -dist(arr[posa], dustbin);
            benefit += dist(arr[posa], adil);
            here += benefit;
            mind = min(mind, here);
        }
        se.insert(i);

        // Only Adil
        here = total - dist(arr[i], dustbin);
        here += dist(arr[i], adil);
        mind = min(mind, here);

    }

    cout << setprecision(12) << fixed << mind << endl;
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