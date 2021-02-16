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
    int n, q, k;
    cin >> n >> q >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    vector<ll> up(n), down(n);
    for(int i = 0; i < n; i++)
    {
        if(i - 1 >= 0) down[i] += arr[i] - arr[i - 1] - 1;
        if(i + 1 < n) up[i] += arr[i + 1] - arr[i] - 1;
    }
    partial_sum(all(up), up.begin());
    partial_sum(all(down), down.begin());
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l == r)
            cout << k - 1 << endl;
        else
        {
            ll ans = arr[l] - 1 + k - arr[r];
            ans += up[r - 1] - (l ? up[l - 1] : 0);
            ans += down[r] - down[l];
            cout << ans << endl;
        }
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
