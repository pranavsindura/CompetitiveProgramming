#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

void cp()
{
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i = 0; i < n; i++)
	    cin >> grid[i];
	array<int, 2> lab;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(grid[i][j] == 'L')
				lab = {i, j};

	vector<vector<bool>> can_reach(n, vector<bool>(m));
	queue<array<int, 2>> q;
	q.push(lab);
	while(!q.empty())
	{
		auto nd = q.front();
		q.pop();
		int x = nd[0], y = nd[1];

		vector<array<int, 2>> can_go;
		int already_explored = 0;
		for(int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#')
			{
				if(!can_reach[nx][ny])
					can_go.push_back({nx, ny});
				else
					already_explored++;
			}
		}

		if(sz(can_go) <= 1 || grid[x][y] == 'L')
		{
			grid[x][y] = '+';
			can_reach[x][y] = 1;
			for(auto nd: can_go)
			{
				int nx = nd[0], ny = nd[1];
				q.push({nx, ny});
			}
		}
	}

	grid[lab[0]][lab[1]] = 'L';

	for(int i = 0; i < n; i++)
		cout << grid[i] << endl;
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
