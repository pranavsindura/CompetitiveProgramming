#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
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
int col[101];
int row;
// vector<vector<bool>> vis(101);
bool vis[101][100002];

struct state
{
    int x, y, steps;
    state(int a = 0, int b = 0, int c = 0)
    {
        x = a, y = b, steps = c;
    }
};
queue<state> q;
int bfs(int r1, int c1, int r2, int c2)
{
    state st(r1, c1, 0);
    q.push(st);
    int ans = INT_MAX;
    while(!q.empty())
    {
        state u = q.front();
        q.pop();
        vis[u.x][u.y] = true;
        if(u.x == r2 && u.y == c2)
        {
            ans = min(ans, u.steps);
            break;
        }

        int new_x, new_y;
        //go up
        new_x = u.x - 1;
        new_x = max(new_x, 1);
        new_y = u.y;
        new_y = min(new_y, col[new_x] + 1);
        if(!vis[new_x][new_y])
        {
            if(abs(u.x - r2) > abs(r2 - new_x) || abs(u.y - c2) >= abs(c2 - new_y))
                q.push(state(new_x, new_y, u.steps + 1)), vis[new_x][new_y] = true;
        }
        //go down
        new_x = u.x + 1;
        new_x = min(new_x, row);
        new_y = u.y;
        new_y = min(new_y, col[new_x] + 1);
        if(!vis[new_x][new_y])
        {
            if(abs(u.x - r2) > abs(r2 - new_x) || abs(u.y - c2) >= abs(c2 - new_y))
                q.push(state(new_x, new_y, u.steps + 1)), vis[new_x][new_y] = true;
        }
        //go left
        new_x = u.x;
        new_y = u.y - 1;
        new_y = max(new_y, 1);
        if(!vis[new_x][new_y])
        {
            if(abs(u.y - c2) > abs(c2 - new_y))
                q.push(state(new_x, new_y, u.steps + 1)), vis[new_x][new_y] = true;
        }
        //go right
        new_x = u.x;
        new_y = u.y + 1;
        new_y = min(new_y, col[u.x] + 1);
        if(!vis[new_x][new_y])
        {
            if(abs(u.y - c2) > abs(c2 - new_y))
                q.push(state(new_x, new_y, u.steps + 1)), vis[new_x][new_y] = true;
        }
    }
    return ans;
}
int r1, c1, r2, c2;
int ans = INT_MAX;
void dfs(state u)
{
    if(u.x == r2 && u.y == c2)
    {
        ans = min(ans, u.steps);
        return;
    }
    vis[u.x][u.y] = true;
    int new_x, new_y;
    //go up
    new_x = u.x - 1;
    new_x = max(new_x, 1);
    new_y = u.y;
    new_y = min(new_y, col[new_x] + 1);
    if(!vis[new_x][new_y])
        dfs(state(new_x, new_y, u.steps + 1));
    //go down
    new_x = u.x + 1;
    new_x = min(new_x, row);
    new_y = u.y;
    new_y = min(new_y, col[new_x] + 1);
    if(!vis[new_x][new_y])
        dfs(state(new_x, new_y, u.steps + 1));
    //go left
    new_x = u.x;
    new_y = u.y - 1;
    new_y = max(new_y, 1);
    if(!vis[new_x][new_y])
        dfs(state(new_x, new_y, u.steps + 1));
    //go right
    new_x = u.x;
    new_y = u.y + 1;
    new_y = min(new_y, col[u.x] + 1);
    if(!vis[new_x][new_y])
        dfs(state(new_x, new_y, u.steps + 1));
}

void cp()
{
    cin >> row;
    for(int i = 1; i <= row; i++)
    {
        cin >> col[i];
        // vis[i] = vector<bool>(col[i] + 2);
    }
    cin >> r1 >> c1 >> r2 >> c2;
    cout << bfs(r1, c1, r2, c2);
    // dfs(state(r1, c1, 0));
    // cout<<ans;
}

int main()
{
    FASTIO;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}