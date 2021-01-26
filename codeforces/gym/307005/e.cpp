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

char arr[105][105];

void cp()
{
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = char('a' + (i + j) % 4);

    bool dn = false, dm = false;
    bool ok = true;
    if((n * m) % 2 == 1) ok = false;
    if(2 * a + 2 * b + 4 * c < n * m) ok = false;
    if(n & 1)
    {
        if(2 * a < m) ok = false;
        for(int j = 0; j < m; j += 2)
            arr[n - 1][j] = arr[n - 1][j + 1], a--;
        n--;
        dn = 1;
    }
    if(m & 1)
    {
        if(2 * b < n) ok = false;
        for(int i = 0; i < n; i += 2)
            arr[i][m - 1] = arr[i + 1][m - 1], b--;
        m--;
        dm = 1;
    }
    for(int i = 0; i < n; i += 2)
        for(int j = 0; j < m; j += 2)
        {
            if(c > 0)
                arr[i][j] = arr[i + 1][j] = arr[i][j + 1] = arr[i + 1][j + 1], c--;
            else if(a > 1)
                arr[i][j] = arr[i][j + 1], arr[i + 1][j] = arr[i + 1][j + 1], a -= 2;
            else if(b > 1)
                arr[i][j] = arr[i + 1][j], arr[i][j + 1] = arr[i + 1][j + 1], b -= 2;
            else
                ok = false;
        }
    n += dn, m += dm;
    if(ok)
    {
        for(int i = 0; i < n; i++, cout << endl)
            for(int j = 0; j < m; j++)
                cout << arr[i][j];
    }
    else
        cout << "IMPOSSIBLE\n";
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

