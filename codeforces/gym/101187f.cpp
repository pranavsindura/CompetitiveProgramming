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
const int MAXN = 5e3 + 5;

int arr[MAXN][MAXN], res[MAXN][MAXN];
int cperm[MAXN], rperm[MAXN];

void cp()
{
    int n, m, q;
    string s;
    cin >> n >> m >> q >> s;

    int k;
    cin >> k;
    vector<int> A(k);
    for(int &x : A) cin >> x;
    cin >> k;
    vector<int> B(k);
    for(int &x : B) cin >> x;
    cin >> k;
    vector<int> C(k);
    for(int &x : C) cin >> x;
    cin >> k;
    vector<int> D(k);
    for(int &x : D) cin >> x;

    while(sz(A) < q)
    {
        int x = (10007 * A[sz(A) - 2] + 10009 * A[sz(A) - 1] + 87277) % n;
        A.push_back(x);
    }

    while(sz(B) < q)
    {
        int x = (10007 * B[sz(B) - 2] + 10009 * B[sz(B) - 1] + 87277) % m;
        B.push_back(x);
    }

    while(sz(C) < q)
    {
        int x = (10007 * C[sz(C) - 2] + 10009 * C[sz(C) - 1] + 87277) % n;
        C.push_back(x);
    }

    while(sz(D) < q)
    {
        int x = (10007 * D[sz(D) - 2] + 10009 * D[sz(D) - 1] + 87277) % m;
        D.push_back(x);
    }

    for(int i = 0; i < n; i++)
    {
        rperm[i] = i;
        for(int j = 0; j < m; j++)
        {
            cperm[j] = j;
            arr[i][j] = i * m + j;
        }
    }

    for(int i = 0; i < q; i++)
    {
        if(s[i] == 'c')
            swap(cperm[B[i]], cperm[D[i]]);
        else if(s[i] == 'r')
            swap(rperm[A[i]], rperm[C[i]]);
        else
            swap(arr[rperm[A[i]]][cperm[B[i]]], arr[rperm[C[i]]][cperm[D[i]]]);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res[i][j] = arr[rperm[i]][cperm[j]];

    ll ans = 0;
    ll p17 = 1, p19 = 1;
    for(int i = 0; i < n; i++)
    {
        p19 = 1;
        for(int j = 0; j < m; j++)
        {
            ans = (ans + ((res[i][j] * p17) % mod * p19) % mod) % mod;
            p19 = (p19 * 19) % mod;
        }
        p17 = (p17 * 17) % mod;
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
