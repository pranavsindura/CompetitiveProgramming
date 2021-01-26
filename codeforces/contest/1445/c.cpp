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

/*
	if p < q, then x = p
	as x is the largest number that divides p, and since p < q => x < q, x will not be divisble by q

	if p >= q, then we can factorise q
	q = p1^k1 * p2^k2 * ... * pm^km
	Since p is the largest number that divides p, we can try to manipulate p to not be divisble by q
	for each prime factor in q, if the power of that prime factor in p is < power of that prime factor in q
	Then p will not be divisible by q
	Try this for each prime factor in q
	Take out powers until its count in p becomes less that count in q
	then maximise it with the answer
*/

void cp()
{
    ll p, q;
    cin >> p >> q;
    if(p < q)
    {
        cout << p << endl;
        return;
    }

    // Factorize q
    map<ll, int> pf;
    ll temp = q;
    while(temp % 2 == 0)
        temp /= 2, pf[2]++;
    for(ll i = 3; i <= sqrt(temp); i += 2)
        while(temp % i == 0)
            temp /= i, pf[i]++;
    if(temp > 1)
        pf[temp]++;


    ll ans = 0;
    for(auto x : pf)
    {
        ll fac = x.ff;

        int cnt = 0;
        temp = p;
        while(temp % fac == 0)
            temp /= fac, cnt++;

        temp = p;
        while(cnt >= x.ss)
            temp /= fac, cnt--;
        
        ans = max(ans, temp);
    }

    cout << ans << endl;
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