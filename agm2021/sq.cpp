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
    ll n, x, y;
    cin >> n >> x >> y;
    ll p = -1;
    while(n > 1)
    {
        if(x >= 1 && x <= n / 2 && y >= 1 && y <= n / 2)
        {
            p = n / 2;
            break;
        }
        else if(x > n / 2 && x <= n && y >= 1 && y <= n / 2)
        {
            x -= n / 2;
            n = n / 2;
        }
        else if(x >= 1 && x <= n / 2 && y > n / 2 && y <= n)
        {
            y -= n / 2;
            n = n / 2;
        }
        else
        {
            p = -1;
            break;
        }
    }

    cout << p << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

/*
1x1
0

2x2
10
00

4x4

  1234
1 2210
2 2200
3 1000
4 0000

8x8
12345678
44442210
44442200
44441000
44440000
22100000
22000000
10000000
00000000

4x4 N=4

N=4  0


*/