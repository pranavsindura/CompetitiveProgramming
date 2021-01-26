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
const int MAXN = 1e5 + 5;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

void cp()
{
    int n, N, M, sx, sy, ex, ey;
    cin >> n >> N >> M >> sx >> sy >> ex >> ey;

    vector<vector<int>> visit(N, vector<int>(M, -1));
    queue<pi> q;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        q.push({x, y});
        visit[x][y] = 0;
    }

    auto valid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < M;
    };

    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int x = node.ff, y = node.ss;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(!valid(nx, ny)) continue;
            if(~visit[nx][ny]) continue;
            visit[nx][ny] = visit[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int sep = N * M;
    int path = N * M;

    int lo = 0, hi = N + M;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        bool found = false;
        vector<vector<bool>> vis(N, vector<bool>(M));
        vector<vector<int>> dist(N, vector<int>(M, N * M));

        vis[sx][sy] = 1, dist[sx][sy] = 0;
        queue<pi> q;
        if(visit[sx][sy] >= mid)
            q.push({sx, sy});

        while(!q.empty() && !found)
        {
            pi node = q.front();
            q.pop();
            int x = node.ff, y = node.ss;
            if(x == ex && y == ey)
                found = true;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(!valid(nx, ny)) continue;
                if(vis[nx][ny]) continue;
                if(visit[nx][ny] < mid) continue;
                vis[nx][ny] = 1;
                dist[nx][ny] = 1 + dist[x][y];
                q.push({nx, ny});
            }
        }

        if(found)
            sep = mid, path = dist[ex][ey], lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << sep << " " << path << endl;
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

