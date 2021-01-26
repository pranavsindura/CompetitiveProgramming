#include <bits/stdc++.h>
#define ll long long int
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define all(x) x.begin(), x.end()
using namespace std;

void dfs(vector<vector<int>> img, int x, int y, vector<vector<bool>> &vis, int n)
{
    vis[x][y] = true;
    int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
    for (int i = 0; i < 8; i++)
    {
        if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
        {
            if (!vis[x + dx[i]][y + dy[i]] && img[x + dx[i]][y + dy[i]])
                dfs(img, x + dx[i], y + dy[i], vis, n);
        }
    }
}

int main()
{
    FASTIO;
    int n, c = 1;
    while (cin >> n)
    {
        vector<vector<int>> img(n, vector<int>(n));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                img[i][j] = s[j] - '0';
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img[i][j] && !vis[i][j])
                {
                    ans++;
                    dfs(img, i, j, vis, n);
                }
            }
        }
        cout << "Image number " << c++ << " contains " << ans << " war eagles." << endl;
    }
    return 0;
}