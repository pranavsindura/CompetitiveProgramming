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
    bool ok = true;
    int o = 0, c = 0, h = 0;
    
    for(int i = 0; i < n; i++)
    {
        o += s[i] == '(', c += s[i] == ')', h += s[i] == '#';
        if(o < c + h) ok = false;
    }

    vector<int> ans(n);
    vector<bool> unmatched(n, true);
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(') st.push(i);
        else if(!st.empty()) unmatched[st.top()] = false, st.pop(), ans[i]++;
        else ok = false;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(') cnt += unmatched[i];
        else if(s[i] == '#') ans[i] += cnt, cnt = 0, c += ans[i];
    }

    ok &= o == c;

    if(ok)
    {
        for(int i = 0; i < n; i++)
            if(s[i] == '#')
                cout << ans[i] << endl;
    }
    else
        cout << -1 << endl;
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

