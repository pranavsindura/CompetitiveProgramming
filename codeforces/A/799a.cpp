#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int ct = 0;
    while (ct <= d)
    {
        ct += t;
        n -= k;
    }
    if (n > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}