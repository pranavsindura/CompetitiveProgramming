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
    vector<array<int, 3>> game(n);
    for(int i = 0; i < n; i++)
    {
        int W = (n - 1) / 2 - game[i][0];
        int j = i + 1;
        for(; j < n && W-- > 0; j++)
            cout << 1 << " ", game[j][1]++, game[i][0]++;

        int D = (n - 1) % 2 ? 1 - game[i][2] : 0;
        for(; j < n && D-- > 0; j++)
            cout << 0 << " ", game[j][2]++, game[i][2]++;

        int L = (n - 1) / 2 - game[i][1];
        for(; j < n && L-- > 0; j++)
            cout << -1 << " ", game[j][0]++, game[i][1]++;
    }
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
