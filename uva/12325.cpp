#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    ll n, s1, v1, s2, v2;
    cin >> n >> s1 >> v1 >> s2 >> v2;
    ll lcm = s1 * s2 / __gcd(s1, s2);
    ll ans = 0;
    if(n >= 2 * lcm)
    {
        ll mul_lcm = n / lcm;
        mul_lcm--;
        ans = max((lcm / s1) * v1, (lcm / s2) * v2);
        ans *= mul_lcm;
        n -= mul_lcm * lcm;
    }

    if(s1 < s2)
        swap(s1, s2), swap(v1, v2);

    ll extra = 0;

    for(ll i = 0; i <= n / s1; i++)
    {
        ll here = i * v1;
        ll rem = n - i * s1;
        here += (rem / s2) * v2;
        extra = max(extra, here);
    }
    cout << ans + extra << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}