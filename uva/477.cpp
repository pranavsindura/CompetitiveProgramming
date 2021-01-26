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
};

struct rect
{
    point a, b;
    int id;
    rect() {};
    rect(point a, point b, int id): a(a), b(b), id(id) {}
    bool inside(const point &p)
    {
        // a.x < p.x < b.x && a.y > p.y > b.y
        // Not on boundary
        if((a.x - p.x) < eps && (p.x - b.x) < eps && (a.y - p.y) > eps && (p.y - b.y) > eps)
            return true;
        else
            return false;
    }
};

struct circle
{
    point center;
    double radius;
    int id;
    circle() {}
    circle(double x, double y, double r, int id): center(x, y), radius(r), id(id) {}
    bool inside(const point &p)
    {
        if((p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y) - radius * radius < eps)
            return true;
        else
            return false;
    }
};

void cp()
{
    char type;
    vector<rect> r;
    vector<circle> c;
    int cnt = 0;
    while(cin >> type && type != '*')
    {
        if(type == 'r')
        {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            point a(x1, y1);
            point b(x2, y2);
            r.pb(rect(a, b, ++cnt));
        }
        else
        {
            double h, k, r;
            cin >> h >> k >> r;
            point center(h, k);
            c.pb(circle(h, k, r, ++cnt));
        }
    }
    point end(9999.9, 9999.9);
    cnt = 0;
    double x, y;
    while(cin >> x >> y && fabs(x - end.x) > eps && fabs(y - end.y) > eps)
    {
        vector<int> at;
        for(rect &a : r)
            if(a.inside(point(x, y)))
                at.pb(a.id);
        for(circle &a : c)
            if(a.inside(point(x, y)))
                at.pb(a.id);
        sort(all(at));
        if(at.empty())
            cout << "Point " << ++cnt << " is not contained in any figure\n";
        else
        {
            ++cnt;
            for(int idx : at)
                cout << "Point " << cnt << " is contained in figure " << idx << endl;
        }
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