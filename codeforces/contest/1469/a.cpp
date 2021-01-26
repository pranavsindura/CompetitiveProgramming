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
    bool flip = false, ok = false;
    for(char x : s)
    {
        if(x == ')') flip = true;
        if(x == '(' || x == ')') break;
    }
    vector<int> cnt(3);
    int t = 0;
    for(char x : s)
    {
        if(x == '(' || x == ')') t++;
        else cnt[t]++;
    }

    if(flip)
    {
        ok |= cnt[0] > 0 && cnt[2] > 0 && (cnt[0] - 1) % 2 == 0 && (cnt[1] + cnt[2] - 1) % 2 == 0;
        ok |= cnt[0] > 0 && cnt[2] > 0 && (cnt[1]) % 2 == 0 && (cnt[0] + cnt[2] - 2) % 2 == 0;
        ok |= cnt[0] > 0 && cnt[2] > 0 && (cnt[2] - 1) % 2 == 0 && (cnt[1] + cnt[0] - 1) % 2 == 0;
    }
    else
    {
        ok |= cnt[0] % 2 == 0 && (cnt[1] + cnt[2]) % 2 == 0;
        ok |= cnt[1] % 2 == 0 && (cnt[0] + cnt[2]) % 2 == 0;
        ok |= cnt[2] % 2 == 0 && (cnt[0] + cnt[1]) % 2 == 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
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

