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

vector<int> prime = {2, 3, 5, 7, 11, 13};

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m)), ans(n, vector<int>(m, 720720));
    for(auto &v : arr)
        for(int &x : v)
            cin >> x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((i + j) % 2)
                ans[i][j] += arr[i][j] * arr[i][j] * arr[i][j] * arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << " \n"[j == m - 1];
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
