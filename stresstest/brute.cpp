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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int &x : A)
        cin >> x;

    partial_sum(all(A), A.begin());

    auto sum = [&](int x, int y)
    {
        return A[y] - (x ? A[x - 1] : 0);
    };

    vector<int> dp(n, inf);
    for(int i = 0; i < n; i++)
        for(int j = max(0, i - m + 1); j <= i; j++)
            if(sum(j, i) % 2)
                dp[i] = min(dp[i], 1 + (j ? dp[j - 1] : 0));

    int ans = dp.back();
    if(ans == inf) ans = -1;
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
