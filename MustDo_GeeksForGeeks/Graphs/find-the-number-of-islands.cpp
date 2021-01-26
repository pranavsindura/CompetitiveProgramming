/*
	Find Number of Islands in Matrix
	Islands are 1s connected by 8 directions
*/

/*
	Approach - DFS
	Basic question on number of connected components
*/
bool vis[105][105];
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
void dfs(int x, int y, int N, int M, vector<int> A[])
{
    vis[x][y] = true;
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] && A[nx][ny] == 1)
            dfs(nx, ny, N, M, A);
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    memset(vis, false, sizeof vis);
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!vis[i][j] && A[i][j] == 1)
                cnt++, dfs(i, j, N, M, A);
        }
    }
    return cnt;
}