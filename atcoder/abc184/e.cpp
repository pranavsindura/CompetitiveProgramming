#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 2e3 + 5;

char arr[MAXN][MAXN];
int dist[MAXN][MAXN];

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};


void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sx, sy, ex, ey;
    vector<vector<pi>> point(26);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'S')
                sx = i, sy = j;
            else if(arr[i][j] == 'G')
                ex = i, ey = j;
            else if(isalpha(arr[i][j]))
                point[arr[i][j] - 'a'].pb({i, j});

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = 1e7;

    vector<int> vis(26, -1);
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    pq.push({0, {sx, sy}});
    dist[sx][sy] = 0;

    while(!pq.empty())
    {
        auto u = pq.top();
        pq.pop();
        int d = u.ff;
        int x = u.ss.ff, y = u.ss.ss;
        bool first = false;
        if(d > dist[x][y])
            continue;
        if(isalpha(arr[x][y]) && arr[x][y] != 'G' && arr[x][y] != 'S')
        {
            if(~vis[arr[x][y] - 'a'])
            {
                if(d > vis[arr[x][y] - 'a'])
                    continue;
            }
            else
            {
                first = true;
                vis[arr[x][y] - 'a'] = d + 1;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '#')
            {
                if(d + 1 < dist[nx][ny])
                {
                    dist[nx][ny] = d + 1;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        if(first) // also an alphabet go to other
        {
            for(auto p : point[arr[x][y] - 'a'])
                if(d + 1 < dist[p.ff][p.ss])
                {
                    dist[p.ff][p.ss] = d + 1;
                    pq.push({dist[p.ff][p.ss], p});
                }
        }
    }

    int ans = dist[ex][ey];
    if(ans >= (int)1e7)
        ans = -1;
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