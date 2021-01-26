/*
	Flood Fill
	Replace the numbers which form connected component with position x,y with k
*/

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int arr[105][105];
bool valid(int i, int j, int k)
{
    return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == k);
}
void dfs(int x, int y, int k)
{
    int prev_colour = arr[x][y];
    arr[x][y] = k;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx, ny, prev_colour))
            dfs(nx, ny, k);
    }
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    int x, y, k;
    cin >> x >> y >> k;
    dfs(x, y, k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
    cout << endl;
}
