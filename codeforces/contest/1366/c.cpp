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
const int MAXN = 1e6 + 5;

pi level[1000];
int max_level = 0;
bool vis[35][35];
void bfs(vector<vector<int>> &arr, int n, int m)
{
    clr(vis, false);
    queue<pair<pi, int>> q;
    q.push({{0, 0}, 0});
    while(!q.empty())
    {
        pair<pi, int> u_node = q.front();
        pi u = u_node.ff;
        int my_level = u_node.ss;
        q.pop();
        vis[u.ff][u.ss] = true;
        max_level = max(max_level, my_level);
        if(arr[u.ff][u.ss] == 1)
            level[my_level].ss++;
        else
            level[my_level].ff++;
        int nx = u.ff + 1, ny = u.ss;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
        {
            q.push({{nx, ny}, my_level + 1});
            vis[nx][ny] = true;
        }
        nx = u.ff, ny = u.ss + 1;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
        {
            q.push({{nx, ny}, my_level + 1});
            vis[nx][ny] = true;
        }
    }
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    max_level = 0;
    for(int i = 0; i < 1000; i++)
        level[i] = {0, 0};
    bfs(arr, n, m);
    int cost = 0;
    max_level++;
    for(int i = 0; i < max_level / 2; i++)
    {
        int cnt_zero = level[i].ff + level[max_level - i - 1].ff;
        int cnt_one = level[i].ss + level[max_level - i - 1].ss;
        if(cnt_one > cnt_zero)
        {
            // convert to one
            cost += cnt_zero;
        }
        else
            cost += cnt_one;
    }
    cout << cost << endl;
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
