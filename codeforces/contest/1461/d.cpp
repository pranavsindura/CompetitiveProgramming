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

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

map<ll, bool> val;
vector<ll> pref, arr;
void solve(int l, int r)
{
    if(l > r) return;
    val[pref[r] - (l ? pref[l - 1] : 0)] = 1;
    if(l == r)	return;

    ll x = arr[l], y = arr[r];
    ll m = (x + y) / 2;
    int idx = upper_bound(all(arr), m) - begin(arr);
    idx--;
    if(idx != r)
        solve(l, idx);
    solve(idx + 1, r);
}

void cp()
{
    int n, q;
    cin >> n >> q;

    arr.resize(n);
    for(ll &x : arr)
        cin >> x;

    sort(all(arr));
    val.clear();
    pref.assign(n, 0);
    pref[0] = arr[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + arr[i];

    solve(0, n - 1);

    while(q--)
    {
        int x;
        cin >> x;
        if(val.count(x))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
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

