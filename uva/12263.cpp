#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 505;

int g[512][512], indeg[512];
void topo(int n)
{
    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            Q.push(i);
    }
    int r[512], rt = 0, u;
    while (!Q.empty())
    {
        u = Q.front(), Q.pop();
        r[rt++] = u;
        for (int i = 1; i <= n; i++)
        {
            if (g[u][i])
            {
                if (--indeg[i] == 0)
                    Q.push(i);
            }
        }
    }
    if (rt != n)
    {
        puts("IMPOSSIBLE");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", r[i], i == n - 1 ? '\n' : ' ');
    }
}
int main()
{
    int testcase, rank[512];
    int n, m, x, y;
    scanf("%d", &testcase);
    while (testcase--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &rank[i]);

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                g[rank[i]][rank[j]] = 1;

        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            swap(g[x][y], g[y][x]);
        }

        for (int i = 1; i <= n; i++)
        {
            indeg[i] = 0;
            for (int j = 1; j <= n; j++)
                indeg[i] += g[j][i];
        }
        topo(n);
    }
    return 0;
}