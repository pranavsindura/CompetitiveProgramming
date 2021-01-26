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
const int MAXN = 1e6 + 5;

struct point
{
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y) {}
    const point operator+(const point &p) const
    {
        return point(x + p.x, y + p.y);
    }
    const point operator-(const point &p) const
    {
        return point(x - p.x, y - p.y);
    }
};
// rotate ccw 90deg
point rotate(point p, point h, int times)
{
    point ans = p;
    for(int i = 0; i < times; i++)
    {
        point strip = ans - h;
        strip = point(-strip.y, strip.x);
        ans = strip + h;
    }
    return ans;
}
// distance squared
int len(point a, point b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool check(point a, point b, point c, point d)
{
    int d2 = len(a, b);
    int d3 = len(a, c);
    int d4 = len(a, d);

    if(d2 == 0 || d3 == 0 || d4 == 0)
        return false;
    if(d2 == d3 && d4 == 2 * d2 && len(b, c) == 2 * len(b, d))
        return true;
    if(d3 == d4 && d2 == 2 * d4 && len(c, d) == 2 * len(b, d))
        return true;
    if(d2 == d4 && d3 == 2 * d2 && len(b, d) == 2 * len(b, c))
        return true;
    return false;
}

void cp()
{
    int n;
    cin >> n;
    // pair location, home
    vector<pair<point, point>> arr;
    for(int i = 0; i < 4 * n; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        arr.pb({point(x, y), point(a, b)});
    }
    for(int i = 0; i < 4 * n; i += 4)
    {
        // points are i,i+1,i+2,i+3
        int total = INT_MAX;
        for(int w = 0; w < 4; w++)
        {
            for(int x = 0; x < 4; x++)
            {
                for(int y = 0; y < 4; y++)
                {
                    for(int z = 0; z < 4; z++)
                    {
                        point a = rotate(arr[i + 0].ff, arr[i + 0].ss, w);
                        point b = rotate(arr[i + 1].ff, arr[i + 1].ss, x);
                        point c = rotate(arr[i + 2].ff, arr[i + 2].ss, y);
                        point d = rotate(arr[i + 3].ff, arr[i + 3].ss, z);
                        if(check(a, b, c, d))
                            total = min(total, w + x + y + z);
                    }
                }
            }
        }
        if(total == INT_MAX)
            cout << -1 << endl;
        else
            cout << total << endl;
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