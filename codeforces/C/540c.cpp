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
const int MAXN = 1e6 + 5;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

char arr[505][505];
bool vis[505][505];

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;

    if(sx == ex && sy == ey)
    {
        int cnt = 0;
        for(int i = 0; i < 4; i++)
        {
            int nx = sx + dx[i], ny = sy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == '.')
                cnt++;
        }
        cout << (cnt >= 1 ? "YES\n" : "NO\n");
        return;
    }

    bool was_x = (arr[ex][ey] == 'X');
    arr[ex][ey] = '.';
    queue<pi> q;
    q.push({sx, sy});
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int x = node.ff, y = node.ss;
        vis[x][y] = 1;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny] == '.')
            {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }

    if(vis[ex][ey])
    {
        if(was_x)
            cout << "YES\n";
        else
        {
            int cnt = 0;
            for(int i = 0; i < 4; i++)
            {
                int nx = ex + dx[i], ny = ey + dy[i];
                if((nx == sx && ny == sy) || (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == '.'))
                    cnt++;
            }
            cout << (cnt >= 2 ? "YES\n" : "NO\n");
        }
    }
    else
        cout << "NO\n";
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