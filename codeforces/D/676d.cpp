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
const int MAXN = 1e3 + 5;

int n, m;
char arr[MAXN][MAXN];
bool vis[MAXN][MAXN][4];
map<char, vector<char>> M;

struct state
{
    int x, y, t, steps;
    state() {}
    state(int x, int y, int t, int steps): x(x), y(y), t(t), steps(steps) {}
};

bool valid(int x, int y, int t)
{
    return !(x < 0 || x >= n || y < 0 || y >= m || vis[x][y][t] || arr[x][y] == '*');
}

bool left(int x, int y, int t)
{
    char c = M[arr[x][y]][t];
    return (c == '+' || c == '-' || c == '<' || c == 'U' || c == 'R' || c == 'D');
}

bool right(int x, int y, int t)
{
    char c = M[arr[x][y]][t];
    return (c == '+' || c == '-' || c == '>' || c == 'U' || c == 'L' || c == 'D');
}

bool up(int x, int y, int t)
{
    char c = M[arr[x][y]][t];
    return (c == '+' || c == '|' || c == '^' || c == 'L' || c == 'R' || c == 'D');
}

bool down(int x, int y, int t)
{
    char c = M[arr[x][y]][t];
    return (c == '+' || c == '|' || c == 'v' || c == 'L' || c == 'R' || c == 'U');
}

int bfs(int sx, int sy, int ex, int ey)
{
    queue<state> q;
    q.push(state(sx, sy, 0, 0));
    while(!q.empty())
    {
        state u = q.front();
        q.pop();
        int x = u.x, y = u.y, t = u.t, steps = u.steps;
        if(x == ex && y == ey) return steps;
        vis[x][y][t] = 1;

        int nx, ny, nt = (t + 1) % 4;

        // stay
        if(valid(x, y, nt))
            vis[x][y][nt] = 1, q.push(state(x, y, nt, steps + 1));

        nt = t;
        // go left
        nx = x, ny = y - 1;
        if(valid(nx, ny, nt) && left(x, y, t) && right(nx, ny, t))
            vis[nx][ny][nt] = 1, q.push(state(nx, ny, nt, steps + 1));

        // go right
        nx = x, ny = y + 1;
        if(valid(nx, ny, nt) && right(x, y, t) && left(nx, ny, t))
            vis[nx][ny][nt] = 1, q.push(state(nx, ny, nt, steps + 1));

        // go up
        nx = x - 1, ny = y;
        if(valid(nx, ny, nt) && up(x, y, t) && down(nx, ny, t))
            vis[nx][ny][nt] = 1, q.push(state(nx, ny, nt, steps + 1));

        // go down
        nx = x + 1, ny = y;
        if(valid(nx, ny, nt) && down(x, y, t) && up(nx, ny, t))
            vis[nx][ny][nt] = 1, q.push(state(nx, ny, nt, steps + 1));
    }
    return -1;
}

void cp()
{
    int sx, sy, ex, ey;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sx >> sy;
    cin >> ex >> ey;
    sx--, sy--, ex--, ey--;

    M['+'] = {'+', '+', '+', '+'};
    M['-'] = {'-', '|', '-', '|'};
    M['|'] = {'|', '-', '|', '-'};
    M['^'] = {'^', '>', 'v', '<'};
    M['>'] = {'>', 'v', '<', '^'};
    M['v'] = {'v', '<', '^', '>'};
    M['<'] = {'<', '^', '>', 'v'};
    M['L'] = {'L', 'U', 'R', 'D'};
    M['U'] = {'U', 'R', 'D', 'L'};
    M['R'] = {'R', 'D', 'L', 'U'};
    M['D'] = {'D', 'L', 'U', 'R'};

    int ans = bfs(sx, sy, ex, ey);
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

