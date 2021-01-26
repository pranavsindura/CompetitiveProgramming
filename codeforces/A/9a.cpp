#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int num = 6 - max(a, b) + 1;
    int gcd = __gcd(num, 6);
    num /= gcd;
    int denom = 6 / gcd;
    cout << num << "/" << denom;
    return 0;
}