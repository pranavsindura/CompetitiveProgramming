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

int dp[2][32][1 << 18];

bool solve(int p, int sum, int mask)
{
    if(sum > 31) return p;

    int &ret = dp[p][sum][mask];
    if(~ret) return ret;

    int win = p ^ 1;
    for(int i = 1; i <= 6; i++)
    {
        int OFF = 3 * (i - 1);
        int freq = (mask >> OFF) & 7;
        if(freq == 0) continue;
        int nmask = mask & ~(7 << OFF);
        nmask |= ((freq - 1) << OFF);
        int who = solve(p ^ 1, sum + i, nmask);
        if(who == p) win = p;
    }
    return ret = win;
}

void cp()
{
    string s;
    while(cin >> s)
    {
        int p = ln(s) % 2;
        int sum = 0, mask = 0;
        for(int i = 1; i <= 6; i++)
        {
            int freq = count(all(s), char(i + 48));
            sum += freq * i;
            mask |= (4 - freq) << (3 * (i - 1));
        }
        clr(dp, -1);
        int who = solve(p, sum, mask);
        cout << s << (who ? " B" : " A") << endl;
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
