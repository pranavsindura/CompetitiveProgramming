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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 50 + 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

bool valid(int i, int j)
{
    return(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && arr[i][j] != '#' && arr[i][j] != 'B');
}

void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        vis[u.ff][u.ss] = true;
        for(int i = 0; i < 4; i++)
        {
            int nx = u.ff + dx[i], ny = u.ss + dy[i];
            if(valid(nx, ny))
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

void cp()
{
    cin >> n >> m;
    clr(vis, false);
    vector<pi> good, bad;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
            if(arr[i][j] == 'G')
                good.pb({i, j});
            else if(arr[i][j] == 'B')
                bad.pb({i, j});
        }
    }
    if(good.empty())
    {
        //If no good People, simply block exit
        cout << "Yes\n";
        return;
    }
    bool ok = true;
    //Block all Bad people
    for(pi b : bad)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = b.ff + dx[i], ny = b.ss + dy[i];
            if(valid(nx, ny))
            {
                //If some Bad man is connected with Good man, he can't be blocked
                if(arr[nx][ny] == 'G' || (nx == n - 1 && ny == m - 1))
                    ok = false;
                //Block Bad man
                else if(arr[nx][ny] == '.')
                    arr[nx][ny] = '#';
            }
        }
    }
    if(!ok)
    {
        cout << "No\n";
        return;
    }
    else
    {
        //Check if Good people can still reach exit with BFS
        bfs(n - 1, m - 1);
        bool all_good = true;
        for(pi g : good)
        {
            if(!vis[g.ff][g.ss])
                all_good = false;
        }
        if(!all_good)
        {
            cout << "No\n";
        }
        else
            cout << "Yes\n";
    }
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