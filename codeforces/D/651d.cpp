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
    int n, a, b, T;
    string s;
    cin >> n >> a >> b >> T >> s;
    // w/o swipe time
    vector<int> pref(n);
    for(int i = 0; i < n; i++)
        pref[i] = (s[i] == 'w' ? b : 0) + 1;
    partial_sum(all(pref), pref.begin());

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        // go to i-th pos
        int me = pref[i] + i * a;
        if(me > T) break;

        ans = max(ans, i + 1);

        // go back to 0
        me += i * a;

        int best = n;
        int lo = i + 1, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int more = pref[n - 1] - (mid ? pref[mid - 1] : 0) + (n - mid) * a;
            if(me + more > T)
                lo = mid + 1;
            else
                best = mid, hi = mid - 1;
        }

        ans = max(ans, i + 1 + n - best);
    }

    if(pref[0] <= T) // can visit the first pos
    {
        ans = max(ans, 1);
        for(int i = n - 1; i > 0; i--)
        {
            // go to i-th pos in reverse
            int me = pref[n - 1] - pref[i - 1] + pref[0] + (n - i) * a;
            if(me > T) break;

            ans = max(ans, n - i + 1);

            // go back to 0
            me += (n - i) * a;

            int best = 0;
            int lo = 1, hi = i - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                int more = pref[mid] - pref[0] + mid * a;
                if(me + more > T)
                    hi = mid - 1;
                else
                    best = mid, lo = mid + 1;
            }

            ans = max(ans, n - i + 1 + best);
        }
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

