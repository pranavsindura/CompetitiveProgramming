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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

void cp()
{
    ll n, m;
    while(cin >> n >> m)
    {
        map<ll, int> factor;
        ll temp_m = m;
        while(m % 2 == 0)
            m /= 2, factor[2]++;
        for(ll i = 3; i <= sqrt(m); i += 2)
        {
            while(m % i == 0)
                m /= i, factor[i]++;
        }
        if(m > 1)
            factor[m]++;
        bool ok = true;
        for(auto x : factor)
        {
            ll p = x.ff;
            ll temp = n;
            ll count = 0;
            while(temp)
            {
                temp /= p;
                count += temp;
            }
            if(count < x.ss)
                ok = false;
        }
        if(ok)
            cout << temp_m << " divides " << n << "!\n";
        else
            cout << temp_m << " does not divide " << n << "!\n";
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