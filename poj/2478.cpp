#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long int phi[1000005];
bool is_prime[1000005];
vector<int> prime;

void init()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    is_prime[0] = false;
    phi[1] = 1;
    phi[0] = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= 1000000; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 3; i <= 1000000; i++)
    {
        phi[i] += phi[i - 1];
    }
}

int main()
{
    init();
    int n;
    cin >> n;
    while (n)
    {
        cout<<phi[n]<<endl;
        cin >> n;
    }
    return 0;
}