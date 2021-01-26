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
string dima = "DIMA";
bool inf = false;
char arr[1005][1005];
bool vis[1005][1005];
ll save[1005][1005];
int time_visited[1005][1005];
int n, m;
int turn = 0;
bool valid(int i, int j, int pos)
{
    return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == dima[pos]);
}
ll dfs(int i, int j, int pos)
{
    if(vis[i][j]){
        if(pos == 0 && time_visited[i][j] != turn)
            return save[i][j];
        else
            return 0;
    }
    time_visited[i][j]=turn;
    vis[i][j] = true;
    ll me = 0, child = 0;
    if(pos == 3)
        me++;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int d = 0; d < 4; d++)
    {
        int ni = i + dy[d];
        int nj = j + dx[d];
        if(valid(ni, nj, (pos + 1) % 4))
        {
            if(vis[ni][nj])
            {
                if(time_visited[i][j] == time_visited[ni][nj] && arr[ni][nj] == 'D')
                    inf = true;
            }
            child += dfs(ni, nj, (pos + 1) % 4);
        }
    }
    return save[i][j] = me + child;
}

void cp()
{

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            arr[i][j] = s[j];
    }
    ll here = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 'D')
            {
                turn++;
                dfs(i, j, 0);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // cout<<save[i][j]<<" ";
            here = max(here, save[i][j]);
        }
        // cout<<endl;
    }
    if(inf)
    {
        cout << "Poor Inna!";
    }
    else
    {
        if(!here)
        {
            cout << "Poor Dima!";
        }
        else
            cout << here;
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