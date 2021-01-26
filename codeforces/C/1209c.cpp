#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    string s;
    cin >> n >> s;

    for(char d = '0'; d <= '9'; d++)
    {
        string ans(n, '-');
        bool ok = true;
        for(int i = 0; i < n; i++)
            if(s[i] < d)
                ans[i] = '1';
            else if(s[i] > d)
                ans[i] = '2';
        char other = '0';
        for(int i = 0; i < n; i++)
            if(s[i] == d)
            {
                if(other > d)
                    ans[i] = '1';
            }
            else
                other = max(other, s[i]);
        other = '9';
        for(int i = n - 1; i >= 0; i--)
            if(s[i] == d)
            {
                if(other < d)
                    ans[i] = '2';
            }
            else
                other = min(other, s[i]);
        for(char &x : ans)
            if(x == '-')
                x = '1';
        string a, b;
        for(int i = 0; i < n; i++)
            if(ans[i] == '1')
                a += s[i];
            else
                b += s[i];
        a += b;
        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1])
                ok = false;
        if(ok)
        {
            cout << ans << endl;
            return;
        }
    }
    cout << "-\n";
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

