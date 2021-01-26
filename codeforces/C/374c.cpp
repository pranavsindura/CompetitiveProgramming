#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e3 + 5;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
char arr[MAXN][MAXN];
bool vis[MAXN][MAXN], in_stack[MAXN][MAXN];
int dp[MAXN][MAXN];
bool inf = false;

string dima = "DIMA";

bool ok(int x, int y, int c)
{
    return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == dima[c]);
}

int dfs(int x, int y, int c)
{
    if(inf)
        return 0;
    if(vis[x][y])
        return dp[x][y];

    vis[x][y] = 1;
    in_stack[x][y] = 1;

    int child = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(ok(nx, ny, (c + 1) % 4))
        {
            if(in_stack[nx][ny])
                inf = true;
            else
                child = max(child, dfs(nx, ny, (c + 1) % 4));
        }
    }

    in_stack[x][y] = 0;
    return dp[x][y] = (c == 3) + child;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'D')
                ans = max(ans, dfs(i, j, 0));

    if(inf)
        cout << "Poor Inna!\n";
    else if(!ans)
        cout << "Poor Dima!\n";
    else
        cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}