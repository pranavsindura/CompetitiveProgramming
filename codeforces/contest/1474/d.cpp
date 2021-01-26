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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    bool ok = false;
    if(n == 2) ok = arr[0] == arr[1];

    vector<ll> need_pref(n), need_suff(n), pref(n), suff(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(i) need_pref[i] = need_pref[i - 1];
        if(sum > arr[i]) need_pref[i] = 1;
        sum = arr[i] - sum;
        pref[i] = sum;
    }
    sum = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(i + 1 < n) need_suff[i] = need_suff[i + 1];
        if(sum > arr[i]) need_suff[i] = 1;
        sum = arr[i] - sum;
        suff[i] = sum;
    }

    ok |= pref[n - 1] == 0 && !need_pref[n - 1];
    ok |= suff[0] == 0 && !need_suff[0];

    for(int i = 0; i < n - 1; i++)
    {
        bool can = true;
        ll A = i ? pref[i - 1] : 0;
        ll B = i + 2 < n ? suff[i + 2] : 0;
        if(A > arr[i + 1]) can = false;
        A = arr[i + 1] - A;
        if(B > arr[i]) can = false;
        B = arr[i] - B;
        can &= !(i ? need_pref[i - 1] : 0) && !(i + 2 < n ? need_suff[i + 2] : 0) && A == B;
        ok |= can;
    }
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

