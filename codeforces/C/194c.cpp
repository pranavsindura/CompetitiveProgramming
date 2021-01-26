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
const int MAXN = 1e5 + 5;

vector<string> arr;
bool vis[55][55];

void dfs(int i, int j, int n, int m)
{
    if(i < 0 || i >= n) return;
    if(j < 0 || j >= m) return;
    if(arr[i][j] == '.' || vis[i][j]) return;
    vis[i][j] = 1;
    dfs(i + 1, j, n, m);
    dfs(i - 1, j, n, m);
    dfs(i, j + 1, n, m);
    dfs(i, j - 1, n, m);
}

int component()
{
    int n = sz(arr), m = sz(arr[0]), comp = 0;
    clr(vis, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == '#' && !vis[i][j])
                dfs(i, j, n, m), comp++;
    return comp;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int mn = 0, cnt = 0;
    for(string &x : arr)
        for(char y : x)
            cnt += y == '#';

    mn = cnt <= 2 ? -1 : 2;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == '#')
            {
                arr[i][j] = '.';
                if(component() > 1)
                    mn = min(mn, 1);
                arr[i][j] = '#';
            }
        }
    }

    cout << mn << endl;
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