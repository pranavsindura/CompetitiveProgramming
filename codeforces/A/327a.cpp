#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count0 = 0, count1 = 0, countmax0=-1;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x == 1)
        {
            count1++;
            if(count0)
                count0--;
        }
        if(x == 0)
        {
            count0++;
            if(count0>countmax0)
                countmax0=count0;
        }
    }
    cout<<count1+countmax0;
}