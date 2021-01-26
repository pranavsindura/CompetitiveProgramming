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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A(3);
    A[0].resize(n);
    A[1].resize(m);
    A[2].resize(k);
    vector<ll> sum(3);

    for(int i = 0; i < 3; i++)
        for(int &x : A[i])
            cin >> x, sum[i] += x;

    for(int i = 0; i < 3; i++)
        sort(all(A[i]));

    ll ans = LLONG_MIN;

    vector<int> order = {0, 1, 2};
    do
    {
        int p = order[0], q = order[1], r = order[2];
        // A B C
        ll P = A[p][0] - (sum[r] - A[r][0]); // accumulate
        ll Q = A[r][0] - (sum[p] - A[p][0]);
        ll R = max({P - Q, Q - P, -P - Q}) + sum[q];
        ans = max(ans, R);
    }
    while(next_permutation(all(order)));

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

