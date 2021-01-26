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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    string s;
    cin >> s;

    ll cnt = 0, p = 1, right = 0;
    int n = ln(s);
    ll ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        // atleast 1 goes from left
        ll left = (i * 1LL * (i + 1) / 2) % mod;
        left = (left * p) % mod;
        left = (left * (s[i] - '0')) % mod;
        ans = (ans + left) % mod;
        // atleast 1 goes from right
        ans = (ans + (s[i] - '0') * right) % mod;
        cnt++;
        right = (right + (cnt * p) % mod) % mod;
        p = (p * 10) % mod;
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