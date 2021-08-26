/*
	Primality Tests

	Wheel Factorisation O(sqrt(N))
		Try all numbers upto sqrt(N)

	Fermat Primality Test

		a^(p - 1) === 1 mod p
		when p is prime

		So, pick random a and check for all of them is the above statement true?

		Do this 5 - 10 times for better accuracy
*/

// Fermat Primality Test
// SPOJ POP2
ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1) res = ((__uint128_t)res * x % m) % m;
        x = ((__uint128_t)x * x % m) % m;
        y >>= 1;
    }
    return res;
}
bool is_prime_fermat(ll p, int iters = 10)
{
    if(p < 4) return p == 2 || p == 3;
    if(p % 2 == 0) return false;
    for(int i = 0; i < iters; i++)
    {
        ll a = rand(2LL, p - 2);
        if(fpow(a, p - 1, p) != 1) return false;
    }
    return true;
}