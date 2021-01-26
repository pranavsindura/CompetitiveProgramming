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
struct circle
{
    point center;
    double radius;
    int id;
    circle() {}
    circle(double x, double y, double r, int id = 0): center(x, y), radius(r), id(id) {}
    bool inside(const point &p)
    {
        if((p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y) - radius * radius < eps)
            return true;
        else
            return false;
    }
};
void cp(int n)
{
	// Circle is centered at (n,n) with radius (2*n-1)/2
    point center(n, n);
    double radius = 2 * n - 1;
    radius /= 2.0;
    circle C(n, n, radius);
    int complete = 0, partial = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        for(int j = 0; j < 2 * n; j++)
        {
        	// For each cell with bottom left corner (i,j) check if the 4 corners are inside the circle
            bool a = C.inside(point(i, j));
            bool b = C.inside(point(i + 1, j));
            bool c = C.inside(point(i, j + 1));
            bool d = C.inside(point(i + 1, j + 1));
            if(a && b && c && d)
                complete++;
            else if(a || b || c || d)
                partial++;
        }
    }
    cout << "In the case n = " << n << ", " << partial << " cells contain segments of the circle.\n";
    cout << "There are " << complete << " cells completely contained in the circle.\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    int cnt = 0;
    while(cin >> t)
    {
        if(cnt++)
            cout << endl;
        cp(t);
    }
    return 0;
}