// With Modulo
const int MAXN = 30;
const ll mod = 1e9 + 7;
ll C[MAXN][MAXN];
void init()
{
    clr(C, 0);
    for(int i = 0; i < MAXN; i++)
        C[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}


// Without Modulo
const int MAXN = 30;
ll C[MAXN][MAXN];
void init()
{
    clr(C, 0);
    for(int i = 0; i < MAXN; i++)
        C[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}