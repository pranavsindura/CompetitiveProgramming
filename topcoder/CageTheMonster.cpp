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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
class CageTheMonster
{
public:

    bool bfs(vector<string> arr, int sx, int sy, int n, int m)
    {
        queue<pi> q;
        q.push({sx, sy});
        vector<vector<bool>> vis(n, vector<bool>(m));
        while(!q.empty())
        {
            pi node = q.front();
            q.pop();
            int x = node.ff, y = node.ss;
            vis[x][y] = true;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if(arr[nx][ny] != '#' && arr[nx][ny] != 'F' && !vis[nx][ny])
                        q.push({nx, ny}), vis[nx][ny] = true;
                }
                else
                    return false;
            }
        }
        return true;
    }

    int capture(vector<string> arr)
    {
        int ans = INT_MAX;
        int n = sz(arr);
        int m = sz(arr[0]);
        for(int a = 0; a <= 1; a++)//top
        {
            for(int b = 0; b <= 1; b++)//left
            {
                for(int c = 0; c <= 1; c++)//bottom
                {
                    for(int d = 0; d <= 1; d++)//right
                    {
                        bool any = false;
                        for(int i = 0; i < n; i++)
                        {
                            for(int j = 0; j < m; j++)
                            {
                                if(arr[i][j] != '^')
                                    continue;

                                // Mark Force Fields
                                vector<string> map = arr;
                                if(a && i - 1 >= 0)
                                    for(int k = 0; k < m; k++)
                                        map[i - 1][k] = 'F';
                                if(b && j - 1 >= 0)
                                    for(int k = 0; k < n; k++)
                                        map[k][j - 1] = 'F';
                                if(c && i + 1 < n)
                                    for(int k = 0; k < m; k++)
                                        map[i + 1][k] = 'F';
                                if(d && j + 1 < m)
                                    for(int k = 0; k < n; k++)
                                        map[k][j + 1] = 'F';
                                    
                                bool me = bfs(map, i, j, n, m);
                                any |= me;
                            }
                        }

                        if(any)
                            ans = min(ans, a + b + c + d);
                    }
                }
            }
        }

        if(ans == INT_MAX)
            ans = -1;
        return ans;
    }
};

int main()
{
    CageTheMonster c;
    vector<string> inp =
	
{
"#....",
"^#...",
"#...."}


;

    cout << c.capture(inp) << endl;
    return 0;
}