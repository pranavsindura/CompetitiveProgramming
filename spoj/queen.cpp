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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
bool blocked[1005][1005];
int vis[1005][1005];
int ans[1005][1005];
bool valid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m && !blocked[i][j]);
}
int bfs(pii st, pii en, int n, int m)
{
    queue<pii> q;
    q.push(st);
    vis[st.ff][st.ss] = 255;
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
    bool ok = false;
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        if(u == en)
        {
            return ans[u.ff][u.ss];
        }
        for(int i = 0; i < 8; i++)
        {
            int j = 1;
            while(true)
            {
                if(valid(u.ff + dy[i]*j, u.ss + dx[i]*j, n, m) &&
                        !(vis[u.ff + dy[i]*j][u.ss + dx[i]*j] & (1 << i)))
                {
                    if(!vis[u.ff + dy[i]*j][u.ss + dx[i]*j])
                        ans[u.ff + dy[i]*j][u.ss + dx[i]*j] = ans[u.ff][u.ss] + 1, q.push(mp(u.ff + dy[i] * j, u.ss + dx[i] * j));
                    vis[u.ff + dy[i]*j][u.ss + dx[i]*j] |= (1 << i);
                }
                else
                    break;
                j++;
            }
        }
    }

    return -1;
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        pii st, en;
        memset(blocked, false, sizeof(blocked));
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                if(s[j] == 'S')
                    st = mp(i, j);
                else if(s[j] == 'F')
                    en = mp(i, j);
                else if(s[j] == 'X')
                    blocked[i][j] = true;
            }
        }
        cout << bfs(st, en, n, m) << endl;
    }
    return 0;
}