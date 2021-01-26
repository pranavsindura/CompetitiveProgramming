#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr(4);
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    vector<int>::iterator max = max_element(arr.begin(), arr.end());
    for(int i=0;i<4;i++)
    {
        if(arr[i] == *max)
            continue;
        else
        {
            cout<<abs(arr[i]-*max)<<" ";
        }
    }
    return 0;
}