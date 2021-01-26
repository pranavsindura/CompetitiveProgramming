#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
// int lp[10000001];
int pr[1000001];
// vector<int> pr;
int k;
bool is_prime[10000001];

int get_rem(char s[], int mod)
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        n = ((n * 10)%mod + s[i] - 48) % mod;
    }
    return n;
}
void sieve(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            // pr.push_back(i);
            pr[k] = i;
            k++;
        }
        for (int j = 0; j < k; j++)
        {
            long long int mul = i * pr[j];
            if (mul <= n)
            {
                is_prime[i * pr[j]] = false;
                if (i % pr[j] == 0)
                    break;
            }
            else
                break;
        }
    }
}
int main()
{
    sieve(1000005);
    // string s;
    char s[110];
    int l;
    // cin >> s >> l;
    scanf("%s%d", s, &l);
    while (s != "0" && l != 0)
    {
        int flag = 0, at = 0;
        for (int i = 0; i < k && pr[i] < l; i++)
        {
            if (get_rem(s, pr[i]) == 0)
            {
                flag = 1;
                at = pr[i];
                break;
            }
        }
        if (flag)
        {
            printf("BAD %d\n", at);
        }
        else
        {
            printf("GOOD\n");
        }
        scanf("%s%d", s, &l);
    }

    return 0;
}