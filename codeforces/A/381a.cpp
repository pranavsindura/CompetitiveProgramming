#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int l = 0, r = n - 1, turn = 0;
    vector<int> sum(2);
    while(l <= r)
    {
        if(arr[l] > arr[r]) sum[turn] += arr[l++];
        else sum[turn] += arr[r--];
        turn ^= 1;
    }
    cout << sum[0] << " " << sum[1] << endl;
}