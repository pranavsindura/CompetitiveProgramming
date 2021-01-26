/*
	Find Whether path exists from sx,sy -> ex,ey

	1->src
	2->dest
	Can only move through 3
*/

/*
	Approach - Simple BFS problem
*/

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void cp()
{
    int n, m;
    cin >> n;
    int arr[n][n];
    bool vis[n][n];
    clr(vis, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == 1) sx = i, sy = j;
            else if(arr[i][j] == 2) ex = i, ey = j;

    bool found = false;
    queue<pi> q;
    q.push({sx, sy});
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int x = node.ff;
        int y = node.ss;
        vis[x][y] = true;
        if(x == ex && y == ey)
        {
            found = true;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && (arr[nx][ny] == 3 || arr[nx][ny] == 2))
                vis[nx][ny] = true, q.push({nx, ny});
        }
    }
    cout << found << endl;
}
