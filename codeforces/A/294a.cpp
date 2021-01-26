#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int n,x,y,m;
    cin>>n;
    int arr[n+2];
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    cin>>m;
    while(m--)
    {
        cin>>x>>y;
        arr[x-1] += y-1;
        arr[x+1] += arr[x] - y;
        arr[x] = 0;
    }
    for(int i=1; i<=n; i++)
        cout<<arr[i]<<endl;
    return 0;
}