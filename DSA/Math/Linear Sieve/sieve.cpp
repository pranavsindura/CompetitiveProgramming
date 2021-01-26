// Linear Sieve - Regular
bool is_prime[MAXN];
vector<int> prime;
void sieve()
{
    clr(is_prime, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i]) prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}

// Smallest Prime Factor
int lp[MAXN];
vector<int> prime;
void sieve()
{
    lp[0] = lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i]) lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

// Euler's Totient Function
int phi[MAXN];
bool is_prime[MAXN];
vector<int> prime;
void sieve()
{
    clr(is_prime, true);
    is_prime[0] = is_prime[1] = false;
    phi[0] = 0, phi[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i]) phi[i] = i - 1, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) phi[i * prime[j]] = prime[j] * phi[i];
            else phi[i * prime[j]] = phi[prime[j]] * phi[i];
            if(i % prime[j] == 0) break;
        }
    }
}

// Mobius Function, not checked
bool is_prime[MAXN];
vector<int> prime;
int mob[MAXN];
void sieve()
{
    clr(is_prime, true);
    is_prime[0] = is_prime[1] = false;
    mob[0] = 0, mob[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i])prime.push_back(i), mob[i] = -1;
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) mob[i * prime[j]] = 0;
            else mob[i * prime[j]] = mob[i] * mob[prime[j]];
            if(i % prime[j] == 0) break;
        }
    }
}