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

ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x % m;
        x = x * x % m;
        y /= 2;
    }
    return res;
}

int main()
{
    FASTIO;
    int t;
    ll m = 2000000011;
    cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        ll n;
        cin >> n;
        //number of spanning trees is n^(n-2)
        cout << "Case #" << tt << ": " << fpow(n, n - 2, m) << endl;
    }
    return 0;
}