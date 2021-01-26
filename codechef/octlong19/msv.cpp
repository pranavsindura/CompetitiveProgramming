#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<set<int>> v(1000005);
// vector<int> f(1000005);
vector<int> primes;
bool is_prime[1000005];
void sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= 1000000; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= 1000000; j++)
        {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
        }
    }
}

vector<pair<int, int>> factors;
void findfactors(int num)
{
    int e;
    for (int i = 0; primes[i] <= sqrt(num); i++)
    {
        e = 0;
        int prime = primes[i];
        while (num % prime == 0)
        {
            e++;
            num = num / prime;
        }
        if (e > 0)
            factors.push_back({prime, e});
    }

    if (num >= 2)
        factors.push_back({num, 1});
}

vector<int> divisors;
void setdiv(int n, int i)
{
    for (int j = i; j < factors.size(); j++)
    {
        int x = factors[j].first * n;
        for (int k = 0; k < factors[j].second; k++)
        {
            divisors.push_back(x);
            setdiv(x, j + 1);
            x *= factors[j].first;
        }
    }
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while (t--)
    {
        v.clear();
        // f.clear();
        int n;
        scanf("%d",&n);
        int arr[n], max=INT_MIN, f[1000000];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&arr[i]);
            v[arr[i]].insert(i);
        }
        fill(f,f+1000000, 0);
        for (int i = 0; i < n; i++)
        {
            v[arr[i]].erase(i);
            if(f[arr[i]] > max)
                max = f[arr[i]];
            findfactors(arr[i]);
            setdiv(1, 0);
            divisors.push_back(1);
            for (int j = 0; j < divisors.size(); j++)
            {
                if (v[divisors[j]].size())
                {
                    f[divisors[j]]++;
                }
            }
            divisors.clear();
            factors.clear();
        }
        printf("%d\n",max);
    }
    return 0;
}