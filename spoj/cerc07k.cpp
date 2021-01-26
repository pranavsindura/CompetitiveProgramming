#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
int vis[105][105][16];
char arr[105][105];
int n, m;

struct state
{
    int x, y, key_mask;
    state(int i, int j, int mask) : x(i), y(j), key_mask(mask) {}
    bool inside()
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(state start)
{
    queue<state> q;
    q.push(start);
    vis[start.x][start.y][start.key_mask] = 0;
    while(!q.empty())
    {
        state u = q.front();
        q.pop();
        // cout << u.x << " " << u.y << " " << u.key_mask << " " << vis[u.x][u.y][u.key_mask] << endl;
        for(int i = 0; i < 4; i++)
        {
            state v(u.x + dx[i], u.y + dy[i], u.key_mask);
            if(v.inside() && arr[v.x][v.y] != '#')
            {
                if(arr[v.x][v.y] == 'X')
                    return vis[u.x][u.y][u.key_mask] + 1;
                if(vis[v.x][v.y][v.key_mask] == -1)
                {
                    if(islower(arr[v.x][v.y]))
                    {

                        if(arr[v.x][v.y] == 'r')
                            v.key_mask |= 1;
                        else if(arr[v.x][v.y] == 'g')
                            v.key_mask |= 2;
                        else if(arr[v.x][v.y] == 'b')
                            v.key_mask |= 4;
                        else if(arr[v.x][v.y] == 'y')
                            v.key_mask |= 8;
                        q.push(v);
                    }
                    else if(isupper(arr[v.x][v.y]))
                    {
                        if(arr[v.x][v.y] == 'R' && (v.key_mask & 1))
                            q.push(v);
                        else if(arr[v.x][v.y] == 'G' && (v.key_mask & 2))
                            q.push(v);
                        else if(arr[v.x][v.y] == 'B' && (v.key_mask & 4))
                            q.push(v);
                        else if(arr[v.x][v.y] == 'Y' && (v.key_mask & 8))
                            q.push(v);
                    }
                    else
                    {
                        q.push(v);
                    }
                    vis[v.x][v.y][v.key_mask] = vis[u.x][u.y][u.key_mask] + 1;
                }
            }
        }
    }
    return -1;
}

void cp()
{
    while(cin >> n >> m)
    {
        if(!n && !m)
            break;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        clr(vis, -1);
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == '*')
                {
                    state st(i, j, 0);
                    ans = bfs(st);
                }
            }
        }
        if(ans == -1)
            cout << "The poor student is trapped!\n";
        else
            cout << "Escape possible in " << ans << " steps.\n";
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