#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {0, 1, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2,
                 3, 0, 9, 2};

    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;
        int bits = (int)log2(n);
        cout << arr[bits] << endl;
    }
    return 0;
}