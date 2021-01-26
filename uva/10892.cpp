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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    ll n;
    while(cin >> n && n)
    {
        ll count = 1;
        map<int, int> fac;
        ll temp = n;
        while(temp % 2 == 0)
            fac[2]++, temp /= 2;
        for(ll i = 3; i <= sqrt(temp); i += 2)
            while(temp % i == 0)
                fac[i]++, temp /= i;
        if(temp > 1)
            fac[temp]++;
        for(auto x : fac)
            count *= 2 * x.ss + 1;
        count = (count + 1) / 2;
        cout << n << " " << count << endl;
    }
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