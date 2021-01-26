#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 60; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        int bits = (int)log2(n);
        long long int res = pow(2, bits) - 1;
        res %= 60;
        // cout << res << endl;
        cout << fib[res] << endl;
    }
    return 0;
}