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

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int need = -1;
    vector<int> colour(n);

    vector<bool> vis(n);
    function<void(int, int)> dfs = [&](int u, int c)
    {
        vis[u] = 1;
        colour[u] = c;
        int v = (u + 1) % n;
        if(arr[u] == arr[v] && !vis[v])
            dfs(v, c);
        v = (u - 1 + n) % n;
        if(arr[u] == arr[v] && !vis[v])
            dfs(v, c);
    };

    int groups = 0;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i, 0), groups++;

    vis.assign(n, false);

    if(groups == 1)
    {
        need = 1;
        dfs(0, 1);
    }
    else if(groups % 2 == 0)
    {
        need = 2;
        int c = 1;
        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs(i, c), c = c % 2 + 1;
    }
    else if(groups == n)
    {
        need = 3;
        int c = 1;
        dfs(0, 3);
        for(int i = 1; i < n; i++)
            if(!vis[i])
                dfs(i, c), c = c % 2 + 1;
    }
    else
    {
        need = 2;
        int idx = -1, c = 2, idx2 = -1;
        for(int i = 0; i < n && idx == -1; i++)
            if(arr[i] == arr[(i + 1) % n])
                idx = i;
        dfs(idx, 2);
        for(int i = 0; i < n; i++)
            if(vis[(idx + i) % n])
                idx2 = (idx + i) % n;
            else break;
        colour[idx2] = 1;
        for(int i = 0; i < n; i++)
            if(!vis[(idx + i) % n])
                dfs((idx + i) % n, c), c = c % 2 + 1;
    }

    cout << need << endl;
    for(int i = 0; i < n; i++)
        cout << colour[i] << " ";
    cout << endl;
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

