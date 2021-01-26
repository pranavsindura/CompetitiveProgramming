#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
bool is_prime[1000005];
vector<ll> prime;
ll phi[1000005];
vector <pair<ll, ll>> factors;
void pf(ll num)
{
    int expo = 0;
    for (int i = 0; prime[i] <= sqrt(num); i++)
    {
        expo = 0;
        int pr = prime[i];
        while (num % pr == 0)
        {
            expo++;
            num = num / pr;
        }
        if (expo > 0)
            factors.push_back(make_pair(pr, expo));
    }

    if ( num >= 2)
        factors.push_back(make_pair(num, 1));

}

vector <ll> divisors;
void setdiv(int n, int i)
{
    ll j, x, k;
    for (j = i; j < factors.size(); j++)
    {
        x = factors[j].first * n;
        for (k = 0; k < factors[j].second; k++)
        {
            divisors.push_back(x);
            setdiv(x, j + 1);
            x *= factors[j].first;
        }
    }
}
void init(int n)
{

    memset(is_prime, true, sizeof(is_prime));
    phi[0] = 0;
    phi[1] = 1;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[prime[j]] * phi[i];
            }
        }
    }
}
ll solve(ll n)
{
	ll ans = 0;
    for(ll i = 1; i <= n; i++)
    {
        factors.clear();
        divisors.clear();
        pf(i);
        setdiv(1, 0);
        ll a = 0;
        for(ll x : divisors)
        {
            a += (x % mod * x % mod * phi[x] % mod) % mod;
            a %= mod;
        }
        a += 1;
        a %= mod;
        ans = (ans%mod + a%mod)%mod;
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    init(n);
    cout<<solve(n);
    return 0;
}
