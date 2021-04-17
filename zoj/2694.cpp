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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

struct cone
{
    int idx;
    double R, x, y;
    cone(): idx(-1), R(0), x(0), y(0) {}
    cone(int idx, double R, double x, double y): idx(idx), R(R), x(x), y(y) {}
    const bool operator<(const cone &c) const
    {
        return R > c.R;
    }
};

bool inside(cone A, cone B)
{
    double d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    double r1 = A.R, r2 = B.R;
    return dcmp(d, r1 + r2) <= 0;
}

void cp()
{
    int n;
    while(cin >> n && n)
    {
        vector<cone> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].R >> p[i].x >> p[i].y, p[i].idx = i;
        sort(all(p));

        vector<bool> picked(n);
        vector<int> worship;
        for(int i = 0; i < n; i++)
        {
            if(picked[i]) continue;
            worship.push_back(p[i].idx);
            for(int j = i + 1; j < n; j++)
            {
                if(picked[j]) continue;
                if(inside(p[i], p[j])) picked[j] = 1;
            }
            picked[i] = 1;
        }
        sort(all(worship));
        cout << sz(worship) << endl;
        for(int x : worship) cout << x + 1 << " \n"[x == worship.back()];
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
