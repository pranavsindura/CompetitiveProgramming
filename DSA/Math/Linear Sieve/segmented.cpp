#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032

unsigned base[MAX / 64], segment[RNG / 64], primes[LEN];

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

// http://zobayer.blogspot.com/2009/09/segmented-sieve.html
void sieve()
{
    unsigned i, j, k;
    for (i = 3; i < LMT; i += 2)
        if (!chkC(base, i))
            for (j = i * i, k = i << 1; j < MAX; j += k)
                setC(base, j);
    primes[0] = 2;
    for (i = 3, j = 1; i < MAX; i += 2)
        if (!chkC(base, i))
            primes[j++] = i;
}