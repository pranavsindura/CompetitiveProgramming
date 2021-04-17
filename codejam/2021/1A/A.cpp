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

bool gre(string &A, string &B)
{
    // Append zeros
    reverse(all(A));
    while(sz(A) < sz(B)) A += '0';
    reverse(all(A));

    reverse(all(B));
    while(sz(B) < sz(A)) B += '0';
    reverse(all(B));

    bool res = A > B;

    reverse(all(A));
    while(sz(A) > 1 && A.back() == '0') A.pop_back();
    reverse(all(A));
    reverse(all(B));
    while(sz(B) > 1 && B.back() == '0') B.pop_back();
    reverse(all(B));

    return res;
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    vector<string> make(n);
    make[0] = to_string(arr[0]);
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        make[i] = to_string(arr[i]);
        if(gre(make[i], make[i - 1])) continue;
        string best;
        int did = 0;
        for(int j = 0; j <= n; j++)
        {
            int lo = 0, hi = 1e9;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                string me = to_string(arr[i]) + string(j, '0') + to_string(mid);
                if(gre(me, make[i - 1]))
                {
                    hi = mid - 1;
                    if(best.empty() || gre(best, me))
                        best = me, did = j + ln(to_string(mid));
                }
                else
                    lo = mid + 1;
            }
            string me = to_string(arr[i]) + string(j, '0');
            if(gre(me, make[i - 1])) break;
        }
        assert(!best.empty());
        make[i] = best;
        ans += did;
    }
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
