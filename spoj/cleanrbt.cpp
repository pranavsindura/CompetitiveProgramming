#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
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
char arr[25][25];
int dist[11][11];
int dist_from_start[11];
int n, m;
vector<pii> dirty;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(pii a)
{
    return (a.ff >= 0 && a.ff < n && a.ss >= 0 && a.ss < m);
}

int bfs(pii st, pii en)
{
    queue<pair<pii, int>> q;
    q.push({st, 0});
    bool vis[25][25];
    clr(vis, false);
    vis[st.ff][st.ss] = true;
    int ans = INT_MAX;
    while(!q.empty())
    {
        pair<pii, int> x = q.front();
        q.pop();
        pii u = x.ff;
        int steps = x.ss;
        vis[u.ff][u.ss] = true;

        if(u == en)
        {
            ans = steps;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            pii v = {u.ff + dx[i], u.ss + dy[i]};
            if(valid(v) && !vis[v.ff][v.ss] && arr[v.ff][v.ss] != 'x')
            {
                vis[v.ff][v.ss] = true;
                q.push({v, steps + 1});
            }
        }
    }
    return ans;
}

int rec(int pos, int mask)
{
    if(mask == (1 << sz(dirty)) - 1)
        return 0;
    else
    {
        int ans = INT_MAX;
        for(int i = 0; i < sz(dirty); i++)
        {
            if(!(mask & (1 << i)))
            {
                ans = min(
                          ans,
                          rec(i, mask | (1 << i)) + dist[i][pos]
                      );
            }
        }
        return ans;
    }
}

void cp()
{
    while(cin >> n >> m)
    {

        if(!n && !m)
            break;
        dirty.clear();
        pii st;
        bool ok = true;
        swap(n, m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '*')
                    dirty.pb({i, j});
                if(arr[i][j] == 'o')
                    st = {i, j};
            }
        }
        for(int i = 0; i < sz(dirty); i++)
        {
            for(int j = i + 1; j < sz(dirty); j++)
            {
                dist[i][j] = bfs(dirty[i], dirty[j]);
                // cout << dirty[i].ff << "," << dirty[i].ss << " " << dirty[j].ff << "," << dirty[j].ss << " " << dist[i][j] << endl;
                dist[j][i] = dist[i][j];
                if(dist[i][j] == INT_MAX)
                    ok = false;

            }
        }
        for(int i = 0; i < sz(dirty); i++)
        {
            dist_from_start[i] = bfs(st, dirty[i]);
            if(dist_from_start[i] == INT_MAX)
                ok = false;
        }
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        int ans = INT_MAX;
        for(int i = 0; i < sz(dirty); i++)
        {
            ans = min(
                      ans,
                      dist_from_start[i] + rec(i, 1 << i)
                  );
        }
        if(ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;

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