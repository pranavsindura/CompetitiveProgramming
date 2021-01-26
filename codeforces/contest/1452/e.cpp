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
const int MAXN = 2e3 + 5;


void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(m, vector<int>(2));
    for(int i = 0; i < m; i++)
        cin >> arr[i][0] >> arr[i][1], arr[i][0]--, arr[i][1]--;

    sort(all(arr), [&](vector<int> a, vector<int> b)
    {
        return a[0] + a[1] < b[0] + b[1];
    });

    auto solve = [&](int a, int b)
    {
        vector<int> diff(n + 1);
        for(int i = a; i < b; i++)
            diff[arr[i][0]]++, diff[arr[i][1] + 1]--;

        for(int i = 1; i <= n; i++)
            diff[i] += diff[i - 1];

        for(int i = 1; i <= n; i++)
            diff[i] += diff[i - 1];

        int mx = diff[k - 1];
        for(int i = k; i <= n; i++)
            mx = max(mx, diff[i] - diff[i - k]);
        return mx;
    };

    int ans = 0;
    for(int i = 0; i <= m; i++)
    {
        int a = solve(0, i);
        int b = solve(i, m);
        ans = max(ans, a + b);
    }

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