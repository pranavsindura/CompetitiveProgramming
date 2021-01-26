
#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool fas(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void ss(int &x, int &y, int a, int b, int cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

int frange(int a, int b, int c, int minx, int maxx, int miny, int maxy)
{
    int x, y, g;
    if (!fas(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    ss(x, y, a, b, (minx - x) / b);
    if (x < minx)
        ss(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    ss(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        ss(x, y, a, b, -sign_b);
    int rx1 = x;

    ss(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        ss(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    ss(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        ss(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        if((n * x + m * y) % 2)
        {
            cout << "NO\n";
            continue;
        }
        int half = (n * x + m * y) / 2;
        if(frange(x, y, half, 0, n, 0, m))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
