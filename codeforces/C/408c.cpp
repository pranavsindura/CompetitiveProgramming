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
    const point operator*(int s) const
    {
        return point(x * s, y * s);
    }
    const point operator-(const point &p) const
    {
        return point(x - p.x, y - p.x);
    }
    const point operator+(const point &p) const
    {
        return point(x + p.x, y + p.x);
    }
};

bool on_boundary(point C, int rad, point test)
{
    return (C.x - test.x) * (C.x - test.x) + (C.y - test.y) * (C.y - test.y) == rad * rad;
}

void cp()
{
    int a, b;
    cin >> a >> b;
    for(int x = -b; x <= b; x++)
    {
        for(int y = -b; y <= b; y++)
        {
            // should not be parallel to X or Y axis
            if(x == 0 || y == 0)
                continue;
            if(on_boundary(point(0, 0), b, point(x, y)))
            {
                // (x,y) is on boundary
                point b_vec = point(x, y);
                point b_vec_normal = point(b_vec.y, -b_vec.x);

                int norm_sq = b_vec_normal.x * b_vec_normal.x + b_vec_normal.y * b_vec_normal.y;

                // norm_sq must be perfect square
                if((int)sqrt(norm_sq) * (int)sqrt(norm_sq) != norm_sq)
                    continue;
                int norm = sqrt(norm_sq);
                point a_vec = b_vec_normal * a;
                // now we divide by norm so they must be divisible
                if(abs(a_vec.x) % norm != 0 || abs(a_vec.y) % norm != 0)
                    continue;

                a_vec.x /= norm;
                a_vec.y /= norm;

                point hyp = a_vec - b_vec;
                //Check if hypotenuse is parallel to X or Y axis
                if(hyp.x == 0 || hyp.y == 0)
                    continue;

                // Found answer!
                cout << "YES\n";
                cout << b_vec.x << " " << b_vec.y << endl;
                cout << 0 << " " << 0 << endl;
                cout << a_vec.x << " " << a_vec.y << endl;
                return;
            }
        }
    }
    cout << "NO";
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