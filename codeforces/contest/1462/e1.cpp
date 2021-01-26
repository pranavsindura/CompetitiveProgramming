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

void cp()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for(int i = 0, x; i < n; i++)
        cin >> x, cnt[x]++;
    ll ans = 0;
    // AAA
    for(int i = 1; i <= n; i++)
        ans += cnt[i] * 1LL * (cnt[i] - 1) * 1LL * (cnt[i] - 2) / 6;
    // ABB
    for(int i = 1; i + 1 <= n; i++)
        ans += cnt[i] * 1LL * cnt[i + 1] * 1LL * (cnt[i + 1] - 1) / 2;
    // AAB
    for(int i = 1; i + 1 <= n; i++)
        ans += cnt[i + 1] * 1LL * cnt[i] * 1LL * (cnt[i] - 1) / 2;
    // ACC
    for(int i = 1; i + 2 <= n; i++)
        ans += cnt[i] * 1LL * cnt[i + 2] * 1LL * (cnt[i + 2] - 1) / 2;
    // AAC
    for(int i = 1; i + 2 <= n; i++)
        ans += cnt[i + 2] * 1LL * cnt[i] * 1LL * (cnt[i] - 1) / 2;
    // ABC
    for(int i = 1; i + 2 <= n; i++)
        ans += cnt[i] * 1LL * cnt[i + 1] * 1LL * cnt[i + 2];
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

