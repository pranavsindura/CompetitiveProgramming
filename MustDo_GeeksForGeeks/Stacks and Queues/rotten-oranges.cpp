/*
    Find minimum time it takes to rot all oranges
    0 -> empty
    1 -> fresh
    2 -> rotten
*/

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
// 0 empty
// 1 fresh
// 2 rotten
int arr[105][105];
int dist[105][105];
int n, m;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 1);
}

void bfs(queue<pair<pi, int>> &q)
{
    while(!q.empty())
    {
        pair<pi, int> node = q.front();
        q.pop();
        pi u = node.ff;
        int lvl = node.ss;
        arr[u.ff][u.ss] = 2;
        dist[u.ff][u.ss] = min(dist[u.ff][u.ss], lvl);
        for(int i = 0; i < 4; i++)
        {
            int nx = u.ff + dx[i], ny = u.ss + dy[i];
            if(valid(nx, ny))
            {
                q.push({{nx, ny}, lvl + 1});
                arr[nx][ny] = 2;
                vis[nx][ny] = true;
            }
        }
    }
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j], dist[i][j] = INT_MAX;
    queue<pair<pi, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 2)
                q.push({{i, j}, 0});
        }
    }

    bfs(q);

    int mx = INT_MIN;
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 2)
                mx = max(mx, dist[i][j]);
            else if(arr[i][j] == 1)
                ok = false;
        }
    }
    if(!ok)
        cout << -1 << endl;
    else
        cout << mx << endl;
}