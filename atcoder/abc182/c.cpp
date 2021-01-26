#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

string s;
int solve(int i, int skipped, int rem)
{
    if(i == ln(s))
        return (!rem && skipped < ln(s) ? 0 : 100);

    int ans = 100;
    ans = min(ans, 1 + solve(i + 1, skipped + 1, rem));
    ans = min(ans, solve(i + 1, skipped, (rem * 10 + (s[i] - '0')) % 3));
    return ans;
}

void cp()
{
    ll n;
    cin >> n;
    s = to_string(n);
    reverse(all(s));
    int ans = solve(0, 0, 0);
    if(ans < 100)
        cout << ans << endl;
    else
        cout << -1 << endl;
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