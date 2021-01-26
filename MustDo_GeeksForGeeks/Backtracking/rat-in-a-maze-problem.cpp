/*
	Rat is at (0,0) wants to reach (N-1, N-1)
	Can only go trough tiles marked 1
	Find all paths
*/
/*
	Approach - Backtracking
	Perform DFS like backtracking
	Mark visited
	process children
	Mark unvisited
*/

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
char dir[] = "RLDU";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[5][5];
bool valid(int i, int j, int n, int arr[MAX][MAX])
{
    return (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && arr[i][j]);
}

void rec(int x, int y, int n, string &path, vector<string> &ans, int arr[MAX][MAX])
{
    vis[x][y] = true;
    if(x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx, ny, n, arr))
            {
                path.push_back(dir[i]);

                rec(nx, ny, n, path, ans, arr);
                
                path.pop_back();
            }
        }
    }
    vis[x][y] = false;
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> ans;
    string path;
    if(m[0][0])
        rec(0, 0, n, path, ans, m);
    sort(begin(ans), end(ans));
    return ans;
}