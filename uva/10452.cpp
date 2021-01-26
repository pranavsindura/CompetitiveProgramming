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
bool check(char x)
{
    if (x == 'I' || x == 'E' || x == 'H' || x == 'O' || x == 'V' || x == 'A' || x == '#')
        return true;
    else
        return false;
}
int main()
{
    // FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> arr;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            arr.push_back(s);
        }
        int startx, starty, endx, endy;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '@')
                {
                    startx = i;
                    starty = j;
                }
                if (arr[i][j] == '#')
                {
                    endx = i;
                    endy = j;
                }
            }
        }
        bool flag = true;
        int x = startx, y = starty;
        bool vis[n][m];
        vector<string> path;
        memset(vis, false, sizeof(vis));
        while (flag)
        {
            vis[x][y] = true;
            int dx[] = {-1, 0, 0};
            int dy[] = {0, 1, -1};
            string move[] = {"forth", "right", "left"};
            for (int i = 0; i < 3; i++)
            {
                if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m)
                {
                    if (!vis[x + dx[i]][y + dy[i]] && check(arr[x + dx[i]][y + dy[i]]))
                    {
                        x = x + dx[i];
                        y = y + dy[i];
                        path.push_back(move[i]);
                        break;
                    }
                }
            }
            if (x == endx && y == endy)
            {
                break;
            }
        }
        cout << path[0];
        for (int i = 1; i < path.size(); i++)
            cout << " " << path[i];
        cout << endl;
    }
    return 0;
}