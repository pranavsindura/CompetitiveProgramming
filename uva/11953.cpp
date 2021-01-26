#include <bits/stdc++.h>
using namespace std;
bool valid(vector<vector<char>> arr, int i, int j, int n)
{
    if (i < n && i >= 0 && j < n && j >= 0 && arr[i][j] != '.')
        return true;
    else
        return false;
}
void dfs(int i, int j, vector<vector<char>> &arr, int n)
{
    arr[i][j] = '.';
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++)
    {
        if (valid(arr, i + dx[k], j + dy[k], n))
            dfs(i + dx[k], j + dy[k], arr, n);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin>>n;
        vector<vector<char>> arr(n, vector<char>(n));
        // vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 'x')
                {
                    count++;
                    dfs(i, j, arr, n);
                }
            }
        }
        cout << "Case " << tt << ": " << count << endl;
    }
}