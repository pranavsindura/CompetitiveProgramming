#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

/*
Node needs a trees and has b neighbours
if a > b + 1 then not possible
node needs to activated when it has
a - 1 inactivated neighbours remaining

So we can perform a BFS like traversal where we consume a node
update its neighbours and add them to the queue of they satisfy the activation criteria
At the end all nodes must be visited
*/

int arr[205][205], nb[205][205];
bool vis[205][205];
void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    bool ok = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i + 1 < n) nb[i][j]++;
            if(i - 1 >= 0) nb[i][j]++;
            if(j + 1 < m) nb[i][j]++;
            if(j - 1 >= 0) nb[i][j]++;
            ok &= (arr[i][j] <= nb[i][j] + 1);
        }

    vector<pi> ans;
    queue<pi> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(nb[i][j] == arr[i][j] - 1)
                q.push({i, j});

    while(!q.empty() && ok)
    {
        pi u = q.front();
        ans.pb(u);
        q.pop();
        int i = u.ff, j = u.ss;
        vis[i][j] = 1;

        if(i + 1 < n) nb[i + 1][j]--;
        if(i - 1 >= 0) nb[i - 1][j]--;
        if(j + 1 < m) nb[i][j + 1]--;
        if(j - 1 >= 0) nb[i][j - 1]--;

        if(i + 1 < n && !vis[i + 1][j] && nb[i + 1][j] == arr[i + 1][j] - 1) vis[i + 1][j] = 1, q.push({i + 1, j});
        if(i - 1 >= 0 && !vis[i - 1][j] && nb[i - 1][j] == arr[i - 1][j] - 1) vis[i - 1][j] = 1, q.push({i - 1, j});
        if(j + 1 < m && !vis[i][j + 1] && nb[i][j + 1] == arr[i][j + 1] - 1) vis[i][j + 1] = 1, q.push({i, j + 1});
        if(j - 1 >= 0 && !vis[i][j - 1] && nb[i][j - 1] == arr[i][j - 1] - 1) vis[i][j - 1] = 1, q.push({i, j - 1});
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ok &= vis[i][j];
    if(ok)
    {
        for(auto p : ans)
            cout << p.ff + 1 << " " << p.ss + 1 << endl;
    }
    else
        cout << "No solution\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}