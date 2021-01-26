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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int n, m;
char arr[55][55];
bool vis[55][55];
bool in_stack[55][55];

bool valid(int i, int j, char match)
{
    return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == match);
}

bool dfs(int x, int y, int p_dir)
{
    vis[x][y] = true;
    in_stack[x][y] = true;
    bool cycle = false;
    int rev = 4 - p_dir - 1;
    for(int i = 0; i < 4; i++)
    {
        if(i == rev)
            continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx, ny, arr[x][y]))
        {
            if(!vis[nx][ny])
            {
                bool me = dfs(nx, ny, i);
                cycle = me || cycle;
            }
            else if(in_stack[nx][ny])
                cycle = true;
        }
    }

    in_stack[x][y] = false;
    return cycle;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    // Since we are in a 2D Grid, we need at least 4 points to form a cycle
    // That is also what the question requires, so we need not check the length of the cycle
    bool cycle = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j])
            {
                bool me = dfs(i, j, -1);
                cycle = cycle || me;
            }
        }
    }
    cout << (cycle ? "Yes" : "No");
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