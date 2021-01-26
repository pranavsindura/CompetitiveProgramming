/*
    TRAVERSE A MATRIX SPIRALLY

    Change direction whenever you reach a position that is out of bounds or has been visited before
*/
//0 -> right
//1 -> down
//2 -> left
//3 -> up
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void cp()
{
    int n,m;
    cin >> n >> m;
    bool vis[n][m];
    int arr[n][m];
    vector<int> res;
    clr(vis, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    int dir = 0;
    int cnt = 0;
    int i = 0, j = 0;
    int last_i = 0, last_j = 0;
    while(cnt < n * m)
    {
        while(!vis[i][j] && i >= 0 && i < n && j >= 0 && j < m)
        {
            last_i = i, last_j = j;
            cnt++;
            vis[i][j] = true;
            res.pb(arr[i][j]);
            i = i + dy[dir], j = j + dx[dir];
        }
        dir = (dir + 1) % 4;
        i = last_i + dy[dir], j = last_j + dx[dir];
    }
    for(int x : res)
        cout << x << " ";
    cout << endl;
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