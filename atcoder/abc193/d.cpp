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

vector<ll> P;

ll score(string &s)
{
    vector<int> freq(10);
    for(char x : s) freq[x - '0']++;
    int ans = 0;
    for(int i = 1; i <= 9; i++)
        ans += i * P[freq[i]];
    return ans;
}

void cp()
{
    int k;
    string s, t;
    cin >> k >> s >> t;

    P.assign(10, 1);
    for(int i = 1; i <= 9; i++) P[i] = P[i - 1] * 10;

    vector<int> freq(10);
    for(char x : s) freq[x - '0']++;
    for(char x : t) freq[x - '0']++;
    for(int &x : freq) x = k - x;

    double ans = 0;

    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(freq[i] <= 0) continue;
            if(freq[j] <= 0) continue;
            if(i == j && freq[i] <= 1) continue;
            double me = 1;
            me *= double(freq[i]) / double(9 * k - 8);
            freq[i]--;
            me *= double(freq[j]) / double(9 * k - 9);
            freq[i]++;

            string A = s, B = t;
            s.back() = char(48 + i), t.back() = char(48 + j);
            if(score(s) > score(t))
                ans += me;
        }
    }

    fix(20);
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
