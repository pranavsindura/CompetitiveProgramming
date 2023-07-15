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
const int MAXN = 2e3 + 5;

int n, m;
char grid[MAXN][MAXN];
bool vis[MAXN * MAXN], instack[MAXN * MAXN];
int height[MAXN * MAXN];

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    vector<int> best = {-1, -1, -1};

    fill(vis, vis + n * m, false);
    fill(instack, instack + n * m, false);
    fill(height, height + n * m, -1);

    for(int u = 0; u < n * m; u++)
    {
        // good code
        // if(!vis[u]) find_height(u, 0);

        // bad code
        vector<int> path;
        bool was_last = false;
        int cycle_at = -1;
        int node = u;
        int child = 0;
        while(true)
        {
            if(vis[node])
            {
                child = height[node];
                break;
            }
            vis[node] = true;
            instack[node] = true;
            path.push_back(node);

            int v = -1;
            int x = node / m, y = node % m, nx = x, ny = y;
            if(grid[x][y] == 'R') ny++;
            else if(grid[x][y] == 'L') ny--;
            else if(grid[x][y] == 'U') nx--;
            else nx++;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) v = nx * m + ny;
            if(v == -1) break;

            if(!vis[v]) node = v;
            else if(instack[v])
            {
                was_last = true, cycle_at = v;
                break;
            }
            else
            {
                child = height[v];
                break;
            }
        }

        int cycle_at_depth = find(all(path), cycle_at) - path.begin();

        while(!path.empty())
        {
            node = path.back();
            path.pop_back();
            instack[node] = false;

            int d = sz(path);
            if(d >= cycle_at_depth)
            {
                if(was_last) height[node] = d - cycle_at_depth + 1, was_last = false;
                else height[node] = child;
            }
            else
                height[node] = child + 1;

            child = height[node];
        }

        vector<int> me = {height[u], u / m, u % m};
        best = max(best, me);
    }

    cout << best[1] + 1 << " " << best[2] + 1 << " " << best[0] << endl;
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
    }
    return 0;
}
