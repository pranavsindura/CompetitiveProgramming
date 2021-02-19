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

vector<int> arr;
int dp[MAXN][2];

int solve(int i, int par)
{
    if(arr[i] % 2 == par) return 0;

    int &ret = dp[i][par];
    if(~ret) return ret;

    ret = inf;
    if(i - arr[i] >= 0) ret = min(ret, 1 + solve(i - arr[i], par));
    if(i + arr[i] < sz(arr)) ret = min(ret, 1 + solve(i + arr[i], par));
    return ret;
}

void cp()
{
    int n;
    cin >> n;
    arr.resize(n);
    for(int &x : arr)
        cin >> x;
    clr(dp, -1);
    for(int i = 0; i < n; i++)
    {
        int step = solve(i, (arr[i] % 2) ^ 1);
        if(step == inf) step = -1;
        cout << step << " ";
    }
    cout << endl;
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
