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

void cp()
{
    int k;
    cin >> k;
    if(k == 1)
    {
        cout << "YES\n2 1\n1 2\n";
        return;
    }
    else if(k % 2 == 0)
    {
        cout << "NO\n";
        return;
    }

    int n = k + 2;
    vector<vector<int>> edges;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            if(i == 1 and j == 2) continue;
            if(i == 1 and j == 3) continue;
            if(i % 2 == 0 and j == i + 1 and i > 2) continue;
            edges.pb({i, j});
            edges.pb({n + i, n + j});
        }
    edges.pb({1, n + 1});
    cout << "YES\n";
    cout << n + n << " " << sz(edges) << endl;
    for(auto v : edges)
        cout << v[0] << " " << v[1] << endl;
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

