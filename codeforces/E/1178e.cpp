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

void cp()
{
    string s;
    cin >> s;
    int n = ln(s);

    string L, R;
    int l = 0, r = n - 1;
    while(true)
    {
        if(r - l + 1 <= 0) break;
        if(r - l + 1 <= 3)
        {
            L += s[l];
            break;
        }
        // given 4 chars, at least 2 will be same
        bool done = false;
        for(int i = 0; i < 2 && !done; i++)
            for(int j = 0; j < 2 && !done; j++)
                if(s[l + i] == s[r - j])
                {
                    L += s[l + i], R += s[r - j];
                    done = true;
                }
        l += 2, r -= 2;
    }
    reverse(all(R));
    cout << L + R << endl;
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
