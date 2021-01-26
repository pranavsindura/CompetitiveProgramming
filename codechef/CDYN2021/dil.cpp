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

string s, make;
int dp[1005][3];
int solve(int i, int j)
{
    if(i == ln(s)) return 0;

    int &ret = dp[i][j];
    if(~ret) return ret;

    int ans = 1 + solve(i + 1, j);
    if(s[i] == make[j])
        ans = min(ans, solve(i + 1, (j + 1) % 3));
    return ret = ans;
}

void cp()
{
    cin >> s;
    int best = ln(s) + 1;
    string best_make = "zzz";
    for(char a = 'a'; a <= 'z'; a++)
        for(char b = 'a'; b <= 'z'; b++)
            for(char c = 'a'; c <= 'z'; c++)
            {
                make.clear();
                make += a, make += b, make += c;
                clr(dp, -1);
                int ans = solve(0, 0);
                if(ans < best) best = ans, best_make = make;
            }

    string ans;
    int j = 0;
    for(int i = 0; i < ln(s); i++)
        if(s[i] == best_make[j])
            ans += s[i], j = (j + 1) % 3;
    cout << best << " " << ans << endl;
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

