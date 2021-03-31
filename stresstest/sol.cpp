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
    int N, MAXH, M;
    cin >> N >> MAXH >> M;
    vector<int> L(M), R(M), A(M), B(M);
    for(int &x : L) cin >> x, x--;
    for(int &x : R) cin >> x, x--;
    for(int &x : A) cin >> x;
    for(int &x : B) cin >> x;

    vector<int> MN(N, 1);
    vector<int> MX(N, MAXH);

    for(int i = 0; i < M; i++)
        for(int j = L[i]; j <= R[i]; j++)
            MN[j] = max(MN[j], A[i]), MX[j] = min(MX[j], B[i]);

    ll ans = 1;
    for(int i = 0; i < N; i++)
        ans = (ans * max(0, MX[i] - MN[i] + 1)) % mod;

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
