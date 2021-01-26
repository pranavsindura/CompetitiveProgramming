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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
using namespace std;

class PolygonCover
{
public:
    double getArea(vector <int> x, vector <int> y);
};
int n;
vector<int> x, y;
double dp[15][1 << 15];
double dist(pi a, pi b)
{
    return sqrt((a.ff - b.ff) * 1.0 * (a.ff - b.ff) + (a.ss - b.ss) * 1.0 * (a.ss - b.ss));
}

double tri(int i, int j, int k)
{
    int dx1 = x[j] - x[i];
    int dy1 = y[k] - y[j];
    int dx2 = x[k] - x[j];
    int dy2 = y[j] - y[i];

    double a = dx1 * dy1 - dx2 * dy2;
    a = fabs(a) * 0.5;
    return a;
}

double solve(int i, int mask)
{
    if(i == n)
        return 0;

    double &ret = dp[i][mask];
    if(fabs(ret + 1) > eps)
        return ret;

    if((mask >> i) & 1)
        return ret = solve(i + 1, mask);

    double area = 1e9;
    for(int j = 0; j < n; j++)
    {
        for(int k = 0; k < n; k++)
        {
            if(i == j || i == k || j == k)
                continue;
            // connect i to j and k, triangle
            int nmask = mask | (1 << i);
            nmask |= (1 << j);
            nmask |= (1 << k);
            double me = tri(i, j, k);
            area = min(area, me + solve(i + 1, nmask));
        }
    }
    return ret = area;
}

double PolygonCover::getArea(vector <int> _x, vector <int> _y)
{
    n = sz(_x);
    x = _x, y = _y;
    clr(dp, -1);
    double area = solve(0, 0);
    return area;
}


int main()
{
    cout << setprecision(5) << fixed;
    PolygonCover p;
    cout << p.getArea(
    {-229, 69, 15, -70, 47, 191, -82, 140, 185, -148, 181, 109, -77, 182, 102}, {35, -159, -62, -116, -232, -216, -156, 154, -187, 143, -57, 186, -17, -136, -7}
         );
    return 0;
}