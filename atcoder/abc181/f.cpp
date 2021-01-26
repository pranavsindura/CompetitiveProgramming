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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 100 + 5;

/*
    Consider a fixed diameter D
    This circle must pass through all the gaps between some points to start from left and end up on the right
    when can it not pass through?
    Let us join all points with a line which have distance < D
    Also consider points (i, 100) and (i, -100) as well 
    When the top boundary (y = 100) and bottom boundary (y = -100)
    are connected by some sequence of lines something like this
    --------------------------------
                    |
                   /
                  /
                 /
                |
    ---------------------------------
    Then no circle can pass through from the left to the right
    We can use DSU/BFS/DFS anything really to check if we can go from some (i, 100) to (j, -100)
    Used DSU here
*/

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

double length(pi a, pi b)
{
    return sqrt((a.ff - b.ff) * 1.0 * (a.ff - b.ff) + (a.ss - b.ss) * 1.0 * (a.ss - b.ss));
}

int parent[10 * MAXN], sz[10 * MAXN];

void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}

void cp()
{
    int n;
    cin >> n;
    vector<pi> arr;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.pb({x, y});
    }
    // [n, n + 200]
    for(int i = -100; i <= 100; i++)
        arr.pb({i, 100});
    // [n + 201, n + 401]
    for(int i = -100; i <= 100; i++)
        arr.pb({i, -100});

    double lo = 0, hi = 200;
    for(int itr = 0; itr < 50; itr++)
    {
        double mid = (lo + hi) / 2;
        make_set(sz(arr));
        for(int i = 0; i < sz(arr); i++)
            for(int j = i + 1; j < sz(arr); j++)
                if(dcmp(length(arr[i], arr[j]), mid) < 0)
                    union_set(i, j);
        bool ok = true;

        set<int> par;
        for(int i = n; i <= n + 200; i++)
            par.insert(find_set(i));
        for(int i = n + 201; i <= n + 401; i++)
            if(par.count(find_set(i)))
                ok = false;
            
        if(ok)
            lo = mid;
        else
            hi = mid;
    }

    dblout(20);
    cout << lo / 2 << endl;
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