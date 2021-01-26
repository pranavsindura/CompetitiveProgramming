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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
char arr[505][505], ans[505][505];
bool vis[505][505];
vector<string> ops;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    string op = "B " + to_string(x + 1) + " " + to_string(y + 1);
    ops.pb(op);
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny] == '.')
            dfs(nx, ny);
    }
    op = "D " + to_string(x + 1) + " " + to_string(y + 1);
    ops.pb(op);
    op = "R " + to_string(x + 1) + " " + to_string(y + 1);
    ops.pb(op);
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j] && arr[i][j] == '.')
                dfs(i, j), ops.pop_back(), ops.pop_back();
    cout << sz(ops) << endl;
    for(string &x : ops)
        cout << x << endl;
}

void print()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans[i][j] = arr[i][j];
    for(string &op : ops)
    {
        char t;
        int x, y;
        stringstream ss(op);
        ss >> t >> x >> y;
        if(t == 'B')
            ans[x - 1][y - 1] = 'B';
        else if(t == 'R')
            ans[x - 1][y - 1] = 'R';
        else
            ans[x - 1][y - 1] = arr[x - 1][y - 1];
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
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
    // print();
    return 0;
}