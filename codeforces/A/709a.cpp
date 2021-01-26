#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int n, b, d, c = 0, sum = 0;
    cin >> n >> b >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > b)
            arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > d)
        {
            sum = 0;
            c++;
        }
    }
    cout << c;
    return 0;
}