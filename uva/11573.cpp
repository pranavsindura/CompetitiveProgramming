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
const int MAXN = 1e3 + 5;
int arr[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dr[] = {-1, -1, 0, 1, 1, 1,  0, -1};
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1};
int n, m;
bool valid(pii pos)
{
    int i = pos.ff, j = pos.ss;
    return(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]);
}
int dijkstra(pii st, pii en)
{
    clr(vis, false);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = INT_MAX;
    dist[st.ff][st.ss] = 0;
    set<pair<int, pii>> s;
    s.insert({0, st});
    while(!s.empty())
    {
        pii u = s.begin()->ss;
        s.erase(s.begin());
        vis[u.ff][u.ss] = true;
        for(int i = 0; i < 8; i++)
        {
            pii v = {u.ff + dr[i], u.ss + dc[i]};
            int cost = arr[u.ff][u.ss] != i;
            if(valid(v))
            {
                if(dist[u.ff][u.ss] + cost < dist[v.ff][v.ss])
                {
                    s.erase({dist[v.ff][v.ss], v});

                    dist[v.ff][v.ss] = dist[u.ff][u.ss] + cost;

                    s.insert({dist[v.ff][v.ss], v});
                }
            }
        }
    }
    return dist[en.ff][en.ss];
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            arr[i][j] = s[j] - '0';
    }
    int q;
    cin >> q;
    while(q--)
    {
        pii st, en;
        cin >> st.ff >> st.ss >> en.ff >> en.ss;
        st.ff--, st.ss--, en.ff--, en.ss--;
        cout << dijkstra(st, en) << endl;
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