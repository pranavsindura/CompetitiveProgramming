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
const int inf = 1e7;
const int MAXN = 250 + 5;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

int n, m;

ll swamp[MAXN][MAXN];
ll path[MAXN][MAXN];
ll visit_time[MAXN][MAXN];
ll times[MAXN][MAXN];
ll interval[MAXN][MAXN];
string quad[MAXN];

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dijkstra(int sx, int sy)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            path[i][j] = LLONG_MAX;

    priority_queue<pair<ll, pi>, vector<pair<ll, pi>>, greater<pair<ll, pi>>> pq;

    path[sx][sy] = 0;
    pq.push({0, {sx, sy}});
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        ll d = node.ff;
        int x = node.ss.ff, y = node.ss.ss;
        if(d > path[x][y]) continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(valid(nx, ny) && path[nx][ny] > path[x][y] + swamp[nx][ny])
            {
                path[nx][ny] = path[x][y] + swamp[nx][ny];
                pq.push({path[nx][ny], {nx, ny}});
            }
        }
    }
}

void quadcopter(int sx, int sy)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            visit_time[i][j] = LLONG_MAX;

    int x = sx, y = sy, T = 0;
    while(true)
    {
        if(!valid(x, y)) break;

        times[x][y]++;

        if(times[x][y] > 2) break;

        if(times[x][y] == 2) interval[x][y] = T - visit_time[x][y];
        else visit_time[x][y] = T;

        T++;
        if(quad[x][y] == 'R') y++;
        else if(quad[x][y] == 'L') y--;
        else if(quad[x][y] == 'U') x--;
        else x++;
    }
}

void cp()
{
    int bx, by, qx, qy;
    cin >> n >> m >> bx >> by >> qx >> qy;
    bx--, by--, qx--, qy--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> swamp[i][j];
    for(int i = 0; i < n; i++)
        cin >> quad[i];

    dijkstra(bx, by);
    quadcopter(qx, qy);

    ll ans = LLONG_MAX;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(visit_time[i][j] == LLONG_MAX) continue;
            if(times[i][j] == 1)
            {
                if(path[i][j] <= visit_time[i][j])
                    ans = min(ans, visit_time[i][j]);
            }
            else
            {
                // visit_time[i][j] + k * interval[i][j] >= path[i][j]
                assert(interval[i][j]);
                ll k = path[i][j] - visit_time[i][j];
                k = max(k, 0LL);
                k = (k + interval[i][j] - 1) / interval[i][j];
                ll T = visit_time[i][j] + k * interval[i][j];
                ans = min(ans, T);
            }
        }
    if(ans == LLONG_MAX) ans = -1;
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

