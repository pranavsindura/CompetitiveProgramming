// Without Modulo
ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}
// With Modulo, 1e9+7 Modulo
const ll mod = 1e9 + 7;
ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}

// With Custom Modulo
ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % m * x % m) % m;
        x = (x % m * x % m) % m;
        y >>= 1;
    }
    return res;
}

// Modular Multiplicative Inverse, Mod is prime
// Fermat's Little Theorem
ll finv(ll a)
{
    return fpow(a, mod - 2);
}

// How to get the inversion of just one number?
// We can memo this as the numbers are <= x if x <= 10^6 and have the inversions of all numbers
ll get_inv(ll x)
{
	if (x <= 1) return 1;
	return (mod - mod / x) * get_inv(mod % x) % mod;
}

// Multiply for large numbers under modulo
ll mul(ll x, ll y)
{
    ll res = 0;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod + x % mod) % mod;
        x = (x % mod + x % mod) % mod;
        y >>= 1;
    }
    return res;
}
// Custom Modulo
ll mul(ll x, ll y, ll m)
{
    ll res = 0;
    while(y > 0)
    {
        if(y & 1)
            res = (res % m + x % m) % m;
        x = (x % m + x % m) % m;
        y >>= 1;
    }
    return res;
}