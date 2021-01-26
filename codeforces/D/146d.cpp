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

void no()
{
    cout << -1 << endl;
    exit(0);
}

void cp()
{
    int a4, a7, a47, a74;
    cin >> a4 >> a7 >> a47 >> a74;
    if(abs(a47 - a74) > 1) no();
    string ans;
    if(a47 > a74)
    {
        // 474747...
        if(a47 <= a4 && a47 <= a7)
        {
            for(int i = 0; i < a47; i++)
                ans += "47", a4--, a7--;
        }
        else no();
        // Fill last with 7
        for(int i = 0; i < a7; i++) ans += '7';
        reverse(all(ans));
        // Fill front with 4
        for(int i = 0; i < a4; i++) ans += '4';
        reverse(all(ans));
    }
    else if(a47 < a74)
    {
        // 747474...
        if(a74 <= a4 && a74 <= a7)
        {
            for(int i = 0; i < a74; i++)
                ans += "74", a4--, a7--;
        }
        else no();
        ans.pop_back();
        // Fill last with 7
        for(int i = 0; i < a7; i++) ans += '7';
        ans += '4';
        reverse(all(ans));
        ans.pop_back();
        // Fill front with 4
        for(int i = 0; i < a4; i++) ans += '4';
        ans += '7';
        reverse(all(ans));
    }
    else
    {
        // 47474...
        if(a47 + 1 <= a4 && a47 <= a7)
        {
            for(int i = 0; i < a47; i++)
                ans += "47", a4--, a7--;
            ans += '4';
            a4--;
            ans.pop_back();
            // Fill last with 7
            for(int i = 0; i < a7; i++) ans += '7';
            ans += '4';
            // Fill front with 4
            reverse(all(ans));
            for(int i = 0; i < a4; i++) ans += '4';
            reverse(all(ans));
        }
        // 74747...
        else if(a74 + 1 <= a7 && a74 <= a4)
        {
            for(int i = 0; i < a74; i++)
                ans += "74", a4--, a7--;
            ans += '7';
            a7--;
            // Fill last with 7
            for(int i = 0; i < a7; i++) ans += '7';
            reverse(all(ans));
            ans.pop_back();
            // Fill front with 4
            for(int i = 0; i < a4; i++) ans += '4';
            ans += '7';
            reverse(all(ans));
        }
        else no();
    }
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

