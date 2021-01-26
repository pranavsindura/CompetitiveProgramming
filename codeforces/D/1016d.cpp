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

/*

3 x 4
a1  a2  a3  a4
a5  a6  a7  a8
a9 a10 a11 a12

A1
A2
A3

B1 B2 B3 B4

Obviously, A1^A2^A3^B1^B2^B3^B4 must be 0
We need to construct, not recover

A1 = A2^A3^B1^B2^B3^B4
B1 = A1^A2^A3^B2^B3^B4

A1^B2^B3^B4 B2 B3 B4
A2           0  0  0
A3           0  0  0
*/

void cp()
{
    int n, m, v = 0;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int &x : A)
        cin >> x, v ^= x;
    for(int &x : B)
        cin >> x, v ^= x;
    if(v != 0)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> arr(n, vector<int>(m));
    arr[0][0] = A[0];
    for(int i = 1; i < m; i++)
        arr[0][0] ^= B[i], arr[0][i] = B[i];
    for(int i = 1; i < n; i++)
        arr[i][0] = A[i];
    cout << "YES\n";
    for(int i = 0; i < n; i++, cout << endl)
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
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

