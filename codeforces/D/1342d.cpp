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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<int> atmost(k + 1);
    for(int i = 1; i <= k; i++)
        cin >> atmost[i];

    sort(allr(arr));
    int best = 1;
    for(int i = 0; i < n; i++)
        best = max(best, (atmost[arr[i]] + i) / atmost[arr[i]]);

    vector<vector<int>> ans(best);
    for(int i = 0; i < n; i++)
        ans[i % best].push_back(arr[i]);

    cout << sz(ans) << endl;
    for(auto &v : ans)
    {
        cout << sz(v) << " ";
        for(int x : v)
            cout << x << " ";
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
