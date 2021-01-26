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

int idx[1 << 20];
void cp()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    clr(idx, -1);
    for(int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        int mask = 0;
        for(auto &x : t)
            mask |= (1 << (x - 'a'));
        idx[mask] = i;
    }
    for(int mask = (1 << 20) - 1; mask >= 0 ; mask--)
    {
        if(~idx[mask]) continue;
        for(int i = 0; i < 20; i++)
        {
            if((mask >> i) & 1)
                idx[mask] = idx[mask];
            else
            {
                int a = idx[mask ^ (1 << i)];
                int b = idx[mask];
                if(~a) idx[mask] = a;
                if(~b) idx[mask] = b;
            }
        }
    }
    int l = 0;
    while(l < n)
    {
        int r = l;
        int mask = (1 << (s[l] - 'a'));
        int x = idx[mask];
        while(r + 1 < n && ~idx[mask | (1 << (s[r + 1] - 'a'))])
            mask |= (1 << (s[r + 1] - 'a')), r++, x = idx[mask];
        for(int i = l; i <= r; i++)
            cout << x + 1 << " ";
        l = r + 1;
    }
    cout << endl;
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