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
    vector<int> A(n);
    for(int &x : A)
        cin >> x;
    vector<int> pref_inc(n), pref_dec(n);
    int cnt_inc = 1, cnt_dec = 1;
    pref_inc[0] = pref_dec[0] = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i - 1] < A[i]) cnt_inc++, cnt_dec = 1;
        else cnt_inc = 1, cnt_dec++;
        pref_inc[i] = cnt_inc;
        pref_dec[i] = cnt_dec;
    }
    vector<int> suff_inc(n), suff_dec(n);
    cnt_inc = 1, cnt_dec = 1;
    suff_inc[n - 1] = suff_dec[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
        if(A[i] < A[i + 1]) cnt_dec++, cnt_inc = 1;
        else cnt_dec = 1, cnt_inc++;
        suff_inc[i] = cnt_inc;
        suff_dec[i] = cnt_dec;
    }

    vector<int> pref(n), suff(n);
    pref[0] = max(pref_inc[0], pref_dec[0]);
    for(int i = 1; i < n; i++)
        pref[i] = max({pref[i - 1], pref_inc[i], pref_dec[i]});
    suff[n - 1] = max(suff_inc[n - 1], suff_dec[n - 1]);
    for(int i = n - 2; i >= 0; i--)
        suff[i] = max({suff[i + 1], suff_inc[i], suff_dec[i]});

    int ans = 0;
    for(int i = 1; i < n - 1; i++)
    {
        if(A[i] < A[i - 1] || A[i] < A[i + 1]) continue;

        bool can = false;
        int L = pref_inc[i];
        int R = suff_inc[i];

        if(L - (L % 2) - 1 >= R - 1) can = true;
        if(R - (R % 2) - 1 >= L - 1) can = true;
        if(i - L + 1 >= 0 && pref[i - L + 1] - 1 >= max(L, R) - 1) can = true;
        if(i + R - 1 < n && suff[i + R - 1] - 1 >= max(L, R) - 1) can = true;

        ans += !can;
    }

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
