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
struct pt
{
    int x, y;
    pt() {}
    pt(int _x, int _y): x(_x), y(_y) {}
    pt operator-(const pt &p)
    {
        return pt(x - p.x, y - p.y);
    }
    int cross(const pt &p)
    {
        return x * p.y - p.x * y;
    }
    int cross(pt &a, pt &b)
    {
        return (a - *this).cross(b - *this);
    }
};

bool intersect_1D(int a, int b, int c, int d)
{
    if(a > b)
        swap(a, b);
    if(c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

int sg(int x)
{
    if(x > 0)
        return 1;
    else if(x < 0)
        return -1;
    else
        return 0;
}

bool intersect(pair<pt, pt> &l1, pair<pt, pt> &l2)
{
    pt a = l1.ff, b = l1.ss;
    pt c = l2.ff, d = l2.ss;

    if(c.cross(d, a) == 0 && c.cross(d, b) == 0)
    {
        //lie on same line
        // Check if when projected on X axis intersect
        // and when projected on Y axis intersect
        if(intersect_1D(a.x, b.x, c.x, d.x) && intersect_1D(a.y, b.y, c.y, d.y))
            return true;
        else
            return false;
    }
    // Both points of one segment must lie on either side of the other segment
    // Signs of cross product must be opposite
    if(sg(c.cross(d, a)) != sg(c.cross(d, b)) && sg(a.cross(b, c)) != sg(a.cross(b, d)))
        return true;
    else
        return false;
}

void cp()
{
    int n;
    cin >> n;
    vector<pair<pt, pt>> line;
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line.pb({pt(x1, y1), pt(x2, y2)});
    }
    int adj[n][n];
    clr(adj, 0);

    // Form edge if they intersect
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(intersect(line[i], line[j]))
                adj[i][j] = 1;
        }
    }

    // Transitive Closure
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] |= (adj[i][k] & adj[k][j]);
    int u, v;
    while(cin >> u >> v && u + v)
    {
        u--, v--;
        if(adj[u][v])
            cout << "CONNECTED\n";
        else
            cout << "NOT CONNECTED\n";
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
        if(t)
            cout << endl;
    }
    return 0;
}