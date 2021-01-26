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
    int k;
    cin >> k;
    int gk = k;
    while(__builtin_popcount(gk) > 1) gk &= (gk - 1);
    gk <<= 1;
    int mx = (1 << 18) - 1;
    vector<vector<int>> arr(3, vector<int>(3, mx));
    arr[1][0] = gk;
    arr[0][1] = k;
    arr[2][2] = k;
    arr[1][2] = 0;
    cout << 3 << " " << 3 << endl;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cout << arr[i][j] << " \n"[j == 2];
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

