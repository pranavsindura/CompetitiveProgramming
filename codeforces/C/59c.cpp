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
    int k;
    string s;
    cin >> k >> s;
    int n = ln(s);
    bool ok = true;
    vector<int> ques;
    vector<bool> nothave(k, true);
    for(int i = 0; i < n / 2; i++)
        if(s[i] == '?' && s[n - i - 1] == '?') ques.push_back(i);
        else if(s[i] == '?' && s[n - i - 1] != '?') s[i] = s[n - i - 1], nothave[s[i] - 'a'] = 0;
        else if(s[i] != '?' && s[n - i - 1] == '?') s[n - i - 1] = s[i], nothave[s[i] - 'a'] = 0;
        else if(s[i] != s[n - i - 1]) ok = false;
        else nothave[s[i] - 'a'] = 0;
    if((n & 1))
    {
        if(s[n / 2] != '?')
            nothave[s[n / 2] - 'a'] = 0;
        else
            ques.push_back(n / 2);
    }
    string need;
    for(int i = 0; i < k; i++) if(nothave[i]) need += char(97 + i);
    if(ln(need) > sz(ques)) ok = false;

    for(int i = sz(ques) - 1; i >= 0; i--)
        if(need.empty()) s[ques[i]] = 'a', s[n - ques[i] - 1] = 'a';
        else s[ques[i]] = need.back(), s[n - ques[i] - 1] = need.back(), need.pop_back();

    if(ok)
        cout << s << endl;
    else
        cout << "IMPOSSIBLE" << endl;
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

