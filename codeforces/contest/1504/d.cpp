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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

void cp()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> black, white;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if((i + j) & 1) black.push_back(i * n + j);
            else white.push_back(i * n + j);

    reverse(all(white));
    reverse(all(black));

    while(cnt < n * n)
    {
        cnt++;
        int a;
        cin >> a, a--;
        vector<int> can(3, 1);
        can[a] = 0;
        if(can[0])
        {
            if(!white.empty())
            {
                int x = white.back() / n, y = white.back() % n;
                white.pop_back();
                cout << 1 << " " << x + 1 << " " << y + 1 << endl;
                cout.flush();
                continue;
            }
        }

        if(can[1])
        {
            if(!black.empty())
            {
                int x = black.back() / n, y = black.back() % n;
                black.pop_back();
                cout << 2 << " " << x + 1 << " " << y + 1 << endl;
                cout.flush();
                continue;
            }
        }

        if(can[2])
        {
            if(!black.empty())
            {
                int x = black.back() / n, y = black.back() % n;
                black.pop_back();
                cout << 3 << " " << x + 1 << " " << y + 1 << endl;
                cout.flush();
                continue;
            }
            else if(!white.empty())
            {
                int x = white.back() / n, y = white.back() % n;
                white.pop_back();
                cout << 3 << " " << x + 1 << " " << y + 1 << endl;
                cout.flush();
                continue;
            }
            else
                assert(false);
        }
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
