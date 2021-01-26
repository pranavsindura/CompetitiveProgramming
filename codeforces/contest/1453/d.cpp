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
const ll MAXN = 5e6 + 5;
// silly mistakes :|
void cp()
{
    ll k;
    cin >> k;
    if(k % 2)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    while(true)
    {
        ll step = 0;
        ll p = 2;
        ll sum = 0;
        while(sum + p <= k)
            sum += p, step++, p *= 2;
        if(step == 0) break;
        k -= sum;
        ans.pb(1);
        for(int i = 0; i < step - 1 && sz(ans) <= 2000; i++)
            ans.pb(0);
        if(k == 0) break;
    }

    for(int i = 0; i < k / 2 && sz(ans) <= 2000; i++)
        ans.pb(1);

    if(sz(ans) > 2000)
    {
        cout << -1 << endl;
        return;
    }

    cout << sz(ans) << endl;
    for(int x : ans)
        cout << x << " ";
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

/*


*/