#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n, x;
        cin>>n;
        int arr[n];
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        cout<<(sum+n-1)/n<<endl;
    }
    return 0;
}