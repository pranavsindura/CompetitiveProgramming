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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define get(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

int n;
int solve(int i, int j)
{
    if(i == 1 && j == n) return 1;

    int ans = 0;
    if(i > 1) ans += solve(i - 1, j);
    if(j < n) ans += solve(i, j + 1);

    return ans;
}

void cp()
{
    int m;
    cin >> n >> m;
    cout << solve(m, m) << endl;
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

