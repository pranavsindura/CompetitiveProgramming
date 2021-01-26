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

int dig(ll n)
{
    int sum = 0;
    while(n)
        sum += n % 10, n /= 10;
    return sum;
}

/*
	x^2 + x * s(x) - n = 0

	D = s(x)^2 + 4 * n

	x = (-s(x) + sqrt(D))/2

	For all s(x) solve for x,
	Then check if digit sum of x is actually equal to s(x)
*/

void cp()
{
    ll n;
    cin >> n;
    ll ans = LLONG_MAX;
    bool found = false;
    for(int i = 1; i <= 90; i++)
    {
        ll D = i * i + 4 * n;

        if((ll)sqrt(D) * (ll)sqrt(D) != D)
            continue;

        ll xtimes2 = -i + (ll)sqrt(D);

        if(xtimes2 < 0 || xtimes2 % 2 != 0)
            continue;

        ll x = xtimes2 / 2;
        
        if(dig(x) == i)
            ans = min(ans, x), found = true;
    }
    if(found)
        cout << ans;
    else
        cout << -1;
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