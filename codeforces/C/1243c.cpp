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
    ll n, m;
    cin >> n;
    m = n;
    map<ll, int> cnt;
    while(n % 2 == 0)
        cnt[2]++, n /= 2;
    for(ll i = 3; i <= sqrt(n); i += 2)
        while(n % i == 0)
            cnt[i]++, n /= i;
    if(n > 1)
        cnt[n]++;

    if(sz(cnt) > 1 || m == 1)
        cout << 1 << endl;
    else
        cout << cnt.begin()->ff << endl;
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