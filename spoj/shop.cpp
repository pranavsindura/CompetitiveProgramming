#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void cp(int n, int m)
{
    char arr[n][m];
    int st_x, st_y, en_x, en_y;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'S')
                st_x = i, st_y = j;
            else if(arr[i][j] == 'D')
                en_x = i, en_y = j;
        }
    }

    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[st_x][st_y] = 0;
    pq.push({0, {st_x, st_y}});
    while(!pq.empty())
    {
        pair<int, pi> node = pq.top();
        pq.pop();
        pi pos = node.ss;
        int d = node.ff;

        if(dist[pos.ff][pos.ss] < d)
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = pos.ff + dx[i];
            int ny = pos.ss + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 'X')
            {
                int cost = 0;
                if(arr[nx][ny] >= '0' && arr[nx][ny] <= '9')
                    cost = arr[nx][ny] - '0';
                if(dist[nx][ny] > dist[pos.ff][pos.ss] + cost)
                {
                    dist[nx][ny] = dist[pos.ff][pos.ss] + cost;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    cout << dist[en_x][en_y];
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    int n, m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        cp(m, n);
        cout << endl;
    }
    return 0;
}