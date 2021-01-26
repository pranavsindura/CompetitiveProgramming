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

pair<bool, ll> is_expression(string);

pair<bool, ll> is_factor(string s)
{
    if(s.empty()) return {0, 0};
    if(sz(s) > 1 && s.front() == '(' && s.back() == ')')
    {
        s.pop_back();
        reverse(all(s));
        s.pop_back();
        reverse(all(s));
        return is_expression(s);
    }
    int num = 0;
    for(char x : s)
        if(!isdigit(x)) return {0, 0};
        else num = num * 10 + (x - '0');
    return {1, num};
}

pair<bool, ll> is_component(string s)
{
    if(s.empty()) return {0, 0};
    pair<bool, ll> res = is_factor(s);
    if(res.ff) return res;

    string L, R = s;
    for(int i = 0; i < ln(s); i++)
    {
        reverse(all(R));
        R.pop_back();
        reverse(all(R));
        if(s[i] == '*')
        {
            pair<bool, ll> A = is_factor(L);
            pair<bool, ll> B = is_component(R);
            if(A.ff && B.ff) return {1, A.ss * B.ss};
        }
        L += s[i];
    }
    return {0, 0};
}

pair<bool, ll> is_expression(string s)
{
    if(s.empty()) return {0, 0};
    pair<bool, ll> res = is_component(s);
    if(res.ff) return res;

    string L, R = s;
    for(int i = 0; i < ln(s); i++)
    {
        reverse(all(R));
        R.pop_back();
        reverse(all(R));
        if(s[i] == '+')
        {
            pair<bool, ll> A = is_component(L);
            pair<bool, ll> B = is_expression(R);
            if(A.ff && B.ff) return {1, A.ss + B.ss};
        }
        L += s[i];
    }
    return {0, 0};
}

void cp()
{
    string s;
    cin >> s;
    pair<bool, ll> res = is_expression(s);
    if(res.ff) cout << res.ss << endl;
    else cout << "ERROR" << endl;
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

