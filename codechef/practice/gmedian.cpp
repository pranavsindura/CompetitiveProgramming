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
const int MAXN = 1e3 + 5;

ll C[MAXN][MAXN], Csum[MAXN][MAXN][2];
void init()
{
    clr(C, 0);
    for(int i = 0; i < MAXN; i++)
        C[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            Csum[i][j][j % 2] = C[i][j];
    for(int i = 0; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            for(int k = 0; k < 2; k++)
                Csum[i][j][k] = (Csum[i][j - 1][k] + Csum[i][j][k]) % mod;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}

int brute(vector<int> arr)
{
    int n = sz(arr);
    int ans = 0;
    for(int mask = 1; mask < 1 << n; mask++)
    {
        vector<int> subseq;
        for(int i = 0; i < n; i++)
            if((mask >> i) & 1)
                subseq.push_back(arr[i]);
        sort(all(subseq));
        if(sz(subseq) % 2 == 0) ans += subseq[sz(subseq) / 2] == subseq[sz(subseq) / 2 - 1];
        else ans++;
    }
    return ans;
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    vector<int> freq(2 * n + 1), small(2 * n + 1), large(2 * n + 1);
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    for(int i = 1; i <= 2 * n; i++)
        for(int j = 0; j < n; j++)
            if(arr[j] < i) small[i]++;
            else if(arr[j] > i) large[i]++;

    ll ans = 0;
    for(int med = 1; med <= 2 * n; med++)
        for(int cnt = 2; cnt <= freq[med]; cnt++)
            for(int left = 0; left <= n; left++)
            {
                int a = left - (cnt - 2);
                int b = left + (cnt - 2);
                int p = abs(a) % 2;
                a = max(a, 0);
                b = min(b, n);
                ll me = C[freq[med]][cnt];
                me = (me * C[small[med]][left]) % mod;
                ll range = Csum[large[med]][b][p] - (a ? Csum[large[med]][a - 1][p] : 0);
                range = (range + mod) % mod;
                me = (me * range) % mod;
                ans = (ans + me) % mod;
            }

    ans = (ans + fpow(2, n - 1)) % mod;

    cout << ans << endl;
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
