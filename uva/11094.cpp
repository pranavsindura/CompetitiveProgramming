#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

char v[25][25];
bool vis[25][25];
char land;
int n, m;

int csize = 0;
void dfs(int i, int j)
{
    if(j < 0)
        j = m - 1;
    if(j >= m)
        j = 0;
    if(i < 0 || i >= n)
        return;
    if(vis[i][j] || v[i][j] != land)
        return;
    vis[i][j] = true;
    csize++;
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
}

int main()
{
    int x, y;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s", v[i]);
        }
        scanf("%d %d", &x, &y);
        land = v[x][y];
        memset(vis, false, sizeof(vis));
        dfs(x, y);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                csize = 0;
                dfs(i, j);
                ans = max(ans, csize);
            }

        }
        printf("%d\n", ans);
    }
}