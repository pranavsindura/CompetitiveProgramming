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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char arr[50][50];
int dest_idx[50][50];
int dist[20][20];
int n, m;

void bfs(int idx, int sx, int sy)
{
    int temp[50][50] = {0};
    bool vis[50][50] = {0};
    queue<pi> q;
    q.push({sx, sy});
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int x = node.ff, y = node.ss;
        vis[x][y] = 1;
        if(arr[x][y] == 'X')
            dist[idx][dest_idx[x][y]] = temp[x][y];

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '#' && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                temp[nx][ny] = temp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    int src = 0, dest = 0;

    clr(dest_idx, -1), clr(dist, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'X')
                dest_idx[i][j] = dest++;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'B')
                bfs(src++, i, j);

    for(int i = 0; i < src; i++)
        for(int j = 0; j < src; j++)
            if(dist[i][j] == -1)
                dist[i][j] = 5000;

    vector<vector<int>> masks(1 << src);
    for(int i = 0; i < 1 << src; i++)
        masks[__builtin_popcount(i)].pb(i);

    int dp[1 << src];
    for(int i = 0; i < 1 << src; i++)
        dp[i] = 5000;
    
    dp[0] = 0;
    for(int i = 0; i < src; i++)
        for(int msk : masks[i])
            for(int j = 0; j < dest; j++)
                if(!((msk >> j) & 1))
                    dp[msk | (1 << j)] = min(dp[msk | (1 << j)], dp[msk] + dist[i][j]);

    cout << dp[(1 << src) - 1] << endl;
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