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
const int MAXN = 7e3 + 5;

ll mask[MAXN];
int val[MAXN], cnt[MAXN];
int out[MAXN][MAXN];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> mask[i];
    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if((mask[i] & (mask[i] ^ mask[j])) > 0)
                cnt[i] += out[i][j] ^ 1, out[i][j] = 1;

    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b)
    {
        return cnt[a] < cnt[b];
    });

    int rem = n - 1;
    while(!order.empty() && rem > 0)
    {
        int x = order.back();
        if(cnt[x] != rem) break;
        order.pop_back();
        rem--;
        for(int i = 0; i < n; i++)
            cnt[i] -= out[i][x], out[i][x] = 0;
        sort(all(order), [&](int a, int b)
        {
            return cnt[a] < cnt[b];
        });
    }

    ll ans = 0;
    for(int x : order)
        ans += val[x];
    if(sz(order) == 1) ans = 0;
    cout << ans << endl;
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
