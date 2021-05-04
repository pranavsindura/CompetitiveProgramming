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

int dp[1 << 20];

void cp()
{
    string s, e;
    cin >> s >> e;

    int _S = 0, E = 0;
    for(int i = 0; i < ln(s); i++)
        _S = _S * 2 + (s[i] - '0');
    for(int i = 0; i < ln(e); i++)
        E = E * 2 + (e[i] - '0');

    fill(dp, dp + (1 << 20), inf);
    dp[_S] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({dp[_S], _S});
    while(!pq.empty())
    {
        pi u = pq.top();
        pq.pop();
        if(u.ff > dp[u.ss]) continue;
        int S = u.ss;

        // Double
        if((S << 1) < (1 << 20) && dp[S << 1] > 1 + u.ff)
        {
            dp[S << 1] = 1 + u.ff;
            pq.push({dp[S << 1], S << 1});
        }

        // NOT
        s = bitset<20>(S).to_string();
        reverse(all(s));
        while(ln(s) > 1 && s.back() == '0') s.pop_back();
        reverse(all(s));
        for(char &x : s)
            if(x == '0') x = '1';
            else x = '0';
        reverse(all(s));
        while(ln(s) > 1 && s.back() == '0') s.pop_back();
        reverse(all(s));

        S = 0;
        for(int i = 0; i < ln(s); i++)
            S = S * 2 + (s[i] - '0');

        if(dp[S] > 1 + u.ff)
        {
            dp[S] = 1 + u.ff;
            pq.push({dp[S], S});
        }
    }
    int ans = dp[E];
    if(ans == inf)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
