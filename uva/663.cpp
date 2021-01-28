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
const int MAXN = 1e5 + 5;

bool is_inside(array<int, 4> &A, array<int, 2> &B)
{
    return A[0] < B[0] && B[0] < A[1] && A[2] < B[1] && B[1] < A[3];
}

vector<int> mt;
vector<bool> vis;

bool kuhn(int u, vector<vector<int>> &adj)
{
    if(vis[u]) return false;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(mt[v] == -1 || kuhn(mt[v], adj)) // can find an augmenting path?
        {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int max_match(vector<vector<int>> &adj)
{
    int n = sz(adj);
    int match = 0;
    mt.assign(n, -1);
    for(int u = 0; u < n; u++)
    {
        vis.assign(n, false);
        if(kuhn(u, adj)) match++;
    }

    return match;
}

void cp()
{
    int n, test = 0;
    while(cin >> n && n)
    {
        vector<array<int, 4>> slide(n);
        vector<array<int, 2>> number(n);
        for(auto &v : slide)
            cin >> v[0] >> v[1] >> v[2] >> v[3];
        for(auto &v : number)
            cin >> v[0] >> v[1];

        bool any = false;
        vector<int> match(n, -1);

        for(int i = 0; i < n; i++)
        {
            vector<int> can;
            // assign number j to slide i, then check if any matching can occur
            for(int j = 0; j < n; j++)
            {
                if(!is_inside(slide[i], number[j])) continue;
                vector<vector<int>> adj(n);
                adj[i].push_back(j);
                for(int a = 0; a < n; a++) if(a != i)
                    {
                        for(int b = 0; b < n; b++) if(b != j)
                            {
                                if(is_inside(slide[a], number[b]))
                                    adj[a].push_back(b);
                            }
                    }

                int m = max_match(adj);
                if(m == n)
                    can.push_back(j);
            }

            if(sz(can) == 1)
            {
                any = true;
                match[i] = can[0];
            }
        }

        cout << "Heap " << ++test << endl;
        if(any)
        {
            string ans;
            for(int i = 0; i < n; i++)
                if(~match[i])
                    ans += "(" + string(1, 65 + i) + "," + to_string(match[i] + 1) + ") ";
            ans.pop_back();
            cout << ans << endl;
        }
        else
            cout << "none\n";
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

