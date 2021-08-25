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

ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1) res = (res % m * x % m) % m;
        x = (x % m * x % m) % m;
        y >>= 1;
    }
    return res;
}

bool is_prime_fermat(ll p, int iters = 5)
{
    if(p < 4) return p == 2 || p == 3;
    if(p % 2 == 0) return false;
    for(int i = 0; i < iters; i++)
    {
        ll a = rand(2LL, p - 2);
        if(fpow(a, p - 1, p) != 1) return false;
    }
    return true;
}

int dp[20][20];
bool check(string &s, int i, int j)
{
    if(i == ln(s) && j == ln(s)) return true;
    if(j >= ln(s)) return false;

    int &ret = dp[i][j];
    if(~ret) return ret;

    bool ans = false;
    ans |= check(s, i, j + 1);
    ll x = stoll(s.substr(i, j - i + 1));
    if(j - i + 1 != ln(s) && (j + 1 == ln(s) || s[j + 1] != '0'))
        ans |= is_prime_fermat(x) && check(s, j + 1, j + 1);
    return ret = ans;
}

void cp()
{
    ll n;
    cin >> n;

    string s = to_string(n);
	clr(dp, -1);
    while(!is_prime_fermat(n) || !check(s, 0, 0)){
    	n++, s = to_string(n);
    	clr(dp, -1);
    }

    cout << n << endl;
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
/*

preorder NLR
inorder LNR
postorder LRN

in_order(N):
	in_order(N->left)
	print(N)
	in_order(N->right)

*/  