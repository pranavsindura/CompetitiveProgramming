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
const double eps = 1e-12;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
struct point
{
    ll x, y;
    point() {}
    point(ll x, ll y): x(x), y(y) {}
    point operator+(const point &p)
    {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p)
    {
        return point(x - p.x, y - p.y);
    }
    point operator*(const ll &s)
    {
        return point(x * s, y * s);
    }
    bool operator<(const point &p) const
    {
        return x < p.x || (abs(x - p.x) < 0 && y < p.y);
    }
};

struct line
{
    ll a, b, c;

    line() {}
    line(point p, point q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
    }

    ll dist(point p) const
    {
        return a * p.x + b * p.y + c;
    }
};


vector<point> arr(MAXN);
int n;
bool check(int p1, int p2)
{
    if(n <= 4)
        return true;

    line a(arr[p1], arr[p2]), b;

    bool ok = true;
    int cnt = 0;

    point r,q;
    for(int i = 0; i < n && cnt < 2; i++)
    {
        // if point lies on A, ignore it
        // else use it to make B
        ll d1 = a.dist(arr[i]);

        if(d1 == 0)
            continue;

        if(cnt == 0)
            r = arr[i], cnt++;
        else
            q = arr[i], cnt++;
    }

    if(cnt < 2)
        return ok;

    b = line(r, q);

    for(int i = 0; i < n; i++)
    {
        // if point lies on A, ignore it
        // else it must lie on B
        ll d1 = a.dist(arr[i]);
        ll d2 = b.dist(arr[i]);
        if(!d1 || !d2)
            continue;
        else
            ok = false;
    }
    return ok;
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[i] = point(x, y);
    }
    bool ok = false;
    ok |= check(0, 1);
    ok |= check(1, 2);
    ok |= check(2, 0);
    cout << (ok ? "YES" : "NO");
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