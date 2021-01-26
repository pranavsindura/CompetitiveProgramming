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
const int MAXN = 1e3 + 5;

/*
    Version Tree?
    join edges between version requirements

    update state
    process current version
    go to children
    undo state
*/

vector<vector<int>> adj, queries, arr;
vector<int> ans;
int cnt;

void dfs(int u)
{
    int idx = queries[u][0], t = queries[u][1], x = queries[u][2], y = queries[u][3], k = queries[u][4];
    bool didset = false, didunset = false;

    if(t == 1 && !arr[x][y]) // set
        arr[x][y] = 1, cnt++, didset = true;
    else if(t == 2 && arr[x][y]) // unset
        arr[x][y] = 0, cnt--, didunset = true;
    else if(t == 3)
        for(int i = 0; i < sz(arr[0]); i++)
            cnt -= arr[x][i], arr[x][i] ^= 1, cnt += arr[x][i];

    ans[idx] = cnt;

    for(int v : adj[u]) dfs(v);

    if(t == 1 && didset)
        arr[x][y] = 0, cnt--;
    else if(t == 2 && didunset)
        arr[x][y] = 1, cnt++;
    else if(t == 3)
        for(int i = 0; i < sz(arr[0]); i++)
            cnt -= arr[x][i], arr[x][i] ^= 1, cnt += arr[x][i];
}

void cp()
{
    int n, m, q;
    cin >> n >> m >> q;
    queries.resize(q + 1);
    adj.resize(q + 1);
    for(int i = 1; i <= q; i++)
    {
        int t = 0, x = 0, y = 0, k = 0;
        cin >> t;
        if(t <= 3) cin >> x, x--;
        if(t <= 2) cin >> y, y--;
        if(t == 4) cin >> k;
        queries[i] = {i, t, x, y, k};
        if(t == 4) adj[k].pb(i);
        else adj[i - 1].pb(i);
    }

    arr.assign(n, vector<int>(m));
    ans.resize(q + 1);
    cnt = 0;
    queries[0] = {0, 4, 0, 0, 0};

    dfs(0);

    for(int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}

// void cp()
// {
//     int n, m, Q;
//     cin >> n >> m >> Q;
//     vector<vector<int>> idx(Q + 1, vector<int>(n));
//     vector<vector<int>> rows(Q + 5);
//     rows[0] = vector<int>(m, 0);
//     map<vector<int>, int> pos;
//     pos[rows[0]] = 0;
//     vector<int> cur, ansat(Q + 1);

//     auto get_pos = [&](vector<int> a)
//     {
//         if(pos.count(a)) return pos[a];
//         else return pos[a] = sz(pos) - 1;
//     };

//     int ans = 0;

//     for(int q = 1; q <= Q; q++)
//     {
//         int t, x, y, k;
//         cin >> t;
//         for(int i = 0; i < n; i++)
//             idx[q][i] = idx[q - 1][i];
//         if(t == 1)
//         {
//             cin >> x >> y, x--, y--;
//             cur = rows[idx[q - 1][x]];
//             ans += !cur[y];
//             cur[y] = 1;
//             idx[q][x] = get_pos(cur);
//             rows[idx[q][x]] = cur;
//         }
//         else if(t == 2)
//         {
//             cin >> x >> y, x--, y--;
//             cur = rows[idx[q - 1][x]];
//             ans -= cur[y];
//             cur[y] = 0;
//             idx[q][x] = get_pos(cur);
//             rows[idx[q][x]] = cur;
//         }
//         else if(t == 3)
//         {
//             cin >> x, x--;
//             cur = rows[idx[q - 1][x]];
//             for(int i = 0; i < m; i++)
//                 ans -= cur[i], ans += !cur[i], cur[i] ^= 1;
//             idx[q][x] = get_pos(cur);
//             rows[idx[q][x]] = cur;
//         }
//         else
//         {
//             cin >> k;
//             ans = ansat[k];
//             for(int i = 0; i < n; i++)
//                 idx[q][i] = idx[k][i];
//         }
//         ansat[q] = ans;
//         cout << ans << endl;
//     }
// }

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

