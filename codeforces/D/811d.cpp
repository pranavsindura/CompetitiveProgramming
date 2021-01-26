#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
string dir = "RLDU";

int n, m;
char arr[105][105];
bool vis[505][505];
string path;
bool found;

void dfs(int x, int y, int ex, int ey)
{
    vis[x][y] = 1;
    if(found) return;
    if(x == ex && y == ey) found = true;
    if(found) return;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny] != '*')
        {
            path += dir[i];
            dfs(nx, ny, ex, ey);
            if(found) return;
            path.pop_back();
        }
    }
}

void get(char d, int &x, int &y)
{
    cout << d << endl;
    cout.flush();
    cin >> x >> y;
    if(x == -1 || y == -1) exit(0);
    x--, y--;
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ex, ey;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 'F')
                ex = i, ey = j;
    found = false;
    dfs(0, 0, ex, ey);

    reverse(all(path));
    if(path.empty()) return; // n == 1, m == 1

    // Fix one direction
    int x = 0, y = 0, nx, ny;
    if(path.back() == 'R')
    {
        // go left
        get('L', nx, ny);
        if(nx == x && ny == y) // no change, continue
        {}
        else
        {
            // L and R are swapped
            for(char &c : path)
            {
                if(c == 'L') c = 'R';
                else if(c == 'R') c = 'L';
            }
            get('R', x, y);
        }
    }
    else if(path.back() == 'D')
    {
        // go up
        get('U', nx, ny);
        if(nx == x && ny == y) // no change, continue
        {}
        else
        {
            // U and D are swapped
            for(char &c : path)
            {
                if(c == 'U') c = 'D';
                else if(c == 'D') c = 'U';
            }
            get('D', x, y);
        }
    }

    if(path.empty()) return;
    char last = path.back();
    while(!path.empty() && path.back() == last)
        get(path.back(), x, y), path.pop_back();

    if(path.empty()) return;
    // fix second direction
    if(path.back() == 'R')
    {
        // go left
        get('L', nx, ny);
        if(nx == x && ny == y) // no change, continue
        {}
        else
        {
            // L and R are swapped
            for(char &c : path)
            {
                if(c == 'L') c = 'R';
                else if(c == 'R') c = 'L';
            }
            get('R', x, y);
        }
    }
    else if(path.back() == 'D')
    {
        // go up
        get('U', nx, ny);
        if(nx == x && ny == y) // no change, continue
        {}
        else
        {
            // U and D are swapped
            for(char &c : path)
            {
                if(c == 'U') c = 'D';
                else if(c == 'D') c = 'U';
            }
            get('D', x, y);
        }
    }

    while(!path.empty())
        get(path.back(), x, y), path.pop_back();
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

