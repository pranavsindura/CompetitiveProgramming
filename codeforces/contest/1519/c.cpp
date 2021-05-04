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

void cp()
{
    int n;
    cin >> n;
    vector<int> U(n);
    for(int &x : U)
        cin >> x, x--;
    vector<ll> S(n);
    for(ll &x : S)
        cin >> x;
    vector<vector<ll>> have(n);
    for(int i = 0; i < n; i++)
        have[U[i]].push_back(S[i]);
    for(int i = 0; i < n; i++)
        sort(allr(have[i]));

    vector<ll> ans(n + 5);
    for(int i = 0; i < n; i++)
    {
        int k = sz(have[i]);
        if(k == 0) continue;
        for(int j = k - 2; j >= 0; j--)
            have[i][j] += have[i][j + 1];
        for(int g = 1; g <= k; g++)
        {
            int rem = k % g;
            if(rem > 0)
            {
                ans[g] -= have[i][k - rem];
                ans[g + 1] += have[i][k - rem];
            }
        }
        ans[k + 1] -= have[i].front();
    }

    ll total = accumulate(all(S), 0LL);
    for(int i = 1; i < n + 5; i++)
        ans[i] += ans[i - 1];
    for(int i = 0; i < n + 5; i++)
        ans[i] += total;
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
