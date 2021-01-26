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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int arr[15][105];
int min_cost_path[15][105];
vector<int> min_path[15][105];
int n, m;
int find_cost(int row, int col)
{
    if(~min_cost_path[row][col])
        return min_cost_path[row][col];
    if(col == 0)
    {
        return min_cost_path[row][col] = arr[row][col];
    }
    else
    {
        int choice1 = find_cost((row - 1 + n) % n, col - 1);
        int choice2 = find_cost(row, col - 1);
        int choice3 = find_cost((row + 1) % n, col - 1);

        int best = min({choice1, choice2, choice3});

        return min_cost_path[row][col] = arr[row][col] + best;
    }
}

vector<int> gen_path(int row, int col)
{
    if(sz(min_path[row][col]))
        return min_path[row][col];
    if(col == 0)
    {
        return min_path[row][col] = {row};
    }
    else
    {
        int choice1 = find_cost((row - 1 + n) % n, col - 1);
        int choice2 = find_cost(row, col - 1);
        int choice3 = find_cost((row + 1) % n, col - 1);

        int best = min({choice1, choice2, choice3});

        vector<int> candidate;

        if(best == choice1)
            candidate.pb((row - 1 + n) % n);
        if(best == choice2)
            candidate.pb(row);
        if(best == choice3)
            candidate.pb((row + 1) % n);

        vector<int> path = vector<int>(col, INT_MAX);
        for(int c : candidate)
        {
            vector<int> c_path = gen_path(c, col - 1);
            if(c_path < path)
                path = c_path;
        }
        path.pb(row);
        return min_path[row][col] = path;
    }
}

void cp()
{
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        clr(min_cost_path, -1);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                min_path[i][j].clear();
        int min_cost = INT_MAX;
        vector<int> last_min_cost;
        for(int i = 0; i < n; i++)
        {
            min_cost = min(min_cost, find_cost(i, m - 1));
        }
        for(int i = 0; i < n; i++)
        {
            int cost = find_cost(i, m - 1);
            if(cost == min_cost)
                last_min_cost.pb(i);
        }
        vector<int> path(m, INT_MAX);
        for(int c : last_min_cost)
        {
            // dbg(c);
            vector<int> c_path = gen_path(c, m - 1);
            if(c_path < path)
                path = c_path;
        }
        for(int i = 0; i < sz(path); i++)
        {
            if(i)
                cout << " ";
            cout << path[i] + 1;
        }
        cout << endl;
        cout << min_cost << endl;
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