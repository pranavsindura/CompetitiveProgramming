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

bool vis[1005][1005];
bool vis2[1005][1005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


deque<pair<pi, int>> q;
void cp()
{
    int n, m, sx, sy, ex, ey;
    cin >> n >> m >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;

    int ans = INT_MAX;

    if(arr[sx][sy] != '#')
        q.push_back({{sx, sy}, 0});

    while(!q.empty())
    {
        auto node = q.front();
        q.pop_front();
        int x = node.ff.ff, y = node.ff.ss, d = node.ss;
        vis[x][y] = vis2[x][y] = true;

        if(x == ex && y == ey)
        {
            ans = min(ans, d);
            continue;
        }
        // move A
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny] == '.')
                q.push_front({{nx, ny}, d}), vis[nx][ny] = true;
        }

        // moveB
        for(int i = -2; i <= 2; i++)
        {
            for(int j = -2; j <= 2; j++)
            {
                if(!i && !j)
                    continue;
                int nx = x + i, ny = y + j;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && !vis2[nx][ny] && arr[nx][ny] == '.')
                    q.push_back({{nx, ny}, d + 1}), vis2[nx][ny] = true;
            }
        }
    }
    
    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
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