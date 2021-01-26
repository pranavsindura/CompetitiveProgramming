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
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t;
    for(int i = 0; i < n; i++)
        t += s[i % k];
    string ans;
    if(t >= s) ans = t;
    else
    {
        t = "";
        for(int i = 0; i < k; i++)
            t += s[i];
        int carry = 1;
        for(int i = k - 1; i >= 0; i--)
        {
            int d = t[i] - '0';
            int sum = d + carry;
            carry = sum / 10;
            d = sum % 10;
            t[i] = char(d + 48);
        }
        assert(!carry);
        for(int i = 0; i < n; i++)
            ans += t[i % k];
    }
    cout << ln(ans) << endl;
    cout << ans << endl;
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

