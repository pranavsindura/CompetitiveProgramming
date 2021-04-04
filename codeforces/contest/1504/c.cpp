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
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(2);
    for(char x : s) cnt[x - '0']++;
    if(s.front() == s.back() && s.front() == '1' && cnt[1] % 2 == 0 && cnt[0] % 2 == 0)
    {
        string A, B;
        A += '(', B += '(';
        vector<int> last(2);
        for(int i = 1; i < n - 1; i++)
        {
            if(s[i] == '0')
            {
                last[0] ^= 1;
                if(last[0] == 0)
                    A += '(', B += ')';
                else
                    A += ')', B += '(';
            }
            else
            {
                last[1] ^= 1;
                if(last[1] == 0)
                    A += ')', B += ')';
                else
                    A += '(', B += '(';
            }
        }
        A += ')', B += ')';
        cout << "YES\n";
        cout << A << endl;
        cout << B << endl;
    }
    else
        cout << "NO\n";
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
