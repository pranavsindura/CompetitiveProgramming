#include <bits/stdc++.h>
#define N 1000005
using namespace std;
// f(p^k) = k, multiplicative function
// f(ip) = f(i/p^cnt[i])*f(p*p^cnt[i]) if p divides i
// cnt[i] stores the power of the minimum prime factor of i
int func[N], cnt[N];
bool is_prime[N];
vector<int> prime;

void solve(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    is_prime[0] = false;
    func[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            func[i] = 1;
            cnt[i] = 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
            {
                func[i * prime[j]] = (func[i] / cnt[i]) * (cnt[i] + 1);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            }
            else
            {
                func[i * prime[j]] = func[i] * func[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    solve(n);
    for(int i=1;i<=n;i++)
    {
        cout<<func[i]<<" ";
    }
}