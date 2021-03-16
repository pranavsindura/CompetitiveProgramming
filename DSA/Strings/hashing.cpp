array<ll, MAXN> P;
const ll HMOD = 1e9 + 9;
void init_hash()
{
    P[0] = 1;
    for(int i = 1; i < MAXN; i++)
        P[i] = (P[i - 1] * 31) % HMOD;
}