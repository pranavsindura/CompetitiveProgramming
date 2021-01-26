vector <pii> factors;
void primeFactors(int num)
{
    int expo = 0;
    for (int i = 0; primes[i] <= sqrt(num); i++)
    {
        expo = 0;
        int prime = primes[i];
        while (num % prime == 0)
        {
            expo++;
            num = num / prime;
        }
        if (expo > 0)
            factors.push_back(make_pair(prime, expo));
    }

    if ( num >= 2)
        factors.push_back(make_pair(num, 1));

}

vector <int> divisors;
void setDivisors(int n, int i)
{
    int j, x, k;
    for (j = i; j < factors.size(); j++)
    {
        x = factors[j].first * n;
        for (k = 0; k < factors[j].second; k++)
        {
            divisors.push_back(x);
            setDivisors(x, j + 1);
            x *= factors[j].first;
        }
    }
}

/*
Usage
primeFactors(x);
setDivisors(1, 0);

divisors.push_back(1); // unsorted

*/