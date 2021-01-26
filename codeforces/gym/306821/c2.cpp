#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e3 + 5;

char arr[MAXN][MAXN];
int ID[MAXN][MAXN];
int ans[MAXN * MAXN];

int n, m;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !ID[x][y]);
}

void dfs(int x, int y, int T)
{
    ID[x][y] = T;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(valid(nx, ny))
        {
            if(arr[nx][ny] == '.')
                dfs(nx, ny, T);
            else
                ans[T]++;
        }
    }
}

void cp()
{
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int N = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(valid(i, j) && arr[i][j] == '.')
                ++N, dfs(i, j, N);
    while(k--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << ans[ID[u][v]] << endl;
    }
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

