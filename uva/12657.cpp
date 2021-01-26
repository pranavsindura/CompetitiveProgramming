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
    int n, q, tc = 1;
    while(cin >> n >> q)
    {
        vector<int> left(n + 5), right(n + 5);
        for(int i = 1; i <= n; i++)
            left[i] = i - 1, right[i] = i + 1;
        right[0] = 1, left[n + 1] = n;

        bool rev = false;

        while(q--)
        {
            int x, y, t;
            cin >> t;
            if(t < 4) cin >> x >> y;

            if(t == 1 && rev) t = 2;
            else if(t == 2 && rev) t = 1;

            if(t == 1 && left[y] != x)
            {
                // move x to the left of y
                int L = left[x], R = right[x];
                right[L] = R;
                left[R] = L;

                L = left[y];
                right[L] = x;
                left[y] = x;

                right[x] = y;
                left[x] = L;
            }
            else if(t == 2 && right[y] != x)
            {
                // move x to the right of y
                int L = left[x], R = right[x];
                right[L] = R;
                left[R] = L;

                R = right[y];
                left[R] = x;
                right[y] = x;

                right[x] = R;
                left[x] = y;
            }
            else if(t == 3)
            {
                int Lx = left[x], Rx = right[x], Ly = left[y], Ry = right[y];
                if(x != Ly)
                {
                    right[Ly] = x;
                    left[x] = Ly;
                    right[y] = Rx;
                    left[Rx] = y;
                }
                else
                {
                    right[y] = x;
                    left[x] = y;
                }

                if(x != Ry)
                {
                    right[Lx] = y;
                    left[y] = Lx;
                    right[x] = Ry;
                    left[Ry] = x;
                }
                else
                {
                    right[x] = y;
                    left[y] = x;
                }
            }
            else if(t == 4)
                rev ^= 1;
        }

        vector<int> res(n + 1);
        for(int i = 1; i <= n; i++)
            if(left[i] == 0) res[1] = i;
        for(int i = 2; i <= n; i++)
            res[i] = right[res[i - 1]];

        ll ans = 0;
        for(int i = 1; i <= n; i++)
            if(i & 1)
                ans += res[i];

        if(rev && n % 2 == 0) ans = n * 1LL * (n + 1) / 2 - ans;

        cout << "Case " << tc++ << ": " << ans << endl;
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

