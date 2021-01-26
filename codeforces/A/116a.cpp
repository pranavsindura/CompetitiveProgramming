#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n], arr[n], sum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        arr[i] = b[i] - a[i];
        if (i == 0)
            sum[0] = arr[0];
        else
            sum[i] = sum[i - 1] + arr[i];
    }
    int *ans = max_element(sum, sum + n);
    cout << *ans;
}