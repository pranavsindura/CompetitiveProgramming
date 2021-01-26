#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int m = INT_MIN;
    m = max(arr[0], l - arr[n - 1])*2;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] > m)
            m = arr[i + 1] - arr[i];
    }
    
    double res = m/2.0;
    cout.precision(20);
    cout<<fixed<< res;
}