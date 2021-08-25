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
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int &x : A)
        cin >> x;
    for(int &x : B)
        cin >> x;
    sort(all(A));
    sort(all(B));

    ll ans = 0;
    // Before A[0]
    if(B[0] < A[0])
        ans += (A[0] - B[0]) * 2LL;
    for(int i = 0; i < n - 1; i++)
    {
        // Between [A[i], A[i + 1])
        int l = lower_bound(all(B), A[i]) - B.begin();
        int r = lower_bound(all(B), A[i + 1]) - B.begin() - 1;
        int p = l - 1;
        for(int j = l; j <= r; j++)
            if(B[j] - A[i] <= A[i + 1] - B[j])
                p = j;
        ll d1 = 0;
        if(p >= l) d1 += (B[p] - A[i]) * 2LL;
        if(p + 1 <= r) d1 += (A[i + 1] - B[p + 1]) * 2LL;
        ll  d2 = A[i + 1] - A[i];
        ans += min(d1, d2);
    }
    // After A[n - 1]
    if(B[m - 1] >= A[n - 1])
        ans += (B[m - 1] - A[n - 1]) * 2LL;

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
