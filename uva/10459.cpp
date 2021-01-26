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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    while(cin >> n)
    {
        vector<vector<int>> adj(n + 1);
        for(int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            adj[i].resize(m);
            for(int &x : adj[i])
                cin >> x;
        }
        vector<bool> vis(n + 1);
        queue<tuple<int, int, int>> q;

        int mx_d = 0, last = 1;
        q.push(make_tuple(1, 1, 0));
        while(!q.empty())
        {
            int u, par, depth;
            tie(u, par, depth) = q.front();
            q.pop();
            if(depth > mx_d)
                last = u, mx_d = depth;
            for(int v : adj[u])
                if(v != par)
                    q.push(make_tuple(v, u, depth + 1));
        }

        vector<int> prev(n + 1);
        mx_d = 0;
        q.push(make_tuple(last, last, 0));
        while(!q.empty())
        {
            int u, par, depth;
            tie(u, par, depth) = q.front();
            q.pop();
            prev[u] = par;
            if(depth > mx_d)
                last = u, mx_d = depth;
            for(int v : adj[u])
                if(v != par)
                    q.push(make_tuple(v, u, depth + 1));
        }

        vector<int> path;
        while(prev[last] != last)
            path.pb(last), last = prev[last];
        path.pb(last);

        int dia = sz(path);
        vector<int> best(1, path[dia / 2]);
        set<int> worst;

        if(sz(path) % 2 == 0)
            best.pb(path[dia / 2 - 1]);
        sort(all(best));

        for(int root : best)
        {
            q.push(make_tuple(root, root, 0));
            while(!q.empty())
            {
                int u, par, depth;
                tie(u, par, depth) = q.front();
                q.pop();
                if(depth == dia / 2)
                    worst.insert(u);
                for(int v : adj[u])
                    if(v != par)
                        q.push(make_tuple(v, u, depth + 1));
            }
        }

        cout << "Best Roots  : ";
        for(int x : best)
        {
            cout << x;
            if(x != best.back())
                cout << " ";
        }
        cout << endl;
        cout << "Worst Roots : ";
        for(int x : worst)
        {
            cout << x;
            if(x != *worst.rbegin())
                cout << " ";
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