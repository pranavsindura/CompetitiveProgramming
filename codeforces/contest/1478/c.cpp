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
    vector<ll> arr(2 * n);
    map<ll, int> freq;
    bool ok = true;
    for(ll &x : arr)
        cin >> x, freq[x]++, ok &= x % 2 == 0;
    for(auto x : freq)
        ok &= x.ss % 2 == 0;

    if(n == 1)
    {
        cout << (ok ? "YES\n" : "NO\n");
        return;
    }

    sort(all(arr));

    ll total = 0;
    vector<ll> C;
    for(int i = 0; i < 2 * n; i += 2)
        C.push_back(arr[i]);

    ll M = 2 * n;
    ll pref = 0;
    vector<ll> actual(n);
    for(int i = n - 1; i >= 0; i--)
    {
        ll me = C[i] - pref * 2;
        ok &= me >= 0 && me % M == 0;
        actual[i] = me / M;
        M -= 2;
        pref += actual[i];
    }

    set<ll> st(all(actual));
    st.erase(0);
    ok &= sz(st) == n;

    cout << (ok ? "YES\n" : "NO\n");
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

