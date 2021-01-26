#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n], *max, marr[n], gcd;
    long long int summarr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max = max_element(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        marr[i] = *max - arr[i];
        summarr += marr[i];
    }

    gcd = marr[0];
    for (int i = 1; i < n; i++)
        gcd = __gcd(gcd, marr[i]);
    cout << summarr / gcd << " " << gcd;
}