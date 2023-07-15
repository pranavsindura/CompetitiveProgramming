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

void cp()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;

    set<vector<vector<int>>> make;
    for(int i = 0; i < n; i++)
    {
        int o = 0;
        for(int j = 0; j < n; j++)
            if(arr[i][j] == 'O') o++;
        if(o) continue;
        vector<vector<int>> moves;
        for(int j = 0; j < n; j++)
            if(arr[i][j] == '.')
                moves.push_back({i, j});
        sort(all(moves));
        make.insert(moves);
    }
    for(int j = 0; j < n; j++)
    {
        int o = 0;
        for(int i = 0; i < n; i++)
            if(arr[i][j] == 'O') o++;
        if(o) continue;
        vector<vector<int>> moves;
        for(int i = 0; i < n; i++)
            if(arr[i][j] == '.')
                moves.push_back({i, j});
        sort(all(moves));
        make.insert(moves);
    }

    if(make.empty()) cout << "Impossible\n";
    else
    {
        int best_size = INT_MAX;
        for(auto v : make) best_size = min(best_size, sz(v));
        int cnt = 0;
        for(auto v : make) cnt += sz(v) == best_size;
        cout << best_size << " " << cnt << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
