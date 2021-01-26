#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void cp()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> d >> c;
    ll w = a + b, x = b + c, y = c + d, z = a + d;

    auto valid = [&](int a)
    {
        return (a >= 1 && a <= n);
    };

    ll cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        // middle is common
        // p+a+b = q+b+c = r+c+d = s+a+d
        // q = p + a - c
        // r = q + b - d => p + a - c + b - d
        // s = p + b - d
        if(valid(i + a - c) && valid(i + a - c + b - d) && valid(i + b - d))
            cnt++;
    }
    cnt = cnt * 1LL * n;
    cout << cnt;
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