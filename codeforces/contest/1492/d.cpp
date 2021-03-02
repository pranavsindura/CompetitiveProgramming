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
    int a, b, k;
    cin >> a >> b >> k;
    bool can = false;
    string A, B;

    if(b >= 2)
    {
        if(k <= a + b - 2)
        {
            can = true;
            A = B = string(b, '1') + string(a, '0');
            int T = k;
            int mov = min(T, a);
            int p = b - 1;
            swap(B[p + mov], B[p]);
            T -= mov;
            p--;

            while(T > 0)
            {
                swap(B[p], B[p + 1]);
                p--;
                T--;
            }
        }
    }
    else
    {
        if(k == 0)
            A = B = "1" + string(a, '0'), can = true;
    }

    if(a == 0 && k > 0) can = false;

    cout << (can ? "Yes\n" : "No\n");
    if(can) cout << A << endl << B << endl;
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
