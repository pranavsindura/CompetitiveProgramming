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
const int MAXN = 40;

const int N = 38, S = 36, T = 37;
int req;
int flow[MAXN][MAXN], cap[MAXN][MAXN], vis[MAXN], path[MAXN];

void modify(string &s)
{
    string a, b;
    stringstream ss(s);
    ss >> a >> b;
    b.pop_back();
    int v = (a[0] - 'A') + 10;
    int F = a[1] - '0';
    flow[v][T]  = cap[v][T] = F;
    req += F;
    for(char x : b)
    {
        int u = x - '0';
        flow[u][v] = cap[u][v] = 1;
        flow[S][u] = cap[S][u] = 1;
    }
}

int find_path()
{
    fill(vis, vis + N, 0);
    queue<pi> q;
    q.push({S, inf});
    path[S] = -1;
    while(!q.empty())
    {
        pi node = q.front();
        q.pop();
        int u = node.ff, mx = node.ss;
        vis[u] = 1;
        if(u == T) return mx;
        for(int v = 0; v < N; v++)
            if(!vis[v] && flow[u][v] > 0)
                vis[v] = 1, path[v] = u, q.push({v, min(mx, flow[u][v])});
    }
    return 0;
}

int max_flow()
{
    int ans = 0, d, u;
    while(true)
    {
        d = find_path();
        if(d == 0) break;
        ans += d;
        u = T;
        while(~path[u])
            flow[path[u]][u] -= d, flow[u][path[u]] += d, u = path[u];
    }
    return ans;
}
void cp()
{
    string s;
    while(getline(cin, s) && !s.empty())
    {
        clr(flow, 0), clr(cap, 0);
        req = 0;
        modify(s);
        while(getline(cin, s) && !s.empty()) modify(s);

        int m = max_flow();
        find_path();
        string ans(10, '_');
        for(int i = 0; i < 10; i++)
        {
            for(int j = 10; j < 36; j++)
            {
                if(flow[j][i] > 0)
                {
                    ans[i] = char(j + 65 - 10);
                }
            }
        }
        if(m == req)
            cout << ans << endl;
        else
            cout << "!\n";
    }
}

// vector<int> mt;
// vector<char> tag;
// vector<bool> vis;
// int N, M;

// void modify(vector<vector<int>> &adj, string &s)
// {
//     string a, b;
//     stringstream ss(s);
//     ss >> a >> b;
//     int f = a[1] - '0';
//     while(f--)
//     {
//         tag.pb(a[0]);
//         for(int i = 0, u = b[i] - '0'; b[i] != ';'; i++, u = b[i] - '0')
//             adj[u].pb(M);
//         M++;
//     }
// }

// bool kuhn(int u, vector<vector<int>> &adj)
// {
//     if(vis[u]) return false;
//     vis[u] = 1;
//     for(int v : adj[u])
//     {
//         if(mt[v] == -1 || kuhn(mt[v], adj))
//         {
//             mt[v] = u;
//             return true;
//         }
//     }
//     return false;
// }

// void cp()
// {
//     string s;
//     while(getline(cin, s) && !s.empty())
//     {
//         N = 10, M = 0;
//         tag.clear();
//         vector<vector<int>> adj(N);
//         modify(adj, s);
//         while(getline(cin, s) && !s.empty()) modify(adj, s);

//         mt.assign(M, -1);

//         for(int i = 0; i < N; i++)
//         {
//             vis.assign(N, false);
//             kuhn(i, adj);
//         }
//         int cnt = 0;
//         string ans(N, '_');
//         for(int i = 0; i < M; i++)
//             if(mt[i] != -1)
//                 ans[mt[i]] = tag[i], cnt++;
//         if(cnt == M)
//             cout << ans << endl;
//         else
//             cout << "!" << endl;
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

