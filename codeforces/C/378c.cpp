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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

int n, m, k;
char arr[505][505];
int depth[505][505];
bool vis[505][505];
vector<vector<pair<int, int>>> level(505 * 505, vector<pair<int, int>>());
int max_depth = 0;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && arr[i][j] == '.');
}

void dfs(int i, int j, int depth)
{
    vis[i][j] = true;
    level[depth].pb(mp(i, j));
    max_depth = max(max_depth, depth);
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for(int d = 0; d < 4; d++)
    {
        if(valid(i + dy[d], j + dx[d]))
            dfs(i + dy[d], j + dx[d], depth + 1);
    }

}

void cp()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    pair<int, int> st;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == '.')
            {
                st = mp(i, j);
            }
        }
    }
    dfs(st.ff, st.ss, 0);
    for(int i = max_depth; i >= 0 && k; i--)
    {
        for(int j = 0; j < sz(level[i]) && k; j++)
        {
            pair<int, int> u = level[i][j];
            arr[u.ff][u.ss] = 'X';
            k--;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
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