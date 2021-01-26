/*
	Minimum cost path from (1,1) -> (n-1, n-1)

	Can move Up, Down, Left, Right
*/
/*
	Approach 1 - Dijkstra on 2D matrix
*/

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j, int n)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void cp()
{
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    int dist[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = INT_MAX;
    // 0,0 -> n-1,n-1
    dist[0][0] = arr[0][0];

    priority_queue< pair<int, pi>, vector< pair<int, pi> >, greater<pair<int, pi>> > pq;
    pq.push({dist[0][0], {0, 0}});

    while(!pq.empty())
    {
        pair<int, pi> node = pq.top();
        pq.pop();
        int x = node.ss.ff;
        int y = node.ss.ss;
        int d = node.ff;
        if(dist[x][y] < d)
            continue;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(valid(nx, ny, n))
            {
                // relax position
                if(dist[nx][ny] > dist[x][y] + arr[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + arr[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }

    cout << dist[n - 1][n - 1] << endl;
}
