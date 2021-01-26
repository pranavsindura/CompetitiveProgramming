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

#define ll long long int
// using ll = long long int;
// using ld = long double;
// using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e2 + 5;

ll A[MAXN][MAXN], B[MAXN][MAXN];

void cp()
{
    int n;
    cin >> n;
    vector<ll> rowB(n), colA(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j], colA[j] += A[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> B[i][j], rowB[i] += B[i][j];

    ll sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                sum += A[i][k] * B[k][j];
    int q;
    cin >> q;
    while(q--)
    {
        char t;
        int x, y, k;
        cin >> t >> x >> y >> k;
        if(t == 'A')
        {
            sum -= A[x][y] * rowB[y];
            sum += k * rowB[y];
            colA[y] -= A[x][y];
            colA[y] += k;
            A[x][y] = k;
        }
        else
        {
            sum -= B[x][y] * colA[x];
            sum += k * colA[x];
            rowB[x] -= B[x][y];
            rowB[x] += k;
            B[x][y] = k;
        }
        cout << sum << endl;
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

