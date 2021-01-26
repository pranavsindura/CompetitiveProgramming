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
char arr[8][8];
bool vis[8][8];
int dx[] = {0, 0, 1, -1, -1, 1, -1, 1, 0};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1, 0};

bool dfs(int x, int y, int steps)
{
    if(steps > 8)
        return true;
    if(arr[x][y] == 'A')
        return true;
    bool ok = false;
    for(int i = 0; i < 9; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if((nx < 0) || nx >= 8 || (ny < 0) || ny >= 8)
            continue;
        if(nx - steps >= 0 && arr[nx - steps][ny] == 'S')
            continue;
        if(nx - steps - 1 >= 0 && arr[nx - steps - 1][ny] == 'S')
            continue;
        if(dfs(nx, ny, steps + 1))
            return true;
    }
    return false;
}
void cp()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> arr[i][j];
    bool win = dfs(7, 0, 0);
    if(win)
        cout << "WIN";
    else
        cout << "LOSE";
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