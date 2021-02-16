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
const int MAXN = 5e3 + 5;

ll dp[MAXN];
string s;

ll solve(int i)
{
    if(i > ln(s)) return 0;
    if(i == ln(s)) return 1;

    ll &ret = dp[i];
    if(~ret) return ret;

    ret = 0;

    if(i + 1 < ln(s) && s[i] == '1' && s[i + 1] >= '0' && s[i + 1] <= '9')
        ret += solve(i + 2);
    
    if(i + 1 < ln(s) && s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')
        ret += solve(i + 2);
    
    if(s[i] >= '1' && s[i] <= '9')
        ret += solve(i + 1);
    
    return ret;
}

void cp()
{
    while(cin >> s && s[0] != '0')
    {
        clr(dp, -1);
        cout << solve(0) << endl;
    }
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
