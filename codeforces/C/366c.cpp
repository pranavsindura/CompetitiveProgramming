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
const int inf = 1e8;
const int MAXN = 1e5 + 5;

int dp[105][2 * 105 * 105][2];
const int OFF = 10000;
int n, k;
vector<int> A, B;

int solve(int i, int sum, int once)
{
    if(sum < -100 * n) return -inf;
    if(i == n) return sum == 0 && once ? 0 : -inf;

    int &ret = dp[i][sum + OFF][once];
    if(~ret) return ret;

    int ans = -inf;
    ans = max(ans, solve(i + 1, sum, once));
    ans = max(ans, A[i] + solve(i + 1, sum + A[i] - k * B[i], 1));
    return ret = ans;
}

void cp()
{
    cin >> n >> k;
    A.resize(n), B.resize(n);
    for(int &x : A)
        cin >> x;
    for(int &x : B)
        cin >> x;
    clr(dp, -1);
    int ans = solve(0, 0, 0);
    if(ans < 0) ans = -1;
    cout << ans << endl;
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

