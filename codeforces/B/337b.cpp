#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    FASTIO;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll l = a * c / gcd(a, c);
    ll p = b * (l / a);
    ll q = d * (l / c);
    if(p < q)
    {
        l = b * d / gcd(b, d);
        a *= (l / b);
        c *= (l / d);
        b = l, d = l;
    }
    else
      b=p,d=q,a=l,c=l;
    ll a1 = a * b;
    ll a2 = c * d;
    a2 = a1-a2;
    ll g = gcd(a1, a2);
    a1 /= g, a2 /= g;
    cout << a2 << "/" << a1;
    return 0;
}