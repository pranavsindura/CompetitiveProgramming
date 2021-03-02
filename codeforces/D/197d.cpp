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
const int MAXN = 1500 + 5;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

bool vis[MAXN][MAXN];
char arr[MAXN][MAXN];
array<int, 2> did[MAXN][MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int sx, sy;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'S')
                sx = i, sy = j;

    bool ok = false;

    queue<vector<int>> q;
    q.push({sx, sy, sx, sy});
    while(!q.empty() && !ok)
    {
        vector<int> u = q.front();
        q.pop();

        int x = u[0], y = u[1], X = u[2], Y = u[3];
        did[X][Y] = {x, y};
        vis[X][Y] = 1;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            int nX = X + dx[i], nY = Y + dy[i];
            nX = (nX + n) % n, nY = (nY + m) % m;
            if(arr[nX][nY] != '#')
            {
                if(!vis[nX][nY])
                {
                    q.push({nx, ny, nX, nY});
                    vis[nX][nY] = 1;
                    did[nX][nY] = {nx, ny};
                }
                else if(nx != did[nX][nY][0] || ny != did[nX][nY][1]) ok = true;
            }
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
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
