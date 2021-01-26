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

int sg(int x)
{
    if(x > 0) return 1;
    else if(x < 0) return -1;
    else return 0;
}

void cp()
{
    int a, b;
    string s;
    cin >> a >> b >> s;
    int dx = 0, dy = 0;
    for(char x : s)
        if(x == 'L')      dx--;
        else if(x == 'R') dx++;
        else if(x == 'D') dy--;
        else if(x == 'U') dy++;

    int x = 0, y = 0;
    bool ok = (a == x && b == y);
    for(char d : s)
    {
        if(d == 'L')      x--;
        else if(d == 'R') x++;
        else if(d == 'D') y--;
        else if(d == 'U') y++;

        if(dx == 0 && dy == 0)
            ok |= (a == x && b == y);
        else if(dx == 0)
            ok |= (a == x && abs(b - y) % abs(dy) == 0 && (!sg(b - y) || sg(b - y) == sg(dy)));
        else if(dy == 0)
            ok |= (b == y && abs(a - x) % abs(dx) == 0 && (!sg(a - x) || sg(a - x) == sg(dx)));
        else
            ok |= (
                      abs(b - y) % abs(dy) == 0 && (!sg(b - y) || sg(b - y) == sg(dy)) &&
                      abs(a - x) % abs(dx) == 0 && (!sg(a - x) || sg(a - x) == sg(dx)) &&
                      abs(a - x) / abs(dx) == abs(b - y) / abs(dy)
                  );
    }
    cout << (ok ? "Yes\n" : "No\n");
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

