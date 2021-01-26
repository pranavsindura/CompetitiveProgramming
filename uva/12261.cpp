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
    string s;
    cin >> s;
    int n = ln(s);

    int change = 0;
    vector<int> pos;
    for(int i = 0; i < n; i++)
    {
        int d = s[i] - 'A';
        d = min(d, 26 - d);
        if(d > 0) pos.push_back(i);
        change += d;
    }

    auto dist = [&](int x, int y)
    {
        if(y - x + 1 == 1) return 0;
        if(y - x + 1 == 2) return min(abs(pos[x] - pos[y]), n - abs(pos[x] - pos[y]));
        return pos[y] - pos[x];
    };

    int move = 0;
    if(!pos.empty()) // visit in a single go
        move = dist(0, sz(pos) - 1) + min(pos[0], n - pos.back());
    for(int i = 0; i < sz(pos) - 1; i++)
    {
        // [0, i], [i + 1, sz(pos) - 1]
        int a = dist(0, i);
        int b = dist(i + 1, sz(pos) - 1);
        int ma = min(pos[0], n - pos[i]);
        int mb = min(pos[i + 1], n - pos.back());
        int here = min(2 * (ma + a) + mb + b, 2 * (mb + b) + ma + a);
        move = min(move, here);
    }
    cout << move + change << endl;
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

