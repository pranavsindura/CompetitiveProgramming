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

string rep(string &s)
{
    for(int i = 1; i <= ln(s); i++)
    {
        if(ln(s) % i) continue;
        string t, rep;
        for(int j = 0; j < i; j++) t += s[j];
        for(int j = 0; j < ln(s) / i; j++)
            rep += t;
        if(rep == s)
            return t;
    }
    return s;
}

void cp()
{
    string a, b;
    cin >> a >> b;
    string repa = rep(a);
    string repb = rep(b);
    if(repa == repb)
    {
        int A = ln(a) / ln(repa);
        int B = ln(b) / ln(repb);
        int LCM = A * B / __gcd(A, B);
        string ans;
        while(LCM--)
            ans += repa;
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
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

