// Precomputed inverses - faster
// Factorial
ll fact[MAXN], inv[MAXN], invfact[MAXN];
void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < MAXN; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i < MAXN; i++)
        invfact[i] = (invfact[i - 1] * inv[i]) % mod;
}
// NCR + modular inverse
ll ncr(int n, int r)
{
    if(n < r) return 0;
    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * invfact[n - r] % mod) % mod;
    ans = (ans % mod * invfact[r] % mod) % mod;
    return ans;
}


// With Fermat's Little Theorem - slower
ll ncr(int n, int r)
{
    if(n < r) return 0;
    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * inv(fact[n - r]) % mod) % mod;
    ans = (ans % mod * inv(fact[r]) % mod) % mod;
    return ans;
}