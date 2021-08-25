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
const int MAXN = 2e5 + 5;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lg[MAXN];
void init()
{
    lg[1] = 0;
    for(int i = 2; i < MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

using ftype = ll;
const int K = 25; // Enough for any array
ftype st[MAXN][K + 1];

ftype combine(ftype L, ftype R)
{
	return gcd(L, R);
}

void build(vector<ftype> &arr)
{
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
            st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// Query for idempotent Functions
ftype query(int L, int R)
{
    int j = lg[R - L + 1];
    return combine(st[L][j], st[R - (1 << j) + 1][j]);
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    for(int i = 0; i < n - 1; i++)
        arr[i] = abs(arr[i] - arr[i + 1]);
    arr.pop_back();

    int m = n - 1;
    build(arr);

    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        int lo = i, hi = m - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            ll g = query(i, mid);
            if(g > 1)
                ans = max(ans, mid - i + 1), lo = mid + 1;
            else
                hi = mid - 1;
        }
    }

    cout << ans + 1 << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
