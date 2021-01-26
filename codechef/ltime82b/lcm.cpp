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
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
bool is_composite[10005];
vector<int> prime;
void init(int n)
{
    memset(is_composite, false, sizeof(is_composite));
    for (int i = 2; i < n; i++)
    {
        if (!is_composite[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] < n; j++)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

vector<int> pf(ll x)
{
    vector<int> a;
    if(x % 2 == 0)
    {
        while(x % 2 == 0)
            x /= 2;
        a.pb(2);
    }
    for(ll i = 3; i * i <= x; i += 2)
    {
        if(x % i == 0)
        {
            while(x % i == 0)
                x /= i;
            a.pb(i);
        }
    }
    if(x)
        a.pb(x);
    return a;
}

int main()
{
    FASTIO;
    init(10005);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        for(ll &x : arr)
            cin >> x;
        set<int> f;
        for(ll x : arr)
        {
            vector<int> v = pf(x);
            for(int xx : v)
                f.insert(xx);
        }
        ll ans = 1;
        vector<ll> mul;
        for(int i=0;i<sz(prime) && prime[i] <= m;i++)
        {
        	if(!f.count(prime[i])){
        		mul.pb(1LL*prime[i]);
        	}
        }
        for(int i=sz(mul)-1;i>=0;i--)
        {
        	if(ans*mul[i] <= m)
        		ans *= mul[i];
        }
        cout << ans << endl;
    }
    return 0;
}