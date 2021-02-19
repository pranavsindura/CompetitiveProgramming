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

void cp()
{
    int n;
    cin >> n;
    vector<array<int, 2>> arr(n);
    for(auto &v : arr)
        cin >> v[0] >> v[1];
    sort(all(arr));
    int ans = inf;
    do
    {
        int me = n;
        for(int i = 1; i < n; i++)
            me += max(arr[i - 1][1], arr[i][0]);
        me += max(arr[n - 1][1], arr[0][0]);
        ans = min(ans, me);
    }
    while(next_permutation(all(arr)));
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
