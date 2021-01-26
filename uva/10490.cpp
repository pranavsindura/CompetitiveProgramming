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
const int MAXN = 100005;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}

vector<ll> div(ll x)
{
    vector<ll> res;
    for(ll i = 1; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            res.pb(i);
            if(i != x / i)
                res.pb(x / i);
        }
    }
    return res;
}

void cp()
{
    int n;
    cin >> n;
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while(n)
    {
        ll u = fpow(2, n - 1);
        ll v = fpow(2, n) - 1;
        vector<ll> x = div(u);
        vector<ll> y = div(v);
        set<ll> s;
        for(ll a : x)
            for(ll b : y)
                s.insert(a * b);
        ll sum = 0;
        s.erase(u*v);
        for(ll a : s)
            sum += a;
        if(sum == u*v)
        {
            cout << "Perfect: " << u*v<< "!\n";
        }
        else
        {
            if(binary_search(all(prime), n))
            {
                cout<<"Given number is prime. But, NO perfect number is available.\n";
            }
            else
            {
                cout<<"Given number is NOT prime! NO perfect number is available.\n";
            }
        }
        cin >> n;
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