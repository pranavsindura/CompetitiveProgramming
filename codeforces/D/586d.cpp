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

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<string> arr(3);
    for(string &x : arr)
        cin >> x;

    vector<vector<bool>> vis(3, vector<bool>(n + 5));
    queue<pi> q;

    if(arr[0][0] == 's') q.push({0, 0});
    else if(arr[1][0] == 's') q.push({1, 0});
    else q.push({2, 0});

    auto can = [&](int nx, int ny, int step)
    {
    	// For x, stay in bound. For y, either go out of bound or must be empty and unvisited
        return nx >= 0 && nx < 3 && ((ny + step >= n - 1) || (ny + step < n && arr[nx][ny + step] == '.' && !vis[nx][ny + step]));
    };

    bool reach = false;
    while(!q.empty() && !reach)
    {
        pi node = q.front();
        q.pop();
        int x = node.ff, y = node.ss;
        vis[x][y] = 1;
        // reached end
        if(y >= n - 1)
            reach = true;
        // move one step to right
        if(can(x, y, 1))
        {
            int ny = y + 1;
            // go up
            if(can(x - 1, ny, 0))
            {
                int nx = x - 1;
                // then go 2 steps right
                if(can(nx, ny, 1) && can(nx, ny, 2))
                    q.push({nx, ny + 2}), vis[nx][ny + 2] = 1;
            }
            // stay idle
            if(can(x, ny, 0))
            {
                int nx = x;
                // then go 2 steps right
                if(can(nx, ny, 1) && can(nx, ny, 2))
                    q.push({nx, ny + 2}), vis[nx][ny + 2] = 1;
            }
            // go down
            if(can(x + 1, ny, 0))
            {
                int nx = x + 1;
                // then go 2 steps right
                if(can(nx, ny, 1) && can(nx, ny, 2))
                    q.push({nx, ny + 2}), vis[nx][ny + 2] = 1;
            }
        }
    }

    cout << (reach ? "YES\n" : "NO\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}