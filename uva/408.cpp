#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}
int main()
{
    int step, mod;
    while(scanf("%d %d",&step, &mod) == 2)
    {
        if(gcd(step,mod) == 1)
            printf("%10d%10d    Good Choice\n\n",step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n",step,mod);
    }
    return 0;
}