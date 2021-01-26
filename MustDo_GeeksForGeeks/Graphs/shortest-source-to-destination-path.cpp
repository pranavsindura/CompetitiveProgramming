/*
	Binary Matrix
	Find shortest path from 0,0 to x,y
	Can only move through 1s
*/

/*
	Approach 1 - Simple  BFS problem
*/
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void cp()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    bool vis[n][m];
    clr(vis, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    int ex, ey;
    cin >> ex >> ey;

    int ans = INT_MAX;
    queue<pair<pi, int>> q;
    if(arr[0][0])
        q.push({{0, 0}, 0});
    while(!q.empty())
    {
        pair<pi, int> node = q.front();
        q.pop();
        int x = node.ff.ff;
        int y = node.ff.ss;
        int dist = node.ss;
        vis[x][y] = true;
        if(x == ex && y == ey)
        {
            ans = dist;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny])
                vis[nx][ny] = true, q.push({{nx, ny}, dist + 1});
        }
    }
    if(ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
