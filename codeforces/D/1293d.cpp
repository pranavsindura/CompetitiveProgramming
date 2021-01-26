#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int MAXN = 1e5 + 5;

void cp()
{
    ll x0, y0, ax, bx, ay, by, sx, sy, T;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> sx >> sy >> T;

    vector<vector<ll>> pts;
    ll x = x0, y = y0;
    while(true)
    {
        pts.push_back({x, y});
        if(x >= inf / ax) break;
        x = ax * x;
        if(x >= inf - bx) break;
        x += bx;

        if(y >= inf / ay) break;
        y = ay * y;
        if(y >= inf - by) break;
        y += by;
    }

    int ans = 0;
    for(int i = 0; i < sz(pts); i++)
    {
        ll A, B, cost = 0;
        A = abs(sx - pts[i][0]);
        B = abs(sy - pts[i][1]);

        if(cost >= inf - A) continue;
        cost += A;
        if(cost >= inf - B) continue;
        cost += B;

        if(cost <= T) ans = max(ans, 1);

        for(int j = i - 1; j >= 0; j--)
        {
            A = abs(pts[j + 1][0] - pts[j][0]);
            B = abs(pts[j + 1][1] - pts[j][1]);

            if(cost >= inf - A) break;
            cost += A;
            if(cost >= inf - B) break;
            cost += B;

            if(cost <= T) ans = max(ans, i - j + 1);
        }
    }

    for(int i = 0; i < sz(pts); i++)
    {
        ll A, B, cost = 0;
        A = abs(sx - pts[i][0]);
        B = abs(sy - pts[i][1]);

        if(cost >= inf - A) continue;
        cost += A;
        if(cost >= inf - B) continue;
        cost += B;

        if(cost <= T) ans = max(ans, 1);

        for(int j = i + 1; j < sz(pts); j++)
        {
            A = abs(pts[j - 1][0] - pts[j][0]);
            B = abs(pts[j - 1][1] - pts[j][1]);
            
            if(cost >= inf - A) break;
            cost += A;
            if(cost >= inf - B) break;
            cost += B;

            if(cost <= T) ans = max(ans, j - i + 1);
        }
    }

    cout << ans << endl;
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

